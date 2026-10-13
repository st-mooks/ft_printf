#include "ft_printf.h"

void    foo(char *f_str, ...)
{
    va_list args;

    if (!validate_format_str(f_str))
	{
		ft_putstr_fd(f_str, 1);
		return ;
	}
    va_start(args, f_str);
    if (ft_strchr(f_str, 'u'))
        print_uint(f_str, &args);
    if (ft_strchr(f_str, 's'))
        print_str(f_str, &args);
	if (ft_strchr(f_str, 'c'))
		print_char(f_str, &args);
}
int main(void)
{
    char            *f_str;
    char            *f_str2;
    char            *str;
    unsigned int    u;
	char			c;

    f_str = "-###1052c";
    f_str2 = "%-###1052c";
    str = "Hello world!";
    u = 42;
	c = 'm';
    printf("\"");
    fflush(stdout);
    foo(f_str, c);
    printf("\"\n\"");
    printf(f_str2, c);
    printf("\"");
}
