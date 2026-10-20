/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:08:04 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 10:58:13 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_trim_str(char *arg, t_format f_props)
{
	char	*str;
	size_t	size;
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if (f_props.precision >= arg_len
		|| !f_props.precision_flag
		|| f_props.f_ch == 'p')
		return (ft_strdup(arg));
	size = 0;
	while (size < f_props.precision)
		size++;
	str = ft_substr(arg, 0, size);
	return (str);
}

void	print_str(char *arg, int *char_count, t_format f_props)
{
	char		*str;

	if (!arg)
	{
		print_str("(null)", char_count, f_props);
		return ;
	}
	str = build_str_str(arg, &f_props);
	print_update_free(str, char_count, f_props, 0);
}
