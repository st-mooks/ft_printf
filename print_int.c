/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:41 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/19 15:46:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(int arg, int *char_count, t_format f_props)
{
	char		*arg_str;
	char		*str;
	long long	arg_l;

	arg_l = arg;
	if (arg_l < 0)
		arg_l = -arg_l;
	arg_str = ft_uintptr_toa((uintptr_t)arg_l);
	if (!arg_str)
		return ;
	str = build_str_int(arg, arg_str, &f_props);
	free(arg_str);
	print_update_free(str, char_count, f_props, 0);
}
