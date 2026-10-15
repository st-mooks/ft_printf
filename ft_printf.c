/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:39:27 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 11:27:18 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(char *f_str, va_list *args, int *char_count)
{
	if (ft_strchr(f_str, 'c'))
		print_char(f_str, args, char_count);
	if (ft_strchr(f_str, 's'))
		print_str(f_str, args, char_count);
	if (ft_strchr(f_str, 'p'))
		print_ptr(f_str, args, char_count);
	if (ft_strchr(f_str, 'd') || ft_strchr(f_str, 'i'))
		print_int(f_str, args, char_count);
	if (ft_strchr(f_str, 'u'))
		print_uint(f_str, args, char_count);
	if (ft_strchr(f_str, 'x') || ft_strchr(f_str, 'X'))
		print_hex(f_str, args, char_count);
}

void	check_and_print(char *f_str, va_list *args, int *char_count)
{
	if (f_str)
	{
		print_arg(f_str, args, char_count);
		free(f_str);
	}
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
/*
int	main(void)
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
	hex = 127;
	uint = UINT_MAX;
	str = "This is a string";
	ft_printf("****\n"RED_FG WHITE_BG"printf"RESET":\n");
	printf_return = printf("\"%.5s %-15c %0.6u "
		"%#010.2x %025X %p\"\n", str, c, uint, hex, hex, &hex);
	ft_printf("****\n"RED_FG WHITE_BG"ft_printf"RESET":\n");
	ft_printf_return = ft_printf("\"%.5s %-15c %0.6u "
		"%#010.2x %025X %p\"\n", str, c, uint, hex, hex, &hex);
	ft_printf("****\nprintf return = %u\nft_printf_return = %u\n"
				"", printf_return, ft_printf_return);
}*/
