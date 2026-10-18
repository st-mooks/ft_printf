/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:08:04 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 13:08:05 by mbadarin         ###   ########.fr       */
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
