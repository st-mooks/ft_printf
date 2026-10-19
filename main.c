#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include "ft_printf.h"

#define SEP "\n"

void    assert_return(int ft_n, int n)
{
    ft_printf("ASSERT RETURN: ");
    if (ft_n == n)
        ft_printf(GREEN"PASS\n"RESET);
    else
        ft_printf(RED"FAIL\n"RESET);
}

int main(void)
{
    int ft_n;
    int n;
    int value = 42;
    char c = 'A';

    /* ROUND: PRECISION AND WIDTH */

    /* TEST 000: [NULL] */
    printf("\n========== TEST 000 ==========\n");
    printf("Format: %s\n", "NULL");
    ft_n = ft_printf(NULL, 0);
    n = printf(NULL, 0);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 001: [%10.5d] */
    printf("\n========== TEST 001 ==========\n");
    printf("Format: %s + SEP\n", "[%10.5d]");
    ft_n = ft_printf("[%10.5d]" SEP, NULL);
    n = printf("[%10.5d]\n", NULL);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 002: [%-10.5d] */
    printf("\n========== TEST 002 ==========\n");
    printf("Format: %s + SEP\n", "[%-10.5d]");
    ft_n = ft_printf("[%-10.5d]" SEP, 42);
    n = printf("[%-10.5d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 003: [%010.5d] */
    printf("\n========== TEST 003 ==========\n");
    printf("Format: %s + SEP\n", "[%010.5d]");
    ft_n = ft_printf("[%010.5d]" SEP, 42);
    n = printf("[%010.5d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 004: [%+010.5d] */
    printf("\n========== TEST 004 ==========\n");
    printf("Format: %s + SEP\n", "[%+010.5d]");
    ft_n = ft_printf("[%+010.5d]" SEP, 42);
    n = printf("[%+010.5d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 005: [% 010.5d] */
    printf("\n========== TEST 005 ==========\n");
    printf("Format: %s + SEP\n", "[% 010.5d]");
    ft_n = ft_printf("[% 010.5d]" SEP, 42);
    n = printf("[% 010.5d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 006: [%+10.0d] */
    printf("\n========== TEST 006 ==========\n");
    printf("Format: %s + SEP\n", "[%+10.0d]");
    ft_n = ft_printf("[%+10.0d]" SEP, 0);
    n = printf("[%+10.0d]\n", 0);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 007: [%10.0d] */
    printf("\n========== TEST 007 ==========\n");
    printf("Format: %s + SEP\n", "[%10.0d]");
    ft_n = ft_printf("[%10.0d]" SEP, 0);
    n = printf("[%10.0d]\n", 0);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 008: [%-10.0d] */
    printf("\n========== TEST 008 ==========\n");
    printf("Format: %s + SEP\n", "[%-10.0d]");
    ft_n = ft_printf("[%-10.0d]" SEP, 0);
    n = printf("[%-10.0d]\n", 0);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 009: [%010.0u] */
    printf("\n========== TEST 009 ==========\n");
    printf("Format: %s + SEP\n", "[%010.0u]");
    ft_n = ft_printf("[%010.0u]" SEP, 0u);
    n = printf("[%010.0u]\n", 0u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 010: [%0.0x] */
    printf("\n========== TEST 010 ==========\n");
    printf("Format: %s + SEP\n", "[%0.0x]");
    ft_n = ft_printf("[%0.0x]" SEP, 0u);
    n = printf("[%0.0x]\n", 0u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 011: [%10.0X] */
    printf("\n========== TEST 011 ==========\n");
    printf("Format: %s + SEP\n", "[%10.0X]");
    ft_n = ft_printf("[%10.0X]" SEP, 0u);
    n = printf("[%10.0X]\n", 0u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 012: [%0000010.00005d] */
    printf("\n========== TEST 012 ==========\n");
    printf("Format: %s + SEP\n", "[%0000010.00005d]");
    ft_n = ft_printf("[%0000010.00005d]" SEP, 42);
    n = printf("[%0000010.00005d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* ROUND: FLAGS BEHAVING BADLY */

    /* TEST 013: [%+-10d] */
    printf("\n========== TEST 013 ==========\n");
    printf("Format: %s + SEP\n", "[%+-10d]");
    ft_n = ft_printf("[%+-10d]" SEP, 42);
    n = printf("[%+-10d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 014: [%+ 10d] */
    printf("\n========== TEST 014 ==========\n");
    printf("Format: %s + SEP\n", "[%+ 10d]");
    ft_n = ft_printf("[%+ 10d]" SEP, 42);
    n = printf("[%+ 10d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 015: [%0-10d] */
    printf("\n========== TEST 015 ==========\n");
    printf("Format: %s + SEP\n", "[%0-10d]");
    ft_n = ft_printf("[%0-10d]" SEP, 42);
    n = printf("[%0-10d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 016: [%---+++00010d] */
    printf("\n========== TEST 016 ==========\n");
    printf("Format: %s + SEP\n", "[%---+++00010d]");
    ft_n = ft_printf("[%---+++00010d]" SEP, 42);
    n = printf("[%---+++00010d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 017: [%   +++10d] */
    printf("\n========== TEST 017 ==========\n");
    printf("Format: %s + SEP\n", "[%   +++10d]");
    ft_n = ft_printf("[%   +++10d]" SEP, 42);
    n = printf("[%   +++10d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 018: [%#010x] */
    printf("\n========== TEST 018 ==========\n");
    printf("Format: %s + SEP\n", "[%#010x]");
    ft_n = ft_printf("[%#010x]" SEP, 42u);
    n = printf("[%#010x]\n", 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 019: [%#-10x] */
    printf("\n========== TEST 019 ==========\n");
    printf("Format: %s + SEP\n", "[%#-10x]");
    ft_n = ft_printf("[%#-10x]" SEP, 42u);
    n = printf("[%#-10x]\n", 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 020: [%#010X] */
    printf("\n========== TEST 020 ==========\n");
    printf("Format: %s + SEP\n", "[%#010X]");
    ft_n = ft_printf("[%#010X]" SEP, 42u);
    n = printf("[%#010X]\n", 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 021: [%##00--10x] */
    printf("\n========== TEST 021 ==========\n");
    printf("Format: %s + SEP\n", "[%##00--10x]");
    ft_n = ft_printf("[%##00--10x]" SEP, 42u);
    n = printf("[%##00--10x]\n", 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 022: [%#10.5x] */
    printf("\n========== TEST 022 ==========\n");
    printf("Format: %s + SEP\n", "[%#10.5x]");
    ft_n = ft_printf("[%#10.5x]" SEP, 42u);
    n = printf("[%#10.5x]\n", 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 023: [%#010.5x] */
    printf("\n========== TEST 023 ==========\n");
    printf("Format: %s + SEP\n", "[%#010.5x]");
    ft_n = ft_printf("[%#010.5x]" SEP, 42u);
    n = printf("[%#010.5x]\n", 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 024: [%#10.0x] */
    printf("\n========== TEST 024 ==========\n");
    printf("Format: %s + SEP\n", "[%#10.0x]");
    ft_n = ft_printf("[%#10.0x]" SEP, 0u);
    n = printf("[%#10.0x]\n", 0u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 025: [%#10.0x] */
    printf("\n========== TEST 025 ==========\n");
    printf("Format: %s + SEP\n", "[%#10.0x]");
    ft_n = ft_printf("[%#10.0x]" SEP, 1u);
    n = printf("[%#10.0x]\n", 1u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* ROUND: INTEGER LIMITS */

    /* TEST 026: [%d] */
    printf("\n========== TEST 026 ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, INT_MIN);
    n = printf("[%d]\n", INT_MIN);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 027: [%d] */
    printf("\n========== TEST 027 ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, INT_MAX);
    n = printf("[%d]\n", INT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 028: [%u] */
    printf("\n========== TEST 028 ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, UINT_MAX);
    n = printf("[%u]\n", UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 029: [%x] */
    printf("\n========== TEST 029 ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, UINT_MAX);
    n = printf("[%x]\n", UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 030: [%X] */
    printf("\n========== TEST 030 ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, UINT_MAX);
    n = printf("[%X]\n", UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 031: [%+020d] */
    printf("\n========== TEST 031 ==========\n");
    printf("Format: %s + SEP\n", "[%+020d]");
    ft_n = ft_printf("[%+020d]" SEP, INT_MIN);
    n = printf("[%+020d]\n", INT_MIN);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 032: [%020d] */
    printf("\n========== TEST 032 ==========\n");
    printf("Format: %s + SEP\n", "[%020d]");
    ft_n = ft_printf("[%020d]" SEP, INT_MAX);
    n = printf("[%020d]\n", INT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 033: [%25.20d] */
    printf("\n========== TEST 033 ==========\n");
    printf("Format: %s + SEP\n", "[%25.20d]");
    ft_n = ft_printf("[%25.20d]" SEP, INT_MIN);
    n = printf("[%25.20d]\n", INT_MIN);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 034: [%-25.20d] */
    printf("\n========== TEST 034 ==========\n");
    printf("Format: %s + SEP\n", "[%-25.20d]");
    ft_n = ft_printf("[%-25.20d]" SEP, INT_MIN);
    n = printf("[%-25.20d]\n", INT_MIN);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 035: [%#025x] */
    printf("\n========== TEST 035 ==========\n");
    printf("Format: %s + SEP\n", "[%#025x]");
    ft_n = ft_printf("[%#025x]" SEP, UINT_MAX);
    n = printf("[%#025x]\n", UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 036: [%#025.20X] */
    printf("\n========== TEST 036 ==========\n");
    printf("Format: %s + SEP\n", "[%#025.20X]");
    ft_n = ft_printf("[%#025.20X]" SEP, UINT_MAX);
    n = printf("[%#025.20X]\n", UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 037: [%30.0u] */
    printf("\n========== TEST 037 ==========\n");
    printf("Format: %s + SEP\n", "[%30.0u]");
    ft_n = ft_printf("[%30.0u]" SEP, 0u);
    n = printf("[%30.0u]\n", 0u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* ROUND: STRINGS AND CHARACTERS */

    /* TEST 038: [%10.3s] */
    printf("\n========== TEST 038 ==========\n");
    printf("Format: %s + SEP\n", "[%10.3s]");
    ft_n = ft_printf("[%10.3s]" SEP, "Hello world");
    n = printf("[%10.3s]\n", "Hello world");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 039: [%-10.3s] */
    printf("\n========== TEST 039 ==========\n");
    printf("Format: %s + SEP\n", "[%-10.3s]");
    ft_n = ft_printf("[%-10.3s]" SEP, "Hello world");
    n = printf("[%-10.3s]\n", "Hello world");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 040: [%010.3s] */
    printf("\n========== TEST 040 ==========\n");
    printf("Format: %s + SEP\n", "[%010.3s]");
    ft_n = ft_printf("[%010.3s]" SEP, "Hello world");
    n = printf("[%010.3s]\n", "Hello world");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 041: [%.0s] */
    printf("\n========== TEST 041 ==========\n");
    printf("Format: %s + SEP\n", "[%.0s]");
    ft_n = ft_printf("[%.0s]" SEP, "Hello world");
    n = printf("[%.0s]\n", "Hello world");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 042: [%10.0s] */
    printf("\n========== TEST 042 ==========\n");
    printf("Format: %s + SEP\n", "[%10.0s]");
    ft_n = ft_printf("[%10.0s]" SEP, "Hello world");
    n = printf("[%10.0s]\n", "Hello world");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 043: [%3.10s] */
    printf("\n========== TEST 043 ==========\n");
    printf("Format: %s + SEP\n", "[%3.10s]");
    ft_n = ft_printf("[%3.10s]" SEP, "Hello");
    n = printf("[%3.10s]\n", "Hello");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 044: [%10s] */
    printf("\n========== TEST 044 ==========\n");
    printf("Format: %s + SEP\n", "[%10s]");
    ft_n = ft_printf("[%10s]" SEP, "");
    n = printf("[%10s]\n", "");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 045: [%10c] */
    printf("\n========== TEST 045 ==========\n");
    printf("Format: %s + SEP\n", "[%10c]");
    ft_n = ft_printf("[%10c]" SEP, '\0');
    n = printf("[%10c]\n", '\0');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 046: [%-10c] */
    printf("\n========== TEST 046 ==========\n");
    printf("Format: %s + SEP\n", "[%-10c]");
    ft_n = ft_printf("[%-10c]" SEP, '\0');
    n = printf("[%-10c]\n", '\0');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 047: [%c] */
    printf("\n========== TEST 047 ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, '\0');
    n = printf("[%c]\n", '\0');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* ROUND: POINTER TORTURE */

    /* TEST 048: [%p] */
    printf("\n========== TEST 048 ==========\n");
    printf("Format: %s + SEP\n", "[%p]");
    ft_n = ft_printf("[%p]" SEP, (void *)&value);
    n = printf("[%p]\n", (void *)&value);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 049: [%20p] */
    printf("\n========== TEST 049 ==========\n");
    printf("Format: %s + SEP\n", "[%20p]");
    ft_n = ft_printf("[%20p]" SEP, (void *)&value);
    n = printf("[%20p]\n", (void *)&value);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 050: [%-20p] */
    printf("\n========== TEST 050 ==========\n");
    printf("Format: %s + SEP\n", "[%-20p]");
    ft_n = ft_printf("[%-20p]" SEP, (void *)&value);
    n = printf("[%-20p]\n", (void *)&value);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 051: [%020p] */
    printf("\n========== TEST 051 ==========\n");
    printf("Format: %s + SEP\n", "[%020p]");
    ft_n = ft_printf("[%020p]" SEP, (void *)&value);
    n = printf("[%020p]\n", (void *)&value);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 052: [%p] */
    printf("\n========== TEST 052 ==========\n");
    printf("Format: %s + SEP\n", "[%p]");
    ft_n = ft_printf("[%p]" SEP, (void *)&c);
    n = printf("[%p]\n", (void *)&c);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 053: [%p] */
    printf("\n========== TEST 053 ==========\n");
    printf("Format: %s + SEP\n", "[%p]");
    ft_n = ft_printf("[%p]" SEP, (void *)NULL);
    n = printf("[%p]\n", (void *)NULL);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 054: [%20p] */
    printf("\n========== TEST 054 ==========\n");
    printf("Format: %s + SEP\n", "[%20p]");
    ft_n = ft_printf("[%20p]" SEP, (void *)NULL);
    n = printf("[%20p]\n", (void *)NULL);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 055: [%-20p] */
    printf("\n========== TEST 055 ==========\n");
    printf("Format: %s + SEP\n", "[%-20p]");
    ft_n = ft_printf("[%-20p]" SEP, (void *)NULL);
    n = printf("[%-20p]\n", (void *)NULL);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* ROUND: MULTIPLE CONVERSIONS */

    /* TEST 056: [%d][%u][%x][%X] */
    printf("\n========== TEST 056 ==========\n");
    printf("Format: %s + SEP\n", "[%d][%u][%x][%X]");
    ft_n = ft_printf("[%d][%u][%x][%X]" SEP, -42, 42u, 42u, 42u);
    n = printf("[%d][%u][%x][%X]\n", -42, 42u, 42u, 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 057: [%+010d][%#010x][%-10s] */
    printf("\n========== TEST 057 ==========\n");
    printf("Format: %s + SEP\n", "[%+010d][%#010x][%-10s]");
    ft_n = ft_printf("[%+010d][%#010x][%-10s]" SEP, -123, 0xabcU, "Hello");
    n = printf("[%+010d][%#010x][%-10s]\n", -123, 0xabcU, "Hello");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 058: [%c][%10c][%-10c][%c] */
    printf("\n========== TEST 058 ==========\n");
    printf("Format: %s + SEP\n", "[%c][%10c][%-10c][%c]");
    ft_n = ft_printf("[%c][%10c][%-10c][%c]" SEP, 'A', '\0', 'B', 'Z');
    n = printf("[%c][%10c][%-10c][%c]\n", 'A', '\0', 'B', 'Z');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 059: [%10.0d][%#10.0x][%-10.0s] */
    printf("\n========== TEST 059 ==========\n");
    printf("Format: %s + SEP\n", "[%10.0d][%#10.0x][%-10.0s]");
    ft_n = ft_printf("[%10.0d][%#10.0x][%-10.0s]" SEP, 0, 0u, "Hello");
    n = printf("[%10.0d][%#10.0x][%-10.0s]\n", 0, 0u, "Hello");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 060: [%---+++00015.10d][%##00--15.10x] */
    printf("\n========== TEST 060 ==========\n");
    printf("Format: %s + SEP\n", "[%---+++00015.10d][%##00--15.10x]");
    ft_n = ft_printf("[%---+++00015.10d][%##00--15.10x]" SEP, -42, 0xabcU);
    n = printf("[%---+++00015.10d][%##00--15.10x]\n", -42, 0xabcU);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 061: [%p][%x][%p][%X] */
    printf("\n========== TEST 061 ==========\n");
    printf("Format: %s + SEP\n", "[%p][%x][%p][%X]");
    ft_n = ft_printf("[%p][%x][%p][%X]" SEP, (void *)&value, UINT_MAX, (void *)NULL, 0u);
    n = printf("[%p][%x][%p][%X]\n", (void *)&value, UINT_MAX, (void *)NULL, 0u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* ROUND: IMPLEMENTATION-SPECIFIC / NONSTANDARD */

    /* TEST 062: [%+u] */
    printf("\n========== TEST 062 ==========\n");
    printf("Format: %s + SEP\n", "[%+u]");
    ft_n = ft_printf("[%+u]" SEP, 42u);
    n = printf("[%+u]\n", 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 063: [% u] */
    printf("\n========== TEST 063 ==========\n");
    printf("Format: %s + SEP\n", "[% u]");
    ft_n = ft_printf("[% u]" SEP, 42u);
    n = printf("[% u]\n", 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 064: [%#d] */
    printf("\n========== TEST 064 ==========\n");
    printf("Format: %s + SEP\n", "[%#d]");
    ft_n = ft_printf("[%#d]" SEP, 42);
    n = printf("[%#d]\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 065: [%0s] */
    printf("\n========== TEST 065 ==========\n");
    printf("Format: %s + SEP\n", "[%0s]");
    ft_n = ft_printf("[%0s]" SEP, "Hello");
    n = printf("[%0s]\n", "Hello");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 066: [%+s] */
    printf("\n========== TEST 066 ==========\n");
    printf("Format: %s + SEP\n", "[%+s]");
    ft_n = ft_printf("[%+s]" SEP, "Hello");
    n = printf("[%+s]\n", "Hello");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 067: [%#p] */
    printf("\n========== TEST 067 ==========\n");
    printf("Format: %s + SEP\n", "[%#p]");
    ft_n = ft_printf("[%#p]" SEP, (void *)&value);
    n = printf("[%#p]\n", (void *)&value);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 068: [%.0p] */
    printf("\n========== TEST 068 ==========\n");
    printf("Format: %s + SEP\n", "[%.0p]");
    ft_n = ft_printf("[%.0p]" SEP, (void *)NULL);
    n = printf("[%.0p]\n", (void *)NULL);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 069: [%010.5p] */
    printf("\n========== TEST 069 ==========\n");
    printf("Format: %s + SEP\n", "[%010.5p]");
    ft_n = ft_printf("[%010.5p]" SEP, (void *)&value);
    n = printf("[%010.5p]\n", (void *)&value);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 070: [%10%] */
    printf("\n========== TEST 070 ==========\n");
    printf("Format: %s + SEP\n", "[%10%]");
    ft_n = ft_printf("[%10%]" SEP);
    n = printf("[%10%]\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 071: [%-10%] */
    printf("\n========== TEST 071 ==========\n");
    printf("Format: %s + SEP\n", "[%-10%]");
    ft_n = ft_printf("[%-10%]" SEP);
    n = printf("[%-10%]\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    /* TEST 072: [%05%] */
    printf("\n========== TEST 072 ==========\n");
    printf("Format: %s + SEP\n", "[%05%]");
    ft_n = ft_printf("[%05%]" SEP);
    n = printf("[%05%]\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);


    return (0);
}
