/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:39:27 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 10:35:22 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int	get_arg_count(const char *str)
{
	int		count;
	int		percent_count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			percent_count = 0;
			while (*str++ == '%')
				percent_count++;
			if (percent_count % 2 != 0)
				count++;
		}
		else
			str++;
	}
	return (count);
}
*/
char	*to_hex(long long n, int size)
{
	int		i;
	char	*hex;

	i = size;
	hex = malloc(i + 1);
	if (n < 0)
		n *= -1;
	while (i > 0)
	{
		hex[i - 1] = "0123456789abcdef"[n % 16];
		n /= 16;
		i--;
	}
	hex[size] = '\0';
	return (hex);
}

void	print_hex(char s, va_list *args, int *char_count, int size)
{
	long long		n;
	char			*str;
	char			*ptr;

	n = va_arg(*args, long long);
	str = to_hex(n, size);
	ptr = str;
	if (s == 'X')
		while(*ptr)
		{
			*ptr = ft_toupper(*ptr);
			ptr++;
		}
	ptr = str;
	while (*++ptr == '0');
	ft_putstr_fd(ptr, 1);
	*char_count += ft_strlen(ptr);
	free(str);
}

void	print_sub(char *f_str, va_list *args, int *char_count)
{
	if (ft_strchr(f_str, 'c'))
		print_char(f_str, args, char_count);
	if (ft_strchr(f_str, 's'))
		print_str(f_str, args, char_count);
	/*if (ft_strchr(f_str, 'p'))
	{
		ft_putstr_fd("0x", 1);
		*char_count += 2;
	}*/
	/*if (ft_strchr(f_str, 'd') || ft_strchr(f_str, 'i'))
		print_int(f_str, args, char_count);*/
	if (ft_strchr(f_str, 'u'))
		print_uint(f_str, args, char_count);
	/*if (ft_strchr(f_str, 'x')
		|| ft_strchr(f_str, 'X')
		|| ft_strchr(f_str, 'p'))
		print_hex(f_str, args, char_count, 9);*/
}

int     char_in_set(char c, char *set)
{   
    while (*set)
        if (c == *set++)
            return (1);
    return (0);
}

int		get_f_str_len(char *str)
{
	int		len;
	char    *valid_specifiers;
	char	*valid_flags;

	valid_specifiers = "cspdiuxX";
	valid_flags = "-0# +.";
	len = 0;
	while (char_in_set(*str, valid_flags)
		|| ft_isdigit(*str))
	{
		str++;
		len++;
	}
	if (char_in_set(*str, valid_specifiers))
		len++;
	else
		len = 0;
	return (len);
}

void	print_percent(int percent_count, int *char_count)
{
	while (percent_count > 0)
	{
		ft_putchar_fd('%', 1);
		percent_count -= 2;
		*char_count += 1;
	}
}

char	*get_f_str(const char **str, int *char_count)
{
	char	*f_str;
	int		percent_count;
	int		f_str_len;
	int		i;

	percent_count = 0;
	f_str = NULL;
	while (**str == '%')
	{
		percent_count++;
		(*str)++;
	}
	if (percent_count % 2 != 0)
	{
		f_str_len = get_f_str_len(*(char **)str);
		if (f_str_len)
		{
			percent_count--;
			f_str = ft_substr(*str, 0, f_str_len);
			(*str) += f_str_len;
		}
	}
	print_percent(percent_count, char_count);
	return (f_str);
}

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
			if (f_str)
			{
				print_sub(f_str, &args, &char_count); 
				free(f_str);
			}
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

int	main()
{
	char			*str;
	int				ft_printf_return;
	int				printf_return;
	int				hex;
	unsigned int	uint;
	char			c;
	float			f;

	f = (float)1 / 2;
	c = 'M';
	hex = 15;
	uint = UINT_MAX;
	str = "This is a string";
	printf_return = ft_printf("%:%% s:%s u:%u c:%c\n", str, uint, c);
	/*ft_printf_return = ft_printf("%p%%%s%x%x%u%c\n", str, str, hex, hex, uint, c);
	ft_printf("printf return=%d\nft_printf_return=%d\n"
				"", printf_return, ft_printf_return);
	printf("int:%zu long:%zu long long:%zu size_t:%zu uint:%zu uintptr_t:%zu\n", sizeof(int), sizeof(long), sizeof(long long), sizeof(size_t), sizeof(unsigned int), sizeof(uintptr_t));*/
}
