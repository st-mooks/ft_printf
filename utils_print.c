/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:08:43 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 10:08:47 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_in_set(char c, char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
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
