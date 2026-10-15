/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:33:11 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 11:26:16 by mbadarin         ###   ########.fr       */
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

void	print_char(char *f_str, va_list *args, int	*char_count)
{
	char		*str;
	char		arg;
	t_format	format_props;

	arg = (char)va_arg(*args, int);
	format_props.width = get_width(f_str);
	format_props.just_l = (ft_strchr(f_str, '-') != NULL);
	format_props.pad_0 = 0;
	str = build_str_char(arg, format_props);
	ft_putstr_fd(str, 1);
	*char_count += ft_strlen(str);
	free(str);
}
