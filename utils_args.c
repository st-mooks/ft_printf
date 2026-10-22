/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:12:21 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 10:29:56 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_to_str(char arg)
{
	char		*str;

	str = malloc(2);
	if (str)
	{
		str[0] = arg;
		str[1] = '\0';
	}
	return (str);
}

char	*hex_to_str(char f_ch, uintptr_t arg)
{
	char		*str;

	str = get_hex_str(arg);
	if (str && f_ch == 'X')
		capitalise(str);
	return (str);
}

char	*int_to_str(int arg)
{
	char		*str;

	str = ft_itoa(arg);
	return (str);
}

char	*uint_to_str(unsigned int arg)
{
	char		*str;

	str = ft_uintptr_toa(arg);
	return (str);
}
