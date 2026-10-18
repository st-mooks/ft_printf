/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:41 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 13:19:20 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(char *f_str, int arg, int *char_count)
{
	char		*arg_str;
	char		*str;
	t_format	format_props;

	arg_str = ft_itoa(arg);
	if (!arg_str)
		return ;
	fill_format_props(&format_props, f_str);
	str = build_str_int(arg_str, format_props);
	free(arg_str);
	print_update_free(str, char_count);
}
