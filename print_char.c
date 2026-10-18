/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:33:11 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/17 15:46:10 by marvin           ###   ########.fr       */
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

void	print_char(char *f_str, char arg, int *char_count)
{
	char		*str;
	t_format	format_props;

	fill_format_props(&format_props, f_str);
	str = build_str_char(arg, format_props);
	if (!arg)
	{
			*char_count += 1;
			if (format_props.just_l)
			{
					ft_putchar_fd(0, 1);
					ft_putstr_fd(str, 1);
			}
			else
			{
					ft_putstr_fd(str, 1);
					ft_putchar_fd(0, 1);
			}
			char_count += ft_strlen(str);
			free (str);	
	}
	else
		print_update_free(str, char_count);
}
