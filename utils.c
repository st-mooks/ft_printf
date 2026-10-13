/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:56:52 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/13 13:49:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

    while (!ft_isdigit(*f_str) && *f_str != '.')
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
    if (ptr)
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