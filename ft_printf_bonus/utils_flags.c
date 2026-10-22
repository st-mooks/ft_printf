/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 utils_flags.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/10/20 10:58:45 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/10/22 11:00:49 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	add_sign_space(char **precision_str, char **pad_str,
	int arg, t_format *f_props)
{
	char	*sign_space;

	sign_space = " ";
	if (f_props->sign)
		sign_space = "+";
	if (arg < 0)
	{
		sign_space = "-";
		f_props->sign = 1;
	}
	if (f_props->sign || f_props->space)
	{
		if (ft_strlen(*pad_str) > 0)
		{
			*pad_str = reset_str(*pad_str, ft_strdup(*pad_str + 1));
		}
		else if (*sign_space == '-')
			f_props->len += 1;
		if (f_props->pad_0)
			*pad_str = reset_str(*pad_str, ft_strjoin(sign_space, *pad_str));
		else
			*precision_str = reset_str(*precision_str,
					ft_strjoin(sign_space, *precision_str));
	}
}

void	add_0x(char **precision_str, char **pad_str, t_format *f_props)
{
	ssize_t	pad_len;

	pad_len = ft_strlen(*pad_str);
	if (f_props->hex_0x && **precision_str)
	{
		if (pad_len == 1)
		{
			*pad_str = reset_str(*pad_str, ft_strdup(*pad_str + 1));
			f_props->len += 1;
		}
		else if (pad_len > 1)
			*pad_str = reset_str(*pad_str, ft_strdup(*pad_str + 2));
		else
			f_props->len += 2;
		if (f_props->pad_0)
			*pad_str = reset_str(*pad_str, ft_strjoin("0x", *pad_str));
		else
			*precision_str = reset_str(*precision_str,
					ft_strjoin("0x", *precision_str));
	}
}
