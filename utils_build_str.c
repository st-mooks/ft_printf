/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_build_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 16:02:08 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 16:03:19 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*build_str_char(char arg, t_format format_props)
{
	char	*str;
	char	arg_str[2];
	char	*pad_str;
	size_t	len;

	arg_str[0] = arg;
	arg_str[1] = '\0';
	len = max(2, ft_strlen(arg_str), format_props.width);
	pad_str = get_pad_str(arg_str, len, format_props.pad_0);
	if (format_props.just_l)
		str = ft_strjoin(arg_str, pad_str);
	else
		str = ft_strjoin(pad_str, arg_str);
	free(pad_str);
	return (str);
}

char	*build_str_hex(uintptr_t arg, t_format format_props, char *f_str)
{
	size_t	len;
	char	*precision_str;
	char	*pad_str;
	char	*str;
	char	*hex_str;

	hex_str = get_hex_str(arg);
	precision_str = get_precision_str(hex_str, format_props.precision);
	len = max(3, ft_strlen(hex_str), format_props.precision,
			format_props.width);
	pad_str = get_pad_str(precision_str, len, format_props.pad_0);
	if (arg)
		add_0x(&precision_str, &pad_str, f_str, format_props);
	if (format_props.just_l)
		str = ft_strjoin(precision_str, pad_str);
	else
		str = ft_strjoin(pad_str, precision_str);
	free(hex_str);
	free(precision_str);
	free(pad_str);
	return (str);
}

char	*build_str_int(char *arg, t_format format_props)
{
	size_t	len;
	char	*str;
	char	*precision_str;
	char	*pad_str;

	len = max(3, ft_strlen(arg), format_props.precision, format_props.width);
	precision_str = get_precision_str(arg, format_props.precision);
	pad_str = get_pad_str(precision_str, len, format_props.pad_0);
    precision_str = add_sign_space(precision_str, format_props);
	pad_str = advance_str(pad_str, format_props);
	if (format_props.just_l)
		str = ft_strjoin(precision_str, pad_str);
	else
		str = ft_strjoin(pad_str, precision_str);
	free(precision_str);
	free(pad_str);
	return (str);
}

char	*build_str_str(char *f_str, char *arg, t_format format_props)
{
	size_t	len;
	size_t	arg_len;
	char	*str;
	char	*trim_str;
	char	*pad_str;

	arg_len = ft_strlen(arg);
	trim_str = get_trim_str(f_str, arg, arg_len, format_props.precision);
	len = max(2, ft_strlen(trim_str), format_props.width);
	pad_str = get_pad_str(trim_str, len, format_props.pad_0);
	if (format_props.just_l)
		str = ft_strjoin(trim_str, pad_str);
	else
		str = ft_strjoin(pad_str, trim_str);
	free(trim_str);
	free(pad_str);
	return (str);
}

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
