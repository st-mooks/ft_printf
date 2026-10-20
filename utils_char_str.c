/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:09:18 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 13:16:29 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_f_ch(const char **str, int *char_count)
{
	char	f_ch;
	int		percent_count;

	percent_count = 0;
	f_ch = '\0';
	while (**str == '%')
	{
		percent_count++;
		(*str)++;
	}
	if (percent_count % 2 != 0)
	{
		percent_count--;
		f_ch = **str;
		*str += 1;
	}
	print_percent(percent_count, char_count);
	return (f_ch);
}

char	*get_hex_str(uintptr_t n)
{
	int		size;
	int		i;
	char	*hex_str;

	size = get_digits_count(n, 16);
	hex_str = malloc(size + 1);
	if (n == 0)
		hex_str[0] = '0';
	i = size;
	while (i > 0)
	{
		hex_str[i - 1] = "0123456789abcdef"[n % 16];
		n /= 16;
		i--;
	}
	hex_str[size] = '\0';
	return (hex_str);
}

void	capitalise(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}