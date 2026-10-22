/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_build_printable_str.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:42:58 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 15:43:04 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_arg(const char **str, char **printable_str,
			va_list *args, int *char_count)
{
	char	f_ch;
	char	*arg;

	f_ch = get_f_ch(str);
	arg = get_arg(str, f_ch, args);
	if (arg)
	{
		if (f_ch == 'c' && !*arg)
		{
			*printable_str = add_char(*printable_str, *arg, *char_count);
			*char_count += 1;
		}
		else
			*char_count += ft_strlen(arg);
	}
	*printable_str = add_str(*printable_str, arg, *char_count);
	free(arg);
}

void	add_literal(const char **str, char **printable_str, int *char_count)
{
	*printable_str = add_char(*printable_str, **str, *char_count);
	*char_count += 1;
	*str += 1;
}
