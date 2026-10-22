/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:09:18 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 10:51:38 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_str(char *original, char *new)
{
	char	*old;

	old = original;
	original = ft_strjoin(original, new);
	free(old);
	return (original);
}

char	*add_char(char *original, char c, int *char_count)
{
	char	*old;
	char	*new;

	old = original;
	new = malloc(2);
	if (!new)
		return (NULL);
	new[0] = c;
	new[1] = '\0';
	original = ft_strjoin(original, new);
	*char_count += 1;
	free(new);
	free(old);
	return (original);
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
