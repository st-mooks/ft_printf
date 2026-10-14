/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:39:27 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 14:52:36 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sub(char *f_str, va_list *args, int *char_count)
{
	if (ft_strchr(f_str, 'c'))
		print_char(f_str, args, char_count);
	if (ft_strchr(f_str, 's'))
		print_str(f_str, args, char_count);
	if (ft_strchr(f_str, 'p'))
		print_ptr(f_str, args, char_count);
	/*if (ft_strchr(f_str, 'd') || ft_strchr(f_str, 'i'))
		print_int(f_str, args, char_count);*/
	if (ft_strchr(f_str, 'u'))
		print_uint(f_str, args, char_count);
	if (ft_strchr(f_str, 'x') || ft_strchr(f_str, 'X'))
		print_hex(f_str, args, char_count);
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
	hex = 127;
	uint = UINT_MAX;
	str = "This is a string";
	printf_return = printf("%:%% s:%s u:%u c:%c x:%x X:%X p:%p%!valid\n", str, uint, c, hex, hex, &hex);
	ft_printf_return = ft_printf("%:%% s:%s u:%u c:%c x:%x X:%X p:%p%!valid\n", str, uint, c, hex, hex, &hex);
	ft_printf("printf return=%d\nft_printf_return=%d\n"
				"", printf_return, ft_printf_return);
}
