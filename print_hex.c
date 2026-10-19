/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:29 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/19 15:46:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
