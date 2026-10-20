/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 09:43:39 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 09:50:51 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		char_count;
	va_list	args;
	char	f_ch;

	char_count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (char_count < 0)
			return (-1);
		if (*str == '%')
		{
			f_ch = get_f_ch(&str, &char_count);
			print_arg(f_ch, &args, &char_count);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			char_count++;
		}
	}
	va_end(args);
	return (char_count);
}
