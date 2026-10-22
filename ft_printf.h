/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:06:56 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 15:48:41 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
//Uncomment for testing
//# include <stdio.h>
//# include <limits.h>

//utils_numeric: functions that handle numeric values
char	*fill_digits(uintptr_t l, int size);
int		get_digits_count(uintptr_t l, int base_len);
char	*ft_uintptr_toa(uintptr_t l);
//util_char_str: functions that create and manipulate strs and char
char	*add_str(char *original, char *str, int char_count);
char	*add_char(char *original, char c, int char_count);
char	*get_hex_str(uintptr_t n);
void	capitalise(char *str);
//utils_arg_f_ch: functions for finding the format char and args
char	get_f_ch(const char **str);
char	*get_arg(const char **str, char f_ch, va_list *args);
//utils_build_printable_str: functions for building the final printable str
void	add_arg(const char **str, char **printable_str,
			va_list *args, int *char_count);
void	add_literal(const char **str, char **printable_str, int *char_count);
//arg stringification functions
//		utils_args
char	*char_to_str(char arg);
char	*int_to_str(int arg);
char	*uint_to_str(unsigned int arg);
char	*hex_to_str(char f_ch, uintptr_t arg);
//		utils_args2
char	*str_to_str(char *arg);
char	*ptr_to_str(void *arg);
char	*percent_to_str(const char **str);
//ft_printf without compile time input validation
int		ft_printf(const char *str, ...);
//ft_printf with compile time input validation
/*int		ft_printf(const char *str, ...)
				__attribute__((format(printf, 1, 2)));*/
#endif
