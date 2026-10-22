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

char	*add_str(char *original, char *str, int char_count)
{
	size_t	str_len;
	ssize_t	original_len;
	size_t	new_size;
	char	*new;

	if (!original || !str)
		return (NULL);
	str_len = ft_strlen(str);
	original_len = char_count - str_len;
	new_size = char_count;
	new = malloc(new_size);
	ft_memmove(new, original, original_len);
	ft_memmove(new + original_len, str, str_len);
	free(original);
	return (new);
}

char	*add_char(char *original, char c, int char_count)
{
	size_t	new_size;
	char	*new;

	if (!original)
		return (NULL);
	new_size = char_count + 1;
	new = malloc(new_size);
	ft_memmove(new, original, new_size - 1);
	new[new_size - 1] = c;
	free(original);
	return (new);
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
