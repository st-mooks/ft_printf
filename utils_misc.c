/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_format_props.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:18:32 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 17:18:37 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    fill_format_props(t_format *format_props, char *f_str)
{
    format_props->precision = get_precision(f_str);
	format_props->width = get_width(f_str);
	format_props->just_l = (ft_strchr(f_str, '-') != NULL);
	format_props->pad_0 = (
            get_pad_0(f_str)
			&& !format_props->precision
			&& !format_props->just_l
            && !ft_strchr(f_str, 'c')
            && !ft_strchr(f_str, 's'));
	format_props->sign = (ft_strchr(f_str, '+') != NULL);
	format_props->space = (
            (ft_strchr(f_str, ' ') != NULL)
			&& !format_props->sign);
}
