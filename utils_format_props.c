/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_format_props.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:08:35 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 13:18:09 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_precision(char *f_str)
{
	char	*precision_str;
	int		precision;

	precision_str = ft_strchr(f_str, '.');
	if (precision_str)
		precision = ft_atoi(++precision_str);
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

void    fill_format_props(t_format *format_props, char *f_str)
{
    format_props->precision = get_precision(f_str);
	format_props->width = get_width(f_str);
	format_props->just_l = (ft_strchr(f_str, '-') != NULL);
	format_props->pad_0 = (
            get_pad_0(f_str)
			&& !ft_strchr(f_str, '.')
			&& !format_props->just_l
            && !ft_strchr(f_str, 'c')
            && !ft_strchr(f_str, 's'));
	format_props->sign = (ft_strchr(f_str, '+') != NULL);
	format_props->space = (
            (ft_strchr(f_str, ' ') != NULL)
			&& !format_props->sign);
}
