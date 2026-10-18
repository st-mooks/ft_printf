#include "ft_printf.h"

char    *advance_str(char *pad_str, t_format format_props)
{
    char *ptr;

    if ((format_props.sign || format_props.space)
        && pad_str)
    {
        if (*pad_str)
        {
            ptr = pad_str;
            pad_str = ft_strdup(pad_str + 1);
            free (ptr);
        }
    }
    return (pad_str);
}

char    *add_sign_space(char *precision_str, t_format format_props)
{
    if (format_props.sign)
        precision_str = join_free_str(precision_str, "+", 1);
    else if (format_props.space)
        precision_str = join_free_str(precision_str, " ", 1);
    return (precision_str);
}

void    add_0x(char **precision_str, char **pad_str,
    char *f_str,   t_format format_props)
{
    int     is_add;
    char    *ptr;

    is_add = (ft_strchr(f_str, '#') != NULL);
    if (is_add)
    {
        if (!format_props.pad_0)
            *precision_str = join_free_str(*precision_str, "0x", 1);
        else if (ft_strlen(*pad_str) > 1)
        {
            ptr = *pad_str;
            *pad_str = ft_strdup(*pad_str + 2);
            *pad_str = join_free_str(*pad_str, "0x", 1);
            free(ptr);
        }
    }
}