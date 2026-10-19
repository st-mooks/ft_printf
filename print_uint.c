/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:08:13 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/19 15:46:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uint(unsigned int arg, int *char_count, t_format f_props)
{
	char		*str;
	char		*arg_str;

	arg_str = ft_uintptr_toa(arg);
	if (!arg_str)
		return ;
	str = build_str_uint(arg_str, &f_props);
	free(arg_str);
	print_update_free(str, char_count, f_props, 0);
}
