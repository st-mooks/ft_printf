/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_format_props.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:51:41 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 10:49:17 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_precision(char *f_str)
{
	char	*precision_str;
	int		precision;

	precision_str = ft_strchr(f_str, '.');
	if (precision_str++)
		precision = ft_atoi(precision_str);
	else
		precision = 0;
	return (precision);
}

size_t	get_width(char *f_str)
{
	size_t	width;

	while (*f_str
		&& (!ft_isdigit(*f_str) || *f_str == '0')
		&& *f_str != '.')
		f_str++;
	width = ft_atoi(f_str);
	return (width);
}

int	get_pad_0(char *f_str)
{
	char	*zero_ptr;
	char	*check_ptr;
	char	digit;
	int		pad_0;

	pad_0 = 1;
	digit = '1';
	zero_ptr = ft_strchr(f_str, '0');
	if (zero_ptr)
	{
		while (digit <= '9')
		{
			check_ptr = ft_strchr(f_str, digit);
			if (check_ptr && check_ptr < zero_ptr)
			{
				pad_0 = 0;
				break ;
			}
			digit++;
		}
	}
	else
		pad_0 = 0;
	return (pad_0);
}

char	*get_precision_str(char *arg, size_t precision)
{
	char	*str;
	size_t	arg_len;
	size_t	i;
	size_t	size;

	arg_len = ft_strlen(arg);
	size = max(2, arg_len, precision) + 1;
	str = malloc(size);
	i = 0;
	while (precision > arg_len + i)
		str[i++] = '0';
	str[i] = '\0';
	ft_strlcat(str, arg, size);
	return (str);
}

char	*get_pad_str(char *precision_str, size_t len, int pad_0)
{
	char	pad_char;
	char	*str;
	size_t	size;
	size_t	i;

	pad_char = ' ';
	size = len - ft_strlen(precision_str);
	str = malloc(size + 1);
	if (pad_0)
		pad_char = '0';
	i = 0;
	while (size > i)
		str[i++] = pad_char;
	str[i] = '\0';
	return (str);
}
