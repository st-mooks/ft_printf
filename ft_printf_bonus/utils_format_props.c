/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_f_props.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:08:35 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/19 10:52:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

void	update_f_props_len(t_format *f_props, char *precision_str)
{
	f_props->len = max (3,
			f_props->width,
			f_props->precision,
			ft_strlen(precision_str));
}

void    fill_f_props(t_format *f_props, char *f_str)
{
	f_props->f_ch = *(f_str + ft_strlen(f_str) - 1);
    f_props->precision = get_precision(f_str);
	f_props->width = get_width(f_str);
	f_props->precision_flag = (ft_strchr(f_str, '.') != NULL);
	f_props->just_l = (ft_strchr(f_str, '-') != NULL);
	f_props->pad_0 = (
            get_pad_0(f_str)
			&& !f_props->precision_flag
			&& !f_props->just_l
            && f_props->f_ch != 'c'
            && f_props->f_ch != 's');
	f_props->sign = (ft_strchr(f_str, '+') != NULL);
	f_props->space = (
            (ft_strchr(f_str, ' ') != NULL)
			&& !f_props->sign);
	f_props->hex_0x = (
		ft_strchr(f_str, '#') != NULL
		|| f_props->f_ch == 'p');
}
