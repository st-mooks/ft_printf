/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:52 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/19 15:45:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(void *arg, int *char_count, t_format f_props)
{
	if (!arg)
	{
		print_str("(nil)", char_count, f_props);
		return ;
	}
	print_hex((uintptr_t)arg, char_count, f_props);
}
