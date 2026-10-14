#include <stdio.h>
#include "ft_printf.h"

int	get_digits_count(long long l, int base_len)
{
	int	count;

	count = 0;
	if (l == 0)
		count++;
	if (l < 0)
		l *= -1;
	while (l > 0)
	{
        count++;
		l /= base_len;
	}
    printf("%zu", sizeof(uintptr_t));
	return (count);
}

char    *get_hex_str(unsigned int n)
{   
    int     size;
    int     i;
    char    *hex_str;
    
    size = get_digits_count((long long)n, 16);
    hex_str = malloc(size + 1);
    if (n == 0)
        hex_str[0] = '0';
    i = size;
    while (i > 0)
    {   
        hex_str[i - 1] = "0123456789abcdef"[n % 16];
        n /= 16;
        i--;
    }
    hex_str[size] = '\0';
    return (hex_str);
}

int main(void)
{
    char    c = 'n';
    long long p = (long long)(uintptr_t)&c;

    printf("p:%p\nlu:%lld", &c, p);
    //get_hex_str(100);
}