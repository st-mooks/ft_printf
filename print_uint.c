/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:50:19 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 15:50:23 by mbadarin         ###   ########.fr       */
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

void	print_uint(char *f_str, va_list *args, int *char_count)
{
	t_format	format_props;
	char		*str;
	char		*arg;

	arg = ft_ltoa((long long)va_arg(*args, unsigned int));
	fill_format_props(&format_props, f_str);
	str = build_str_uint(arg, format_props);
	print_update_free(str, char_count);
}
