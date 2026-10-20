/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:12:21 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 10:12:21 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char arg, int *char_count)
{
	char		*str;

	str = malloc(2);
	if (!str)
	{
		*char_count = -1;
		return ;
	}
	str[0] = arg;
	str[1] = '\0';
	print_update_free(str, char_count, !arg);
}

void	print_hex(char f_ch, uintptr_t arg, int *char_count)
{
	char		*str;

	str = get_hex_str(arg);
	if (!str)
	{
		*char_count = -1;
		return ;
	}
	if (f_ch == 'X')
		capitalise(str);
	print_update_free(str, char_count, 0);
}

void	print_int(int arg, int *char_count)
{
	char		*str;

	str = ft_itoa(arg);
	if (!str)
	{
		*char_count = -1;
		return ;
	}
	print_update_free(str, char_count, 0);
}

void	print_ptr(char f_ch, void *arg, int *char_count)
{
	if (!arg)
	{
		print_str("(nil)", char_count);
		return ;
	}
	if (write(1, "0x", 2) != 2)
	{
		*char_count = -1;
		return ;
	}
	*char_count += 2;
	print_hex(f_ch, (uintptr_t)arg, char_count);
}

void	print_str(char *arg, int *char_count)
{
	if (!arg)
	{
		print_str("(null)", char_count);
		return ;
	}
	print_update_free(ft_strdup(arg), char_count, 0);
}

void	print_uint(unsigned int arg, int *char_count)
{
	char		*str;

	str = ft_uintptr_toa(arg);
	if (!str)
	{
		*char_count = -1;
		return ;
	}
	print_update_free(str, char_count, 0);
}