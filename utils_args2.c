/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:18:05 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 10:18:16 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ptr_to_str(void *arg)
{
	char	*str;
	char	*hex;

	if (arg)
	{
		hex = get_hex_str((uintptr_t) arg);
		str = ft_strjoin("0x", hex);
		free(hex);
	}
	else
		str = str_to_str("(nil)");
	return (str);
}

char	*str_to_str(char *arg)
{
	char	*str;

	if (arg)
		str = ft_strdup(arg);
	else
		str = ft_strdup("(null)");
	return (str);
}
