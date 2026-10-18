/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:49:34 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/18 08:49:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>
//Uncomment for testing
# define RED_FG "\033[0;31m"
# define RESET "\033[0m"
# define WHITE_BG "\033[47m"
# include <stdio.h>
# include <string.h>

typedef struct s_format
{
	size_t	precision;
	size_t	width;
	int		just_l;
	int		pad_0;
	int		sign;
	int		space;
}	t_format;

//utils_numeric: utility functions that handle numeric values
size_t		max(int arg_count, ...);
char		*fill_digits(uintptr_t l, int size);
int			get_digits_count(uintptr_t l, int base_len);
char		*ft_uintptr_toa(uintptr_t l);
//utility functions that handle format_props struct
//
size_t			get_precision(char *f_str);
size_t			get_width(char *f_str);
int				get_pad_0(char *f_str);
void    		fill_format_props(t_format *format_props, char *f_str);
//utilty functions that create strs
char			*get_precision_str(char *arg, size_t precision);
char			*get_pad_str(char *precision_str, size_t len, int pad_0);
//create and retrieve pionters to pass to arg print functions
void			*get_arg(char *f_str, va_list *args);
int				*create_int_ptr(int n);
unsigned int	*create_uint_ptr(unsigned int u);
//utils_print: utility functions for printing
void			print_update_free(char *str, int *char_count);
void			print_percent(int percent_count, int *char_count);
void			print_arg(char *f_str, va_list *args, int *char_count);
//arg print functions
void			print_char(char *f_str, char arg, int *char_count);
void			print_str(char *f_str, char *arg, int *char_count);
void			print_int(char *f_str, int arg, int *char_count);
void			print_uint(char *f_str, unsigned int arg, int *char_count);
void			print_hex(char *f_str, uintptr_t arg, int *char_count);
void			print_ptr(char *f_str, void *arg, int *char_count);
//utils_f_str: f_str creation and validation
void			check_and_print(char *f_str, va_list *args, int *char_count);
int				get_f_str_len(char *str);
char			*get_f_str(const char **str, int *char_count);
int				validate_format_str(char *f_str);
//ft_printf without input check
int				ft_printf(const char *str, ...);
//ft_printf's input check according to the original printf rules
/*int		ft_printf(const char *str, ...)
				__attribute__((format(printf, 1, 2)));*/
#endif
