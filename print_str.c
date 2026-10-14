/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:50:01 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/14 15:50:07 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_trim_str(char *f_str, char *arg, size_t arg_len, size_t precision)
{
	char	*str;
	size_t	size;
	size_t	i;

	if (precision >= arg_len || !ft_strchr(f_str, '.'))
		return (ft_strdup(arg));
	size = 0;
	while (size < precision)
		size++;
	str = ft_substr(arg, 0, size);
	/*str = malloc(size + 1);
	i = 0;
	while (i < size)
		str[i++] = arg[i];
	str[i] = '\0';*/
	return (str);
}

char	*build_str_str(char *f_str, char *arg, t_format format_props)
{
	size_t	len;
	size_t	arg_len;
	char	*str;
	char	*trim_str;
	char	*pad_str;

	arg_len = ft_strlen(arg);
	len = max(2, arg_len, format_props.width);
	if (len > format_props.precision)
		len = format_props.precision;
	trim_str = get_trim_str(f_str, arg, arg_len, format_props.precision);
	pad_str = get_pad_str(trim_str, len, format_props.pad_0);
	if (format_props.just_l)
		str = ft_strjoin(trim_str, pad_str);
	else
		str = ft_strjoin(pad_str, trim_str);
	free(trim_str);
	free(pad_str);
	return (str);
}

void	print_str(char *f_str, va_list *args, int *char_count)
{
	char		*arg;
	char		*str;
	t_format	format_props;

	arg = va_arg(*args, char *);
	format_props.precision = get_precision(f_str);
	format_props.width = get_width(f_str);
	format_props.just_l = (ft_strchr(f_str, '-') != NULL);
	format_props.pad_0 = 0;
	str = build_str_str(f_str, arg, format_props);
	ft_putstr_fd(str, 1);
	*char_count += ft_strlen(str);
	free(str);
}
