/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:41 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 10:58:00 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
