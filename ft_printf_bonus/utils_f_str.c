/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_f_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:08:48 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 10:58:37 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_f_str_len(char *str)
{
	int		len;
	char	*valid_specifiers;
	char	*valid_flags;

	valid_specifiers = "cspdiuxX";
	valid_flags = "-0# +.";
	len = 0;
	while (ft_strchr(valid_flags, *str)
		|| ft_isdigit(*str))
	{
		str++;
		len++;
	}
	if (ft_strchr(valid_specifiers, *str))
		len++;
	return (len);
}

char	*get_f_str(const char **str, int *char_count)
{
	char	*f_str;
	int		percent_count;
	int		f_str_len;

	percent_count = 0;
	f_str = NULL;
	while (**str == '%')
	{
		percent_count++;
		(*str)++;
	}
	if (percent_count % 2 != 0)
	{
		f_str_len = get_f_str_len(*(char **)str);
		if (f_str_len)
		{
			percent_count--;
			f_str = ft_substr(*str, 0, f_str_len);
			(*str) += f_str_len;
		}
	}
	print_percent(percent_count, char_count);
	return (f_str);
}

int	validate_format_str(char *f_str)
{
	char	*width;
	char	*ptr;
	char	*check_str;
	int		is_valid;

	is_valid = 1;
	width = ft_itoa((int)get_width(f_str));
	ptr = ft_strnstr(f_str, width, ft_strlen(f_str));
	if (ptr && *width != '0')
	{
		check_str = ft_strchr(f_str, '+');
		if (check_str && check_str > ptr)
			is_valid = 0;
		check_str = ft_strchr(f_str, '-');
		if (check_str && check_str > ptr)
			is_valid = 0;
		check_str = ft_strchr(f_str, ' ');
		if (check_str && check_str > ptr)
			is_valid = 0;
		check_str = ft_strchr(f_str, '#');
		if (check_str && check_str > ptr)
			is_valid = 0;
	}
	free(width);
	return (is_valid);
}
