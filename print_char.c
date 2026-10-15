/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:33:11 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 09:14:13 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char *f_str, va_list *args, int	*char_count)
{
	char		*str;
	char		arg[2];
	char		*pad_str;
	t_format	format_props;
	size_t		len;

	arg[0] = (char)va_arg(*args, int);
	arg[1] = '\0';
	format_props.width = get_width(f_str);
	len = max(2, ft_strlen(arg), format_props.width);
	format_props.just_l = (ft_strchr(f_str, '-') != NULL);
	format_props.pad_0 = 0;
	pad_str = get_pad_str(arg, len, format_props.pad_0);
	if (format_props.just_l)
		str = ft_strjoin(arg, pad_str);
	else
		str = ft_strjoin(pad_str, arg);
	ft_putstr_fd(str, 1);
	*char_count += ft_strlen(str);
	free(pad_str);
	free(str);
}
