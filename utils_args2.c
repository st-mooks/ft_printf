/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:18:05 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 15:33:07 by mbadarin         ###   ########.fr       */
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

char	*percent_to_str(const char **str)
{
	int		count;
	char	*p_str;

	count = 2;
	while (**str == '%')
	{
		count++;
		*str += 1;
	}
	if (count % 2 == 1)
		*str -= 1;
	count /= 2;
	p_str = malloc(count + 1);
	p_str[count--] = '\0';
	while (count >= 0)
		p_str[count--] = '%';
	return (p_str);
}
