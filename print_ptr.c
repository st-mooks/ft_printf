/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:52 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 13:07:54 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(char *f_str, void *arg, int *char_count)
{
	char		*f_str_to_hex;

	if (!arg)
	{
		print_str(f_str, "(nil)", char_count);
		return ;
	}
	f_str_to_hex = ft_strjoin("#", f_str);
	print_hex(f_str_to_hex, (uintptr_t)arg, char_count);
	free(f_str_to_hex);
}
