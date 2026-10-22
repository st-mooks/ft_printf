/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:06:56 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/22 10:56:48 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>
//Uncomment for testing
//# include <stdio.h>

typedef struct s_format
{
	char	f_ch;
	size_t	precision;
	size_t	width;
	size_t	len;
	int		precision_flag;
	int		just_l;
	int		pad_0;
	int		sign;
	int		space;
	int		hex_0x;
}	t_format;

//utils_numeric: utility functions that handle numeric values
size_t			max(int arg_count, ...);
char			*fill_digits(uintptr_t l, int size);
int				get_digits_count(uintptr_t l, int base_len);
char			*ft_uintptr_toa(uintptr_t l);
//utils_f_props: utility functions that handle s_format struct members (f_props)
size_t			get_precision(char *f_str);
size_t			get_width(char *f_str);
int				get_pad_0(char *f_str);
void			update_f_props_len(t_format *f_props, char *precision_str);
void			fill_f_props(t_format *f_props, char *f_str);
//utilty functions that create and manipulate strs
//		util_build_str: create final printable strs
char			*build_str_char(char *arg, t_format *f_props);
char			*build_str_hex(char *arg, t_format *f_props);
char			*build_str_int(int arg, char *arg_str, t_format *f_props);
char			*build_str_str(char *arg, t_format *f_props);
char			*build_str_uint(char *arg, t_format *f_props);
//		util_str: handle all other str operations
char			*get_precision_str(char *arg, t_format f_props);
char			*get_pad_str(char *precision_str, size_t len, int pad_0);
char			*get_hex_str(uintptr_t n);
char			*reset_str(char *str, char *new);
void			capitalise(char *str);
//		print_str: trim the arg str to fit precision
char			*get_trim_str(char *arg, t_format f_props);
//utils_flags: handle sign and space flags for signed int (%d/%i)
//and # flag for hex (%x/%X/%p)
void			add_sign_space(char **precision_str, char **pad_str,
					int arg, t_format *f_props);
void			add_0x(char **precision_str, char **pad_str, t_format *f_props);
//utils_arg_ptr: create and retrieve pionters to pass to arg print functions
void			*get_arg(va_list *args, t_format f_props);
int				*create_int_ptr(int n);
unsigned int	*create_uint_ptr(unsigned int u);
//utils_print: utility functions for printing
void			print_update_free(char *str, int *char_count,
					t_format f_props, int is_null_char);
void			print_percent(int percent_count, int *char_count);
void			print_arg(va_list *args, int *char_count, t_format f_props);
void			check_and_print(char *f_str, va_list *args, int *char_count);
//arg print functions
void			print_char(char arg, int *char_count, t_format f_props);
void			print_str(char *arg, int *char_count, t_format f_props);
void			print_int(int arg, int *char_count, t_format f_props);
void			print_uint(unsigned int arg, int *char_count,
					t_format f_props);
void			print_hex(uintptr_t arg, int *char_count,
					t_format f_props);
void			print_ptr(void *arg, int *char_count, t_format f_props);
//utils_f_str: f_str creation and validation
int				get_f_str_len(char *str);
char			*get_f_str(const char **str, int *char_count);
int				validate_format_str(char *f_str);
//ft_printf without input check
int				ft_printf(const char *str, ...);
//ft_printf's input check according to the original printf rules
/*int		ft_printf(const char *str, ...)
				__attribute__((format(printf, 1, 2)));*/
#endif
