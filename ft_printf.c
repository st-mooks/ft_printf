/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:39:27 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/19 16:16:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		char_count;
	va_list	args;
	char	*f_str;

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
