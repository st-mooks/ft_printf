/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:07:18 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 10:57:34 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_char(char arg, int *char_count, t_format f_props)
{
	char		*str;
	char		arg_str[2];

	arg_str[0] = arg;
	arg_str[1] = '\0';
	str = build_str_char(arg_str, &f_props);
	print_update_free(str, char_count, f_props, !arg);
}
