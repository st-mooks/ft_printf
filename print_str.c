/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:50:01 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/17 17:02:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_trim_str(char *f_str, char *arg, size_t arg_len, size_t precision)
{
	char	*str;
	size_t	size;

	if (precision >= arg_len || !ft_strchr(f_str, '.'))
		return (ft_strdup(arg));
	size = 0;
	while (size < precision)
		size++;
	str = ft_substr(arg, 0, size);
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
	//len = max(2, arg_len, format_props.width);
	/*if (len > format_props.precision)
		len = format_props.precision;*/
	trim_str = get_trim_str(f_str, arg, arg_len, format_props.precision);
	len = max(2, ft_strlen(trim_str), format_props.width);
	pad_str = get_pad_str(trim_str, len, format_props.pad_0);
	if (format_props.just_l)
		str = ft_strjoin(trim_str, pad_str);
	else
		str = ft_strjoin(pad_str, trim_str);
	free(trim_str);
	free(pad_str);
	return (str);
}

void	print_str(char *f_str, char *arg, int *char_count)
{
	char		*str;
	char		*ptr;
	t_format	format_props;

	ptr = NULL;
	if (!arg)
	{
		arg = ft_strdup("(null)");
		ptr = arg;
	}
	fill_format_props(&format_props, f_str);
	str = build_str_str(f_str, arg, format_props);
	if (ptr)
		free(ptr);
	print_update_free(str, char_count);
}
