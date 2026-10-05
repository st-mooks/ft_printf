/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:39:27 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/05 15:19:26 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "../libft/libft.h"
int	count_args(const char *str)
{
	int		count;
	char	pre;

	count = 0;
	pre = '\0';
	while (*str)
	{
		while (*str != '%' && *str)
		{
			pre = *str;
			str++;
		}
		if (*str)
			if (*(str + 1) != '%' && pre != '%')
				count++;
		pre = *str;
		str++;
	}
	return (count);
}

char	get_specifier(const char **str)
{
	*str = ft_strchr(*str, '%') + 1;
	return (**str);
}

char	*format_string(void *data, char s)
{
	if (s == 'd')
		return (ft_itoa(*((int *)data)));
	if (s == 's')
		return ((char *) data);
	return (NULL);
}

int	ft_printf(const char *str, ...)
{
	int		args_count;
	va_list	args;
	int		i;
	char	s;
	int		num;
	char	*result;

	args_count = count_args(str);
	va_start(args, str);
	i = 0;
	while (i++ < args_count)
	{
		s = get_specifier(&str);
		if (s == 's')
		{
			result = format_string(va_arg(args, char *), s);
			printf("%s", result);
		}	
		if (s == 'd')
		{
			num = va_arg(args, int);
			result = format_string(&num, s);
			printf("%s", result);
		}
	}
	va_end(args);
	return (0);
}

int	main()
{
	ft_printf("arg1%s %d", "123", 123);
}
