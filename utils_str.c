#include "ft_printf.h"

char	*get_precision_str(char *arg, size_t precision)
{
	char	*str;
	size_t	arg_len;
	size_t	i;
	size_t	size;

	arg_len = ft_strlen(arg);
	size = max(2, arg_len, precision) + 1;
	str = malloc(size);
	i = 0;
	while (precision > arg_len + i)
		str[i++] = '0';
	str[i] = '\0';
	ft_strlcat(str, arg, size);
	return (str);
}

char	*get_pad_str(char *precision_str, size_t len, int pad_0)
{
	char	pad_char;
	char	*str;
	size_t	size;
	size_t	i;

	pad_char = ' ';
	size = len - ft_strlen(precision_str);
	str = malloc(size + 1);
	if (pad_0)
		pad_char = '0';
	i = 0;
	while (size > i)
		str[i++] = pad_char;
	str[i] = '\0';
	return (str);
}
