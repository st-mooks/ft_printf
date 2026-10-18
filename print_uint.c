/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:50:19 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/17 15:45:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*build_str_uint(char *arg, t_format format_props)
{
	size_t	len;
	char	*str;
	char	*precision_str;
	char	*pad_str;

	len = max(3, ft_strlen(arg), format_props.precision, format_props.width);
	precision_str = get_precision_str(arg, format_props.precision);
	pad_str = get_pad_str(precision_str, len, format_props.pad_0);
	if (format_props.just_l)
		str = ft_strjoin(precision_str, pad_str);
	else
		str = ft_strjoin(pad_str, precision_str);
	free(precision_str);
	free(pad_str);
	return (str);
}

void	print_uint(char *f_str, unsigned int arg, int *char_count)
{
	t_format	format_props;
	char		*str;
	char		*arg_str;

	arg_str = ft_uintptr_toa(arg);
	if (!arg_str)
		return ;
	fill_format_props(&format_props, f_str);
	str = build_str_uint(arg_str, format_props);
	free(arg_str);
	print_update_free(str, char_count);
}
