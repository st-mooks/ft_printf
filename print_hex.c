/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:29 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 13:07:30 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(char *f_str, uintptr_t arg, int *char_count)
{
	t_format			format_props;
	char				*str;

	fill_format_props(&format_props, f_str);
	str = build_str_hex(arg, format_props, f_str);
	if (ft_strchr(f_str, 'X'))
		capitalise(str);
	print_update_free(str, char_count);
}
