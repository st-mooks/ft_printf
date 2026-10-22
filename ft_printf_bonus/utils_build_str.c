/* ************************************************************************** */
/*									    */
/*							:::      ::::::::   */
/*   utils_build_str.c				  :+:      :+:    :+:   */
/*						    +:+ +:+	 +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+	*/
/*						+#+#+#+#+#+   +#+	   */
/*   Created: 2026/10/18 16:02:08 by mbadarin	  #+#    #+#	     */
/*   Updated: 2026/10/22 10:59:24 by mbadarin	 ###   ########.fr       */
/*									    */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*build_str_char(char *arg, t_format *f_props)
{
	char	*pad_str;
	char	*str;

	update_f_props_len(f_props, arg);
	if (!*arg && f_props->len > 0)
		f_props->len -= 1;
	pad_str = get_pad_str(arg, f_props->len, f_props->pad_0);
	if (*arg)
	{
		if (f_props->just_l)
			str = ft_strjoin(arg, pad_str);
		else
			str = ft_strjoin(pad_str, arg);
		free(pad_str);
	}
	else
		str = pad_str;
	return (str);
}

char	*build_str_hex(char *arg, t_format *f_props)
{
	char	*precision_str;
	char	*pad_str;
	char	*str;

	precision_str = get_precision_str(arg, *f_props);
	update_f_props_len(f_props, precision_str);
	pad_str = get_pad_str(precision_str, f_props->len, f_props->pad_0);
	if (*arg != '0')
		add_0x(&precision_str, &pad_str, f_props);
	if (f_props->just_l)
		str = ft_strjoin(precision_str, pad_str);
	else
		str = ft_strjoin(pad_str, precision_str);
	free(precision_str);
	free(pad_str);
	return (str);
}

char	*build_str_int(int arg, char *arg_str, t_format *f_props)
{
	char	*str;
	char	*precision_str;
	char	*pad_str;

	precision_str = get_precision_str(arg_str, *f_props);
	update_f_props_len(f_props, precision_str);
	pad_str = get_pad_str(precision_str, f_props->len, f_props->pad_0);
	add_sign_space(&precision_str, &pad_str, arg, f_props);
	if (f_props->just_l)
		str = ft_strjoin(precision_str, pad_str);
	else
		str = ft_strjoin(pad_str, precision_str);
	free(precision_str);
	free(pad_str);
	return (str);
}

char	*build_str_str(char *arg, t_format *f_props)
{
	char	*str;
	char	*trim_str;
	char	*pad_str;

	trim_str = get_trim_str(arg, *f_props);
	if (f_props->precision > ft_strlen(arg))
		f_props->precision = ft_strlen(arg);
	update_f_props_len(f_props, trim_str);
	pad_str = get_pad_str(trim_str, f_props->len, f_props->pad_0);
	if (f_props->just_l)
		str = ft_strjoin(trim_str, pad_str);
	else
		str = ft_strjoin(pad_str, trim_str);
	free(trim_str);
	free(pad_str);
	return (str);
}

char	*build_str_uint(char *arg, t_format *f_props)
{
	char	*str;
	char	*precision_str;
	char	*pad_str;

	precision_str = get_precision_str(arg, *f_props);
	update_f_props_len(f_props, precision_str);
	pad_str = get_pad_str(precision_str, f_props->len, f_props->pad_0);
	if (f_props->just_l)
		str = ft_strjoin(precision_str, pad_str);
	else
		str = ft_strjoin(pad_str, precision_str);
	free(precision_str);
	free(pad_str);
	return (str);
}
