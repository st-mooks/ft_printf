/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:23:13 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 12:45:40 by mbadarin         ###   ########.fr       */
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
	str[len] = '\0';
	return (str);
}

void	print_uint(char *f_str, va_list *args, int *char_count)
{
	t_format	format_props;
	char		*str;
	char		*arg;

	arg = ft_ltoa((long long)va_arg(*args, unsigned int));
	format_props.precision = get_precision(f_str);
	format_props.width = get_width(f_str);
	format_props.just_l = (ft_strchr(f_str, '-') != NULL);
	format_props.pad_0 = (ft_strchr(f_str, '0')
			&& !format_props.just_l
			&& !format_props.precision);
	str = build_str_uint(arg, format_props);
	ft_putstr_fd(str, 1);
	char_count += ft_strlen(str);
	free(str);
}
