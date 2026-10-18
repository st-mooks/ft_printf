/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:18 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 13:07:20 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
