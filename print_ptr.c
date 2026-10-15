/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:02:59 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 10:49:46 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(char *f_str, va_list *args, int *char_count)
{
	char		*f_str_to_hex;

	f_str_to_hex = ft_strjoin("#", f_str);
	print_hex(f_str_to_hex, args, char_count);
	free(f_str_to_hex);
}
