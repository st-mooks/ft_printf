/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 09:43:39 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 15:12:22 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		char_count;
	va_list	args;
	char	*printable_str;

	if (!str)
		return (-1);
	char_count = 0;
	printable_str = ft_strdup("");
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			add_arg(&str, &printable_str, &args, &char_count);
		else
			add_literal(&str, &printable_str, &char_count);
	}
	va_end(args);
	char_count = (int)write(1, printable_str, char_count);
	free (printable_str);
	return (char_count);
}
