/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:08:43 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 10:08:47 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(int percent_count, int *char_count)
{
	while (percent_count > 0)
	{
		ft_putchar_fd('%', 1);
		percent_count -= 2;
		*char_count += 1;
	}
}

void	print_update_free(char *str, int *char_count)
{
	ft_putstr_fd(str, 1);
	*char_count += ft_strlen(str);
	free(str);
}

void	print_arg(char *f_str, va_list *args, int *char_count)
{
	if (ft_strchr(f_str, 'c'))
		print_char(f_str, args, char_count);
	if (ft_strchr(f_str, 's'))
		print_str(f_str, args, char_count);
	if (ft_strchr(f_str, 'p'))
		print_ptr(f_str, args, char_count);
	if (ft_strchr(f_str, 'd') || ft_strchr(f_str, 'i'))
		print_int(f_str, args, char_count);
	if (ft_strchr(f_str, 'u'))
		print_uint(f_str, args, char_count);
	if (ft_strchr(f_str, 'x') || ft_strchr(f_str, 'X'))
		print_hex(f_str, args, char_count);
}