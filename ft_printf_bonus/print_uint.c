/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:08:13 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 10:58:19 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
