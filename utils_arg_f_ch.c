/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_f_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:28:08 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 15:32:51 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_f_ch(const char **str)
{
	char	f_ch;
	char	*valid_chars;

	valid_chars = "cspdiuxX%";
	*str += 1;
	f_ch = **str;
	*str += 1;
	if (!ft_strchr(valid_chars, f_ch))
		return (0);
	return (f_ch);
}

char	*get_arg(const char **str, char f_ch, va_list *args)
{
	char	*arg;

	arg = NULL;
	if (f_ch == 'c')
		arg = char_to_str((char)va_arg(*args, int));
	if (f_ch == 's')
		arg = str_to_str(va_arg(*args, char *));
	if (f_ch == 'p')
		arg = ptr_to_str(va_arg(*args, void *));
	if (f_ch == 'd' || f_ch == 'i')
		arg = int_to_str(va_arg(*args, int));
	if (f_ch == 'u')
		arg = uint_to_str(va_arg(*args, unsigned int));
	if (f_ch == 'x' || f_ch == 'X')
		arg = hex_to_str(f_ch, va_arg(*args, unsigned int));
	if (f_ch == '%')
		arg = percent_to_str(str);
	return (arg);
}
