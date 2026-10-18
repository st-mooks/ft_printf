/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:36:51 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 08:46:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_sign_space(char *str_pre, t_format format_props)
{
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
	char	*ptr2;

	len = max(3, ft_strlen(arg), format_props.precision, format_props.width);
	precision_str = get_precision_str(arg, format_props.precision);
	pad_str = get_pad_str(precision_str, len, format_props.pad_0);
	ptr = pad_str;
	if (advance_ptr(ptr, format_props))
		ptr++;
	str = add_sign_space(precision_str, format_props);
	ptr2 = str;
	if (format_props.just_l)
		str = ft_strjoin(str, ptr);
	else
		str = ft_strjoin(ptr, str);
	free(precision_str);
	free(pad_str);
	free(ptr2);
	return (str);
}
/*
char	*build_str_int(char *arg, t_format f_props)
{
	char	*str;
	char	*precision_str;
	char	*pad_str;
	size_t	len;

	precision_str = get_precision_str(arg);
	len = max(3, ft_strlen(precision_str, f_props.width, f_props.precisoin));
	
}*/

void	print_int(char *f_str, int arg, int *char_count)
{
	char		*arg_str;
	char		*str;
	t_format	format_props;

	arg_str = ft_itoa(arg);
	if (!arg_str)
		return ;
	fill_format_props(&format_props, f_str);
	str = build_str_int(arg_str, format_props);
	free(arg_str);
	print_update_free(str, char_count);
}
