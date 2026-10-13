/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:42:58 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/13 14:34:51 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
//Delete those after testing
# include <stdio.h>
# include <string.h>

typedef struct s_format
{
	size_t	precision;
	size_t	width;
	int		just_l;
	int		pad_0;
}	t_format;

void	foo(char *f_str, ...)__attribute__((format(printf, 1, 2)));
int		validate_format_str(char *f_str);
size_t	get_precision(char *f_str);
size_t	get_width(char *f_str);
size_t	max(int arg_count, ...);
char	*get_pad_str(char *precision_str, size_t len, int pad_0);
char	*get_precision_str(char *arg, size_t precision);
void	print_uint(char *f_str, va_list *args);
void	print_str(char *f_str, va_list *args);
void	print_char(char *f_str, va_list *args);
#endif
