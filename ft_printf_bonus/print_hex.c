/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:29 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 10:57:56 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_hex(uintptr_t arg, int *char_count, t_format f_props)
{
	char		*str;
	char		*arg_str;

	arg_str = get_hex_str(arg);
	str = build_str_hex(arg_str, &f_props);
	if (f_props.f_ch == 'X')
		capitalise(str);
	free(arg_str);
	print_update_free(str, char_count, f_props, 0);
}
