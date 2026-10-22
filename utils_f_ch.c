/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_f_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:28:08 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 10:52:25 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_f_ch(const char **str, char **printable_str, int *char_count)
{
	char	f_ch;
	int		percent_count;
	char	*valid_chars;

	valid_chars = "cspdiuxX%";
	percent_count = 0;
	f_ch = 0;
	while (**str == '%')
	{
		if (++percent_count % 2 == 0)
			*printable_str = add_char(*printable_str, '%', char_count);
		*str += 1;
	}
	if (percent_count % 2 == 0)
		f_ch = '%';
	else
	{
		f_ch = **str;
		*str += 1;
	}
	if (!ft_strchr(valid_chars, f_ch))
		return (0);
	return (f_ch);
}

char	*get_arg(char f_ch, va_list *args, int *char_count)
{
	char	*str;

	str = NULL;
	if (f_ch == 'c')
		str = char_to_str((char)va_arg(*args, int));
	if (f_ch == 's')
		str = str_to_str(va_arg(*args, char *));
	if (f_ch == 'p')
		str = ptr_to_str(va_arg(*args, void *));
	if (f_ch == 'd' || f_ch == 'i')
		str = int_to_str(va_arg(*args, int));
	if (f_ch == 'u')
		str = uint_to_str(va_arg(*args, unsigned int));
	if (f_ch == 'x' || f_ch == 'X')
		str = hex_to_str(f_ch, va_arg(*args, unsigned int));
	if (f_ch == '%')
		str = ft_strdup("");
	if (str)
	{
		if (!*str && f_ch == 'c')
			*char_count += 1;
		else
			*char_count += ft_strlen(str);
	}
	return (str);
}

void	add_arg(const char **str, char **printable_str,
			va_list *args, int *char_count)
{
	char	f_ch;
	char	*arg;

	f_ch = get_f_ch(str, printable_str, char_count);
	arg = get_arg(f_ch, args, char_count);
	*printable_str = add_str(*printable_str, arg);
}
