/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:08:13 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 13:08:14 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
