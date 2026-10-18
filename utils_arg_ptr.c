/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arg_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:18:32 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 08:46:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*get_arg(char * f_str, va_list *args)
{
	if (ft_strchr(f_str, 'c'))
		return (create_int_ptr(va_arg(*args, int)));
	if (ft_strchr(f_str, 's'))
		return (va_arg(*args, char *));
	if (ft_strchr(f_str, 'p'))
		return (va_arg(*args, void *));
	if (ft_strchr(f_str, 'd')
		|| ft_strchr(f_str, 'i'))
		return (create_int_ptr(va_arg(*args, int)));
	if (ft_strchr(f_str, 'u')
		|| ft_strchr(f_str, 'x')
		|| ft_strchr(f_str, 'X'))
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