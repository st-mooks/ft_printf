/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:06:56 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/20 11:21:35 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>
//Uncomment for testing
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define WHITE_BG "\033[47m"
# include <stdio.h>
# include <string.h>

//utils_numeric: utility functions that handle numeric values
char			*fill_digits(uintptr_t l, int size);
int				get_digits_count(uintptr_t l, int base_len);
char			*ft_uintptr_toa(uintptr_t l);
//util_char_str: utilty functions that create and manipulate strs and char
char			*get_hex_str(uintptr_t n);
void			capitalise(char *str);
char			get_f_ch(const char **str, int *char_count);
//utils_print: utility functions for printing
void			print_update_free(char *str, int *char_count,
					int is_null_char);
void			print_percent(int percent_count, int *char_count);
void			print_arg(char  f_cj, va_list *args, int *char_count);
void			check_and_print(char f_ch, va_list *args, int *char_count);
//util_args: arg stringification functions
void			print_char(char arg, int *char_count);
void			print_str(char *arg, int *char_count);
void			print_int(int arg, int *char_count);
void			print_uint(unsigned int arg, int *char_count);
void			print_hex(char f_ch, uintptr_t arg, int *char_count);
void			print_ptr(char f_ch, void *arg, int *char_count);
//ft_printf without input check
int				ft_printf(const char *str, ...);
//ft_printf's input check according to the original printf rules
/*int		ft_printf(const char *str, ...)
				__attribute__((format(printf, 1, 2)));*/
#endif
