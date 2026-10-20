/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:52 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 10:58:07 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_ptr(void *arg, int *char_count, t_format f_props)
{
	if (!arg)
	{
		print_str("(nil)", char_count, f_props);
		return ;
	}
	print_hex((uintptr_t)arg, char_count, f_props);
}
