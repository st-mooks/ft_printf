/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:12:31 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 15:03:23 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_hex_str(long long n)
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

char	*build_str_hex(long long arg, t_format format_props, char *f_str)
{
	size_t	len;
	char	*precision_str;
	char	*pad_str;
	char	*str;
	char	*hex_str;

	hex_str = get_hex_str(arg);
	precision_str = get_precision_str(hex_str, format_props.precision);
	if (ft_strchr(f_str, '#'))
	{
		pad_str = precision_str;
		precision_str = ft_strjoin("0x", precision_str);
		free(pad_str);
	}
	len = max(3, ft_strlen(precision_str), format_props.precision, format_props.width);
	pad_str = get_pad_str(precision_str, len, format_props.pad_0);
	if (format_props.just_l)
		str = ft_strjoin(precision_str, pad_str);
	else
		str = ft_strjoin(pad_str, precision_str);
	free(hex_str);
	free(precision_str);
	free(pad_str);
	return (str);
}

void	print_hex(char *f_str, va_list *args, int *char_count)
{
	long long			arg;
	t_format			format_props;
	char				*str;

	arg = va_arg(*args, long long);
	format_props.precision = get_precision(f_str);
	format_props.width = get_width(f_str);
	format_props.just_l	= (ft_strchr(f_str, '-') != NULL);
	format_props.pad_0 = (get_pad_0(f_str)
						&& !format_props.precision
						&& !format_props.just_l);
	str = build_str_hex(arg, format_props, f_str);
	if (ft_strchr(f_str, 'X'))
		capitalise(str);
	ft_putstr_fd(str, 1);
	*char_count += ft_strlen(str);
	free(str);
}
