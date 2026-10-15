/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@students.42amman.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:49:34 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/15 10:56:22 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>
//Delete those after testing
/*# define RED_FG "\033[0;31m"
# define RESET "\033[0m"
# define WHITE_BG "\033[47m"
# include <stdio.h>
# include <string.h>*/

typedef struct s_format
{
	size_t	precision;
	size_t	width;
	int		just_l;
	int		pad_0;
	int		sign;
	int		space;
}	t_format;

int		validate_format_str(char *f_str);
char	*get_f_str(const char **str, int *char_count);
int		get_f_str_len(char *str);
int		char_in_set(char c, char *set);
void	print_percent(int percent_count, int *char_count);
size_t	get_precision(char *f_str);
size_t	get_width(char *f_str);
int		get_pad_0(char *f_str);
size_t	max(int arg_count, ...);
int		get_digits_count(long long l, int base_len);
char	*ft_ltoa(long long l);
char	*get_pad_str(char *precision_str, size_t len, int pad_0);
char	*get_precision_str(char *arg, size_t precision);
void	print_uint(char *f_str, va_list *args, int *char_count);
void	print_int(char *f_str, va_list *args, int *char_count);
void	print_str(char *f_str, va_list *args, int *char_count);
void	print_char(char *f_str, va_list *args, int *char_count);
void	print_hex(char *f_str, va_list *args, int *char_count);
void	print_ptr(char *f_str, va_list *args, int *char_count);
size_t	max(int arg_count, ...);
char	*fill_digits(long long l, int size);
int		get_digits_count(long long l, int base_len);
char	*ft_ltoa(long long l);
int		validate_format_str(char *f_str);
#endif
