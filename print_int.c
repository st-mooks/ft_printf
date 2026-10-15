/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:36:51 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 10:31:51 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_sign_space(char *str_pre, t_format format_props)
{
	size_t	len;

	len = ft_strlen(str_pre);
	if (format_props.sign)
		return (ft_strjoin("+", str_pre));
	if (format_props.space)
		return (ft_strjoin(" ", str_pre));
	return (ft_strdup(str_pre));
}

int	advance_ptr(char *ptr, t_format format_props)
{
	if (*ptr && (format_props.sign || format_props.space))
		return (1);
	return (0);
}

char	*build_str_int(char *arg, t_format format_props)
{
	size_t	len;
	char	*str;
	char	*precision_str;
	char	*pad_str;
	char	*ptr;

	len = max(3, ft_strlen(arg), format_props.precision, format_props.width);
	precision_str = get_precision_str(arg, format_props.precision);
	pad_str = get_pad_str(precision_str, len, format_props.pad_0);
	ptr = pad_str;
	if (advance_ptr(ptr, format_props))
		ptr++;
	if (format_props.just_l)
		str = ft_strjoin(precision_str, ptr);
	else
		str = ft_strjoin(ptr, precision_str);
	ptr = str;
	str = add_sign_space(ptr, format_props);
	free(precision_str);
	free(pad_str);
	free(ptr);
	return (str);
}

void	print_int(char *f_str, va_list *args, int *char_count)
{
	char		*str;
	char		*arg;
	t_format	format_props;

	arg = ft_itoa(va_arg(*args, int));
	format_props.precision = get_precision(f_str);
	format_props.width = get_width(f_str);
	format_props.just_l = (ft_strchr(f_str, '-') != NULL);
	format_props.pad_0 = (get_pad_0(f_str)
			&& !format_props.precision
			&& !format_props.just_l);
	format_props.sign = (ft_strchr(f_str, '+') != NULL);
	format_props.space = ((ft_strchr(f_str, ' ') != NULL)
			&& !format_props.sign);
	str = build_str_int(arg, format_props);
	*char_count += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(arg);
	free(str);
}
