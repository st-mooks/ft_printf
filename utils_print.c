/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:09:11 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/19 16:47:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_and_print(char *f_str, va_list *args, int *char_count)
{
	if (f_str)
	{
		t_format	f_props;
		fill_f_props(&f_props, f_str);
		print_arg(args, char_count, f_props);
		free(f_str);
	}
}

void	print_percent(int percent_count, int *char_count)
{
	while (percent_count > 0)
	{
		ft_putchar_fd('%', 1);
		percent_count -= 2;
		*char_count += 1;
	}
}

ssize_t	print_null_char(char *str, t_format f_props)
{
	ssize_t	check_c;
	ssize_t	check_s;

	if (f_props.just_l)
	{
		check_c = write(1, "\0", 1);
		check_s = write(1, str, ft_strlen(str));
	}
	else
	{
		check_s = write(1, str, ft_strlen(str));
		check_c = write(1, "\0", 1);
	}
	if (check_s < (ssize_t)ft_strlen(str) || check_c != 1)
		return (-1);
	return (check_c + check_s);
}

void	print_update_free(char *str, int *char_count,
			t_format f_props, int is_null_char)
{
	ssize_t	check_s;
	ssize_t	check_c;
	
	check_c = 0;
	if (is_null_char)
	{
		check_s = print_null_char(str, f_props);
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

void	print_arg(va_list *args, int *char_count, t_format f_props)
{
	void	*arg;

	arg = get_arg(args, f_props);
	if (f_props.f_ch == 'c')
		print_char(*(int *)arg, char_count, f_props);
	if (f_props.f_ch == 's')
		print_str((char *)arg, char_count, f_props);
	if (f_props.f_ch == 'p')
		print_ptr(arg, char_count, f_props);
	if (f_props.f_ch == 'd' || f_props.f_ch == 'i')
		print_int(*(int *)arg, char_count, f_props);
	if (f_props.f_ch == 'u')
		print_uint(*(unsigned int *)arg, char_count, f_props);
	if (f_props.f_ch == 'x' || f_props.f_ch == 'X')
		print_hex(*(unsigned int *)arg, char_count, f_props);
	if (f_props.f_ch != 's' && f_props.f_ch != 'p')
		free(arg);
}
