/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arg_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:08:25 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 10:58:25 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	*get_arg(va_list *args, t_format f_props)
{
	if (f_props.f_ch == 'c')
		return (create_int_ptr(va_arg(*args, int)));
	if (f_props.f_ch == 's')
		return (va_arg(*args, char *));
	if (f_props.f_ch == 'p')
		return (va_arg(*args, void *));
	if (f_props.f_ch == 'd'
		|| f_props.f_ch == 'i')
		return (create_int_ptr(va_arg(*args, int)));
	if (f_props.f_ch == 'u'
		|| f_props.f_ch == 'x'
		|| f_props.f_ch == 'X')
		return (create_uint_ptr(va_arg(*args, unsigned int)));
	return (NULL);
}

int	*create_int_ptr(int n)
{
	int	*ptr;

	ptr = malloc(sizeof(int));
	*ptr = n;
	return (ptr);
}

unsigned int	*create_uint_ptr(unsigned int u)
{
	unsigned int	*ptr;

	ptr = malloc(sizeof(unsigned int));
	*ptr = u;
	return (ptr);
}
