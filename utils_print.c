/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:08:43 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 08:44:58 by marvin           ###   ########.fr       */
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
	void	*arg;

	arg = get_arg(f_str, args);
	if (ft_strchr(f_str, 'c'))
		print_char(f_str, *(int *)arg, char_count);
	if (ft_strchr(f_str, 's'))
		print_str(f_str, (char *)arg, char_count);
	if (ft_strchr(f_str, 'p'))
		print_ptr(f_str, arg, char_count);
	if (ft_strchr(f_str, 'd') || ft_strchr(f_str, 'i'))
		print_int(f_str, *(int *)arg, char_count);
	if (ft_strchr(f_str, 'u'))
		print_uint(f_str, *(unsigned int *)arg, char_count);
	if (ft_strchr(f_str, 'x') || ft_strchr(f_str, 'X'))
		print_hex(f_str, *(unsigned int *)arg, char_count);
	if (!ft_strchr(f_str, 's') && !ft_strchr(f_str, 'p'))
		free(arg);
}