/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:09:11 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 10:29:50 by mbadarin         ###   ########.fr       */
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

ssize_t	print_null_char(char *str)
{
	ssize_t	check_c;
	ssize_t	check_s;

	check_c = write(1, "\0", 1);
	check_s = write(1, str, ft_strlen(str));
	if (check_s < (ssize_t)ft_strlen(str) || check_c != 1)
		return (-1);
	return (check_c + check_s);
}

void	print_update_free(char *str, int *char_count, int is_null_char)
{
	ssize_t	check_s;
	ssize_t	check_c;
	
	check_c = 0;
	if (is_null_char)
	{
		check_s = print_null_char(str);
		check_c = 1;
	}
	else
		check_s = write(1, str, ft_strlen(str));
	if (check_s + check_c < (ssize_t)ft_strlen(str))
		*char_count = -1;
	else
		*char_count += (int)check_s;
	free(str);
}

void	print_arg(char f_ch, va_list *args, int *char_count)
{
	if (f_ch == 'c')
		print_char((char)va_arg(*args, int), char_count);
	if (f_ch == 's')
		print_str(va_arg(*args, char *), char_count);
	if (f_ch == 'p')
		print_ptr(f_ch, va_arg(*args, void *), char_count);
	if (f_ch == 'd' || f_ch == 'i')
		print_int(va_arg(*args, int), char_count);
	if (f_ch == 'u')
		print_uint(va_arg(*args, unsigned int), char_count);
	if (f_ch == 'x' || f_ch == 'X')
		print_hex(f_ch, va_arg(*args, unsigned int), char_count);
}
