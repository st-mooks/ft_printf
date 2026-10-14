#include<stdio.h>
#include<limits.h>
#include<stdint.h>
int	main()
{
	printf("**INT**\nint min:%d\nint max:%d\n**UINT**\nuint max:%u\n"
		"**LONG**\nlong min:%ld\nlong max:%ld\n"
		"", INT_MIN, INT_MAX, UINT_MAX, LONG_MIN, LONG_MAX);
	printf("**SIZE_T**\nsize_t max:%zu", SIZE_MAX);
}
