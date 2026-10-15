/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:39:27 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 16:34:31 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		char_count;
	va_list	args;
	char	*f_str;

	char_count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			f_str = get_f_str(&str, &char_count);
			check_and_print(f_str, &args, &char_count);
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
