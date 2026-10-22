/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:09:18 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 11:06:46 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_precision_str(char *arg, t_format f_props)
{
	char	*str;
	size_t	arg_len;
	size_t	i;
	size_t	size;

	if (*arg == '0' && !f_props.precision && f_props.precision_flag)
		return (ft_strdup(""));
	arg_len = ft_strlen(arg);
	size = max(2, arg_len, f_props.precision) + 1;
	str = malloc(size);
	if (!str)
		return (NULL);
	i = 0;
	while (f_props.precision > arg_len + i)
		str[i++] = '0';
	str[i] = '\0';
	ft_strlcat(str, arg, size);
	return (str);
}

char	*get_pad_str(char *precision_str, size_t len, int pad_0)
{
	char	pad_char;
	char	*str;
	size_t	size;
	size_t	i;

	pad_char = ' ';
	size = len - ft_strlen(precision_str);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	if (pad_0)
		pad_char = '0';
	i = 0;
	while (size > i)
		str[i++] = pad_char;
	str[i] = '\0';
	return (str);
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

char	*reset_str(char *str, char *new)
{
	char	*ptr;

	ptr = str;
	str = new;
	free(ptr);
	return (str);
}

void	capitalise(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}
