/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:08:58 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 13:08:59 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	max(int arg_count, ...)
{
	va_list	args;
	size_t	a;
	size_t	b;

	va_start(args, arg_count);
	a = va_arg(args, size_t);
	arg_count--;
	while (arg_count-- > 0)
	{
		b = va_arg(args, size_t);
		if (b > a)
			a = b;
	}
	return (a);
}

char	*fill_digits(uintptr_t l, int size)
{
	int		i;
	char	*base;
	char	*str;

	str = malloc(size + 1);
	if (!str)
		return (NULL);
	base = "0123456789";
	i = 0;
	while (i < size)
	{
		str[size - i - 1] = base[l % 10];
		l /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	get_digits_count(uintptr_t l, int base_len)
{
	int	count;

	count = 0;
	if (l == 0)
		count++;
	while (l != 0)
	{
		count++;
		l /= base_len;
	}
	return (count);
}

char	*ft_uintptr_toa(uintptr_t l)
{
	char	*str;
	int		size;

	size = get_digits_count(l, 10);
	str = fill_digits(l, size);
	return (str);
}
