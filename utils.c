/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:56:52 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 13:30:54 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *fill_digits(long long l, int size)
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

int	get_digits_count(long long l, int base_len)
{
	int	count;

	count = 0;
	if (l == 0)
		count++;
	if (l < 0)
		l *= -1;
	while (l > 0)
	{
		count++;
		l /= base_len;
	}
	return (count);
}

char	*ft_ltoa(long long l)
{
	char	*str;
	int		size;

	if (l == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	size = get_digits_count(l, 10);
	str = fill_digits(l, size);
	return (str);
}

size_t	get_precision(char *f_str)
{
	char	*precision_str;
	int		precision;

	precision_str = ft_strchr(f_str, '.');
	if (precision_str++)
		precision = ft_atoi(precision_str);
	else
		precision = 0;
	return (precision);
}

size_t	get_width(char *f_str)
{
	size_t	width;

    while (*f_str
			&& !ft_isdigit(*f_str)
			&& *f_str != '.')
        f_str++;
	width = ft_atoi(f_str);
	return (width);
}

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

char	*get_precision_str(char *arg, size_t precision)
{
	char	*str;
	size_t	arg_len;
	size_t	i;
	size_t	size;

	arg_len = ft_strlen(arg);
	size = max(2, arg_len, precision) + 1;
	str = malloc(size);
	i = 0;
	while (precision > arg_len + i)
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
	if (pad_0)
		pad_char = '0';
	i = 0;
	while (size > i)
		str[i++] = pad_char;
	str[i] = '\0';
	return (str);
}

int validate_format_str(char *f_str)
{
    char    *width;
    char    *ptr;
    char    *check_str;

    width = ft_itoa((int)get_width(f_str));
    ptr = ft_strnstr(f_str, width, ft_strlen(f_str));
    if (ptr && *width != '0')
    {
        if (((check_str = ft_strchr(f_str, '+')) && check_str > ptr)
        || ((check_str =  ft_strchr(f_str, '-')) && check_str > ptr)
        || ((check_str =  ft_strchr(f_str, ' ')) && check_str > ptr)
        || ((check_str =  ft_strchr(f_str, '#')) && check_str > ptr))
        {
            free(width);
            return (0);
        }        
    }
    free(width);
    return (1);
}
