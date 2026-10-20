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
    char letter = 'A';
    int array[5] = {0, 1, 2, 3, 4};
    const char *str = "pointer target";
    const char *long_str =
        "A long string containing numbers 0123456789 and literal percent signs %%% ";

    /* TEST 000: Empty string | [%s] */
    printf("\n========== TEST 000: Empty string ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, "");
    n = printf("[%s]" "\n", "");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 001: Single-character string | [%s] */
    printf("\n========== TEST 001: Single-character string ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, "a");
    n = printf("[%s]" "\n", "a");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 002: Ordinary sentence | [%s] */
    printf("\n========== TEST 002: Ordinary sentence ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, "Hello, world!");
    n = printf("[%s]" "\n", "Hello, world!");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 003: Literal percent in string | [%s] */
    printf("\n========== TEST 003: Literal percent in string ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, "100% real");
    n = printf("[%s]" "\n", "100% real");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 004: Specifier-looking string content | [%s] */
    printf("\n========== TEST 004: Specifier-looking string content ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, "%% %d %p");
    n = printf("[%s]" "\n", "%% %d %p");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 005: Embedded newline in string | [%s] */
    printf("\n========== TEST 005: Embedded newline in string ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, "line1\nline2");
    n = printf("[%s]" "\n", "line1\nline2");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 006: Embedded tab in string | [%s] */
    printf("\n========== TEST 006: Embedded tab in string ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, "tab\there");
    n = printf("[%s]" "\n", "tab\there");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 007: Whitespace-only string | [%s] */
    printf("\n========== TEST 007: Whitespace-only string ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, "\t\n");
    n = printf("[%s]" "\n", "\t\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 008: Digit-only string | [%s] */
    printf("\n========== TEST 008: Digit-only string ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, "0123456789");
    n = printf("[%s]" "\n", "0123456789");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 009: Mixed-case alphabet string | [%s] */
    printf("\n========== TEST 009: Mixed-case alphabet string ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    n = printf("[%s]" "\n", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 010: Long string argument | [%s] */
    printf("\n========== TEST 010: Long string argument ==========\n");
    printf("Format: %s + SEP\n", "[%s]");
    ft_n = ft_printf("[%s]" SEP, long_str);
    n = printf("[%s]" "\n", long_str);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 011: Uppercase character | [%c] */
    printf("\n========== TEST 011: Uppercase character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, 'A');
    n = printf("[%c]" "\n", 'A');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 012: Lowercase character | [%c] */
    printf("\n========== TEST 012: Lowercase character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, 'z');
    n = printf("[%c]" "\n", 'z');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 013: Digit character | [%c] */
    printf("\n========== TEST 013: Digit character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, '0');
    n = printf("[%c]" "\n", '0');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 014: Percent as character | [%c] */
    printf("\n========== TEST 014: Percent as character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, '%');
    n = printf("[%c]" "\n", '%');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 015: Newline character | [%c] */
    printf("\n========== TEST 015: Newline character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, '\n');
    n = printf("[%c]" "\n", '\n');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 016: Tab character | [%c] */
    printf("\n========== TEST 016: Tab character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, '\t');
    n = printf("[%c]" "\n", '\t');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 017: NUL character | [%c] */
    printf("\n========== TEST 017: NUL character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, '\0');
    n = printf("[%c]" "\n", '\0');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 018: Space character | [%c] */
    printf("\n========== TEST 018: Space character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, ' ');
    n = printf("[%c]" "\n", ' ');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 019: DEL control character | [%c] */
    printf("\n========== TEST 019: DEL control character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, '\177');
    n = printf("[%c]" "\n", '\177');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 020: Integer zero as character | [%c] */
    printf("\n========== TEST 020: Integer zero as character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, 0);
    n = printf("[%c]" "\n", 0);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 021: SOH control character | [%c] */
    printf("\n========== TEST 021: SOH control character ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, 1);
    n = printf("[%c]" "\n", 1);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 022: Maximum byte value | [%c] */
    printf("\n========== TEST 022: Maximum byte value ==========\n");
    printf("Format: %s + SEP\n", "[%c]");
    ft_n = ft_printf("[%c]" SEP, 255);
    n = printf("[%c]" "\n", 255);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 023: Signed zero | [%d] */
    printf("\n========== TEST 023: Signed zero ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, 0);
    n = printf("[%d]" "\n", 0);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 024: Small positive integer | [%d] */
    printf("\n========== TEST 024: Small positive integer ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, 1);
    n = printf("[%d]" "\n", 1);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 025: Small negative integer | [%d] */
    printf("\n========== TEST 025: Small negative integer ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, -1);
    n = printf("[%d]" "\n", -1);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 026: Positive two-digit integer | [%d] */
    printf("\n========== TEST 026: Positive two-digit integer ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, 42);
    n = printf("[%d]" "\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 027: Negative two-digit integer | [%d] */
    printf("\n========== TEST 027: Negative two-digit integer ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, -42);
    n = printf("[%d]" "\n", -42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 028: Minimum signed integer | [%d] */
    printf("\n========== TEST 028: Minimum signed integer ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, INT_MIN);
    n = printf("[%d]" "\n", INT_MIN);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 029: Maximum signed integer | [%d] */
    printf("\n========== TEST 029: Maximum signed integer ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, INT_MAX);
    n = printf("[%d]" "\n", INT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 030: Large negative decimal | [%d] */
    printf("\n========== TEST 030: Large negative decimal ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, -1000000000);
    n = printf("[%d]" "\n", -1000000000);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 031: Large positive decimal | [%d] */
    printf("\n========== TEST 031: Large positive decimal ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, 1000000000);
    n = printf("[%d]" "\n", 1000000000);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 032: Near-minimum signed integer | [%d] */
    printf("\n========== TEST 032: Near-minimum signed integer ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, -2147483647);
    n = printf("[%d]" "\n", -2147483647);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 033: Nine-digit positive decimal | [%d] */
    printf("\n========== TEST 033: Nine-digit positive decimal ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, 123456789);
    n = printf("[%d]" "\n", 123456789);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 034: Nine-digit negative decimal | [%d] */
    printf("\n========== TEST 034: Nine-digit negative decimal ==========\n");
    printf("Format: %s + SEP\n", "[%d]");
    ft_n = ft_printf("[%d]" SEP, -987654321);
    n = printf("[%d]" "\n", -987654321);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 035: Integer i: zero | [%i] */
    printf("\n========== TEST 035: Integer i: zero ==========\n");
    printf("Format: %s + SEP\n", "[%i]");
    ft_n = ft_printf("[%i]" SEP, 0);
    n = printf("[%i]" "\n", 0);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 036: Integer i: positive one | [%i] */
    printf("\n========== TEST 036: Integer i: positive one ==========\n");
    printf("Format: %s + SEP\n", "[%i]");
    ft_n = ft_printf("[%i]" SEP, 1);
    n = printf("[%i]" "\n", 1);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 037: Integer i: negative one | [%i] */
    printf("\n========== TEST 037: Integer i: negative one ==========\n");
    printf("Format: %s + SEP\n", "[%i]");
    ft_n = ft_printf("[%i]" SEP, -1);
    n = printf("[%i]" "\n", -1);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 038: Integer i: positive two digits | [%i] */
    printf("\n========== TEST 038: Integer i: positive two digits ==========\n");
    printf("Format: %s + SEP\n", "[%i]");
    ft_n = ft_printf("[%i]" SEP, 42);
    n = printf("[%i]" "\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 039: Integer i: negative two digits | [%i] */
    printf("\n========== TEST 039: Integer i: negative two digits ==========\n");
    printf("Format: %s + SEP\n", "[%i]");
    ft_n = ft_printf("[%i]" SEP, -42);
    n = printf("[%i]" "\n", -42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 040: Integer i: INT_MIN | [%i] */
    printf("\n========== TEST 040: Integer i: INT_MIN ==========\n");
    printf("Format: %s + SEP\n", "[%i]");
    ft_n = ft_printf("[%i]" SEP, INT_MIN);
    n = printf("[%i]" "\n", INT_MIN);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 041: Integer i: INT_MAX | [%i] */
    printf("\n========== TEST 041: Integer i: INT_MAX ==========\n");
    printf("Format: %s + SEP\n", "[%i]");
    ft_n = ft_printf("[%i]" SEP, INT_MAX);
    n = printf("[%i]" "\n", INT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 042: Integer i: nine digits | [%i] */
    printf("\n========== TEST 042: Integer i: nine digits ==========\n");
    printf("Format: %s + SEP\n", "[%i]");
    ft_n = ft_printf("[%i]" SEP, 123456789);
    n = printf("[%i]" "\n", 123456789);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 043: Unsigned zero | [%u] */
    printf("\n========== TEST 043: Unsigned zero ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 0u);
    n = printf("[%u]" "\n", 0u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 044: Unsigned one | [%u] */
    printf("\n========== TEST 044: Unsigned one ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 1u);
    n = printf("[%u]" "\n", 1u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 045: Unsigned two | [%u] */
    printf("\n========== TEST 045: Unsigned two ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 2u);
    n = printf("[%u]" "\n", 2u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 046: Last single-digit unsigned | [%u] */
    printf("\n========== TEST 046: Last single-digit unsigned ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 9u);
    n = printf("[%u]" "\n", 9u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 047: First two-digit unsigned | [%u] */
    printf("\n========== TEST 047: First two-digit unsigned ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 10u);
    n = printf("[%u]" "\n", 10u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 048: Ordinary unsigned value | [%u] */
    printf("\n========== TEST 048: Ordinary unsigned value ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 42u);
    n = printf("[%u]" "\n", 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 049: Unsigned byte boundary minus one | [%u] */
    printf("\n========== TEST 049: Unsigned byte boundary minus one ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 255u);
    n = printf("[%u]" "\n", 255u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 050: Unsigned byte boundary plus one | [%u] */
    printf("\n========== TEST 050: Unsigned byte boundary plus one ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 256u);
    n = printf("[%u]" "\n", 256u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 051: Unsigned 16-bit maximum | [%u] */
    printf("\n========== TEST 051: Unsigned 16-bit maximum ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 65535u);
    n = printf("[%u]" "\n", 65535u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 052: Unsigned 16-bit overflow boundary | [%u] */
    printf("\n========== TEST 052: Unsigned 16-bit overflow boundary ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 65536u);
    n = printf("[%u]" "\n", 65536u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 053: Maximum unsigned integer | [%u] */
    printf("\n========== TEST 053: Maximum unsigned integer ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, UINT_MAX);
    n = printf("[%u]" "\n", UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 054: Unsigned one below maximum | [%u] */
    printf("\n========== TEST 054: Unsigned one below maximum ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, UINT_MAX - 1u);
    n = printf("[%u]" "\n", UINT_MAX - 1u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 055: Unsigned above INT_MAX | [%u] */
    printf("\n========== TEST 055: Unsigned above INT_MAX ==========\n");
    printf("Format: %s + SEP\n", "[%u]");
    ft_n = ft_printf("[%u]" SEP, 2147483648u);
    n = printf("[%u]" "\n", 2147483648u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 056: Hex zero | [%x] */
    printf("\n========== TEST 056: Hex zero ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 0u);
    n = printf("[%x]" "\n", 0u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 057: Hex one | [%x] */
    printf("\n========== TEST 057: Hex one ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 1u);
    n = printf("[%x]" "\n", 1u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 058: Hex numeric digit nine | [%x] */
    printf("\n========== TEST 058: Hex numeric digit nine ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 9u);
    n = printf("[%x]" "\n", 9u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 059: Hex first alphabetic digit a | [%x] */
    printf("\n========== TEST 059: Hex first alphabetic digit a ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 10u);
    n = printf("[%x]" "\n", 10u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 060: Hex last alphabetic digit f | [%x] */
    printf("\n========== TEST 060: Hex last alphabetic digit f ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 15u);
    n = printf("[%x]" "\n", 15u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 061: Hex carry to 0x10 | [%x] */
    printf("\n========== TEST 061: Hex carry to 0x10 ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 16u);
    n = printf("[%x]" "\n", 16u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 062: Hex 0x1f boundary | [%x] */
    printf("\n========== TEST 062: Hex 0x1f boundary ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 31u);
    n = printf("[%x]" "\n", 31u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 063: Hex two-digit maximum | [%x] */
    printf("\n========== TEST 063: Hex two-digit maximum ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 255u);
    n = printf("[%x]" "\n", 255u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 064: Hex carry to 0x100 | [%x] */
    printf("\n========== TEST 064: Hex carry to 0x100 ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 256u);
    n = printf("[%x]" "\n", 256u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 065: Hex 0xfff boundary | [%x] */
    printf("\n========== TEST 065: Hex 0xfff boundary ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 4095u);
    n = printf("[%x]" "\n", 4095u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 066: Hex carry to 0x1000 | [%x] */
    printf("\n========== TEST 066: Hex carry to 0x1000 ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 4096u);
    n = printf("[%x]" "\n", 4096u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 067: Hex multiple alphabetic digits | [%x] */
    printf("\n========== TEST 067: Hex multiple alphabetic digits ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 0xABCDEFu);
    n = printf("[%x]" "\n", 0xABCDEFu);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 068: Hex highest bit set | [%x] */
    printf("\n========== TEST 068: Hex highest bit set ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, 0x80000000u);
    n = printf("[%x]" "\n", 0x80000000u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 069: Hex UINT_MAX | [%x] */
    printf("\n========== TEST 069: Hex UINT_MAX ==========\n");
    printf("Format: %s + SEP\n", "[%x]");
    ft_n = ft_printf("[%x]" SEP, UINT_MAX);
    n = printf("[%x]" "\n", UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 070: Upper hex zero | [%X] */
    printf("\n========== TEST 070: Upper hex zero ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 0u);
    n = printf("[%X]" "\n", 0u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 071: Upper hex one | [%X] */
    printf("\n========== TEST 071: Upper hex one ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 1u);
    n = printf("[%X]" "\n", 1u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 072: Upper hex digit nine | [%X] */
    printf("\n========== TEST 072: Upper hex digit nine ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 9u);
    n = printf("[%X]" "\n", 9u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 073: Upper hex first letter A | [%X] */
    printf("\n========== TEST 073: Upper hex first letter A ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 10u);
    n = printf("[%X]" "\n", 10u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 074: Upper hex last letter F | [%X] */
    printf("\n========== TEST 074: Upper hex last letter F ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 15u);
    n = printf("[%X]" "\n", 15u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 075: Upper hex carry to 0x10 | [%X] */
    printf("\n========== TEST 075: Upper hex carry to 0x10 ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 16u);
    n = printf("[%X]" "\n", 16u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 076: Upper hex 0x1F boundary | [%X] */
    printf("\n========== TEST 076: Upper hex 0x1F boundary ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 31u);
    n = printf("[%X]" "\n", 31u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 077: Upper hex 0xFF boundary | [%X] */
    printf("\n========== TEST 077: Upper hex 0xFF boundary ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 255u);
    n = printf("[%X]" "\n", 255u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 078: Upper hex carry to 0x100 | [%X] */
    printf("\n========== TEST 078: Upper hex carry to 0x100 ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 256u);
    n = printf("[%X]" "\n", 256u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 079: Upper hex 0xFFF boundary | [%X] */
    printf("\n========== TEST 079: Upper hex 0xFFF boundary ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 4095u);
    n = printf("[%X]" "\n", 4095u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 080: Upper hex carry to 0x1000 | [%X] */
    printf("\n========== TEST 080: Upper hex carry to 0x1000 ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 4096u);
    n = printf("[%X]" "\n", 4096u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 081: Upper hex alphabetic sequence | [%X] */
    printf("\n========== TEST 081: Upper hex alphabetic sequence ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 0xABCDEFu);
    n = printf("[%X]" "\n", 0xABCDEFu);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 082: Upper hex highest bit set | [%X] */
    printf("\n========== TEST 082: Upper hex highest bit set ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, 0x80000000u);
    n = printf("[%X]" "\n", 0x80000000u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 083: Upper hex UINT_MAX | [%X] */
    printf("\n========== TEST 083: Upper hex UINT_MAX ==========\n");
    printf("Format: %s + SEP\n", "[%X]");
    ft_n = ft_printf("[%X]" SEP, UINT_MAX);
    n = printf("[%X]" "\n", UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 084: Pointer to integer | [%p] */
    printf("\n========== TEST 084: Pointer to integer ==========\n");
    printf("Format: %s + SEP\n", "[%p]");
    ft_n = ft_printf("[%p]" SEP, (void *)&value);
    n = printf("[%p]" "\n", (void *)&value);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 085: Pointer to character | [%p] */
    printf("\n========== TEST 085: Pointer to character ==========\n");
    printf("Format: %s + SEP\n", "[%p]");
    ft_n = ft_printf("[%p]" SEP, (void *)&letter);
    n = printf("[%p]" "\n", (void *)&letter);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 086: Pointer to string storage | [%p] */
    printf("\n========== TEST 086: Pointer to string storage ==========\n");
    printf("Format: %s + SEP\n", "[%p]");
    ft_n = ft_printf("[%p]" SEP, (void *)str);
    n = printf("[%p]" "\n", (void *)str);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 087: Null pointer representation | [%p] */
    printf("\n========== TEST 087: Null pointer representation ==========\n");
    printf("Format: %s + SEP\n", "[%p]");
    ft_n = ft_printf("[%p]" SEP, (void *)NULL);
    n = printf("[%p]" "\n", (void *)NULL);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 088: Pointer to first array element | [%p] */
    printf("\n========== TEST 088: Pointer to first array element ==========\n");
    printf("Format: %s + SEP\n", "[%p]");
    ft_n = ft_printf("[%p]" SEP, (void *)&array[0]);
    n = printf("[%p]" "\n", (void *)&array[0]);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 089: Pointer to last array element | [%p] */
    printf("\n========== TEST 089: Pointer to last array element ==========\n");
    printf("Format: %s + SEP\n", "[%p]");
    ft_n = ft_printf("[%p]" SEP, (void *)&array[4]);
    n = printf("[%p]" "\n", (void *)&array[4]);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 090: Array decay to pointer | [%p] */
    printf("\n========== TEST 090: Array decay to pointer ==========\n");
    printf("Format: %s + SEP\n", "[%p]");
    ft_n = ft_printf("[%p]" SEP, (void *)array);
    n = printf("[%p]" "\n", (void *)array);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 091: Single literal percent in brackets | [%%] */
    printf("\n========== TEST 091: Single literal percent in brackets ==========\n");
    printf("Format: %s + SEP\n", "[%%]");
    ft_n = ft_printf("[%%]" SEP);
    n = printf("[%%]" "\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 092: Three consecutive literal percents | [%%%%%%] */
    printf("\n========== TEST 092: Three consecutive literal percents ==========\n");
    printf("Format: %s + SEP\n", "[%%%%%%]");
    ft_n = ft_printf("[%%%%%%]" SEP);
    n = printf("[%%%%%%]" "\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 093: Unbracketed literal percent | %% */
    printf("\n========== TEST 093: Unbracketed literal percent ==========\n");
    printf("Format: %s + SEP\n", "%%");
    ft_n = ft_printf("%%" SEP);
    n = printf("%%" "\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 094: Unbracketed repeated percents | %%%% */
    printf("\n========== TEST 094: Unbracketed repeated percents ==========\n");
    printf("Format: %s + SEP\n", "%%%%");
    ft_n = ft_printf("%%%%" SEP);
    n = printf("%%%%" "\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 095: Plain text without conversions | plain text */
    printf("\n========== TEST 095: Plain text without conversions ==========\n");
    printf("Format: %s + SEP\n", "plain text");
    ft_n = ft_printf("plain text" SEP);
    n = printf("plain text" "\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 096: NULL format body | NULL */
    printf("\n========== TEST 096: NULL format body ==========\n");
    printf("Format: NULL\n");
    ft_n = ft_printf(NULL);
    n = printf(NULL);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 097: Empty format body with newline |  */
    printf("\n========== TEST 097: Empty format body with newline ==========\n");
    printf("Format: %s + SEP\n", "");
    ft_n = ft_printf("" SEP);
    n = printf("" "\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 098: Percent between literal words | hello %% world */
    printf("\n========== TEST 098: Percent between literal words ==========\n");
    printf("Format: %s + SEP\n", "hello %% world");
    ft_n = ft_printf("hello %% world" SEP);
    n = printf("hello %% world" "\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 099: Separated literal percents | %% %% %% */
    printf("\n========== TEST 099: Separated literal percents ==========\n");
    printf("Format: %s + SEP\n", "%% %% %%");
    ft_n = ft_printf("%% %% %%" SEP);
    n = printf("%% %% %%" "\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 100: Percent immediately before decimal | [%%%d] */
    printf("\n========== TEST 100: Percent immediately before decimal ==========\n");
    printf("Format: %s + SEP\n", "[%%%d]");
    ft_n = ft_printf("[%%%d]" SEP, 42);
    n = printf("[%%%d]" "\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 101: Percent immediately after decimal | [%d%%] */
    printf("\n========== TEST 101: Percent immediately after decimal ==========\n");
    printf("Format: %s + SEP\n", "[%d%%]");
    ft_n = ft_printf("[%d%%]" SEP, 42);
    n = printf("[%d%%]" "\n", 42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 102: Percent immediately before string | [%%%s] */
    printf("\n========== TEST 102: Percent immediately before string ==========\n");
    printf("Format: %s + SEP\n", "[%%%s]");
    ft_n = ft_printf("[%%%s]" SEP, "hi");
    n = printf("[%%%s]" "\n", "hi");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 103: Percent immediately after string | [%s%%] */
    printf("\n========== TEST 103: Percent immediately after string ==========\n");
    printf("Format: %s + SEP\n", "[%s%%]");
    ft_n = ft_printf("[%s%%]" SEP, "hi");
    n = printf("[%s%%]" "\n", "hi");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 104: Mixed signed unsigned and hex | [%d][%u][%x][%X] */
    printf("\n========== TEST 104: Mixed signed unsigned and hex ==========\n");
    printf("Format: %s + SEP\n", "[%d][%u][%x][%X]");
    ft_n = ft_printf("[%d][%u][%x][%X]" SEP, -1, UINT_MAX, 0xabcdefu, 0xabcdefu);
    n = printf("[%d][%u][%x][%X]" "\n", -1, UINT_MAX, 0xabcdefu, 0xabcdefu);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 105: String character and signed integer | [%s][%c][%d] */
    printf("\n========== TEST 105: String character and signed integer ==========\n");
    printf("Format: %s + SEP\n", "[%s][%c][%d]");
    ft_n = ft_printf("[%s][%c][%d]" SEP, "hi", '!', -42);
    n = printf("[%s][%c][%d]" "\n", "hi", '!', -42);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 106: Multiple pointers including NULL | [%p][%p][%p] */
    printf("\n========== TEST 106: Multiple pointers including NULL ==========\n");
    printf("Format: %s + SEP\n", "[%p][%p][%p]");
    ft_n = ft_printf("[%p][%p][%p]" SEP, (void *)&value, (void *)NULL, (void *)&letter);
    n = printf("[%p][%p][%p]" "\n", (void *)&value, (void *)NULL, (void *)&letter);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 107: NUL between printable characters | [%c][%c][%c] */
    printf("\n========== TEST 107: NUL between printable characters ==========\n");
    printf("Format: %s + SEP\n", "[%c][%c][%c]");
    ft_n = ft_printf("[%c][%c][%c]" SEP, 'A', '\0', 'Z');
    n = printf("[%c][%c][%c]" "\n", 'A', '\0', 'Z');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 108: Signed integer extremes in sequence | [%d][%d][%d][%d] */
    printf("\n========== TEST 108: Signed integer extremes in sequence ==========\n");
    printf("Format: %s + SEP\n", "[%d][%d][%d][%d]");
    ft_n = ft_printf("[%d][%d][%d][%d]" SEP, INT_MIN, -1, 0, INT_MAX);
    n = printf("[%d][%d][%d][%d]" "\n", INT_MIN, -1, 0, INT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 109: Unsigned extremes in sequence | [%u][%u][%u] */
    printf("\n========== TEST 109: Unsigned extremes in sequence ==========\n");
    printf("Format: %s + SEP\n", "[%u][%u][%u]");
    ft_n = ft_printf("[%u][%u][%u]" SEP, 0u, UINT_MAX, 1u);
    n = printf("[%u][%u][%u]" "\n", 0u, UINT_MAX, 1u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 110: Alternating hex letter cases | [%x][%X][%x][%X] */
    printf("\n========== TEST 110: Alternating hex letter cases ==========\n");
    printf("Format: %s + SEP\n", "[%x][%X][%x][%X]");
    ft_n = ft_printf("[%x][%X][%x][%X]" SEP, 0u, 15u, 16u, UINT_MAX);
    n = printf("[%x][%X][%x][%X]" "\n", 0u, 15u, 16u, UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 111: Empty and long strings together | [%s][%s][%s] */
    printf("\n========== TEST 111: Empty and long strings together ==========\n");
    printf("Format: %s + SEP\n", "[%s][%s][%s]");
    ft_n = ft_printf("[%s][%s][%s]" SEP, "", "abc", long_str);
    n = printf("[%s][%s][%s]" "\n", "", "abc", long_str);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 112: NUL at both ends of string | [%c][%s][%c] */
    printf("\n========== TEST 112: NUL at both ends of string ==========\n");
    printf("Format: %s + SEP\n", "[%c][%s][%c]");
    ft_n = ft_printf("[%c][%s][%c]" SEP, '\0', "middle", '\0');
    n = printf("[%c][%s][%c]" "\n", '\0', "middle", '\0');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 113: Percent between numeric conversions | [%d]%%[%u] */
    printf("\n========== TEST 113: Percent between numeric conversions ==========\n");
    printf("Format: %s + SEP\n", "[%d]%%[%u]");
    ft_n = ft_printf("[%d]%%[%u]" SEP, -42, 42u);
    n = printf("[%d]%%[%u]" "\n", -42, 42u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 114: Percent around pointer conversion | %%[%p]%% */
    printf("\n========== TEST 114: Percent around pointer conversion ==========\n");
    printf("Format: %s + SEP\n", "%%[%p]%%");
    ft_n = ft_printf("%%[%p]%%" SEP, (void *)&value);
    n = printf("%%[%p]%%" "\n", (void *)&value);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 115: All integer conversion types | [%i][%d][%u][%x][%X] */
    printf("\n========== TEST 115: All integer conversion types ==========\n");
    printf("Format: %s + SEP\n", "[%i][%d][%u][%x][%X]");
    ft_n = ft_printf("[%i][%d][%u][%x][%X]" SEP, INT_MIN, INT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
    n = printf("[%i][%d][%u][%x][%X]" "\n", INT_MIN, INT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 116: Every supported conversion together | [%s][%p][%c][%d][%i][%u][%x][%X][%%] */
    printf("\n========== TEST 116: Every supported conversion together ==========\n");
    printf("Format: %s + SEP\n", "[%s][%p][%c][%d][%i][%u][%x][%X][%%]");
    ft_n = ft_printf("[%s][%p][%c][%d][%i][%u][%x][%X][%%]" SEP, "str", (void *)&value, '\0', -7, 8, 9u, 10u, 11u);
    n = printf("[%s][%p][%c][%d][%i][%u][%x][%X][%%]" "\n", "str", (void *)&value, '\0', -7, 8, 9u, 10u, 11u);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 117: Alternating numbers and strings | [%d][%s][%d][%s] */
    printf("\n========== TEST 117: Alternating numbers and strings ==========\n");
    printf("Format: %s + SEP\n", "[%d][%s][%d][%s]");
    ft_n = ft_printf("[%d][%s][%d][%s]" SEP, 1, "", -1, "end");
    n = printf("[%d][%s][%d][%s]" "\n", 1, "", -1, "end");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 118: Adjacent characters including NUL | %c%c%c%c%c */
    printf("\n========== TEST 118: Adjacent characters including NUL ==========\n");
    printf("Format: %s + SEP\n", "%c%c%c%c%c");
    ft_n = ft_printf("%c%c%c%c%c" SEP, 'a', 'b', '\0', 'c', 'd');
    n = printf("%c%c%c%c%c" "\n", 'a', 'b', '\0', 'c', 'd');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 119: Adjacent integers without separators | %d%d%d%d%d */
    printf("\n========== TEST 119: Adjacent integers without separators ==========\n");
    printf("Format: %s + SEP\n", "%d%d%d%d%d");
    ft_n = ft_printf("%d%d%d%d%d" SEP, 1, 22, 333, 4444, 55555);
    n = printf("%d%d%d%d%d" "\n", 1, 22, 333, 4444, 55555);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 120: Adjacent strings with empty middle | %s%s%s */
    printf("\n========== TEST 120: Adjacent strings with empty middle ==========\n");
    printf("Format: %s + SEP\n", "%s%s%s");
    ft_n = ft_printf("%s%s%s" SEP, "alpha", "", "omega");
    n = printf("%s%s%s" "\n", "alpha", "", "omega");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 121: Interleaved percents and hex | %%%x%%%X%% */
    printf("\n========== TEST 121: Interleaved percents and hex ==========\n");
    printf("Format: %s + SEP\n", "%%%x%%%X%%");
    ft_n = ft_printf("%%%x%%%X%%" SEP, 0xfeedu, 0xBEEFu);
    n = printf("%%%x%%%X%%" "\n", 0xfeedu, 0xBEEFu);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 122: Literal prefixes infixes and suffixes | prefix:%d:middle:%s:suffix */
    printf("\n========== TEST 122: Literal prefixes infixes and suffixes ==========\n");
    printf("Format: %s + SEP\n", "prefix:%d:middle:%s:suffix");
    ft_n = ft_printf("prefix:%d:middle:%s:suffix" SEP, -123, "xyz");
    n = printf("prefix:%d:middle:%s:suffix" "\n", -123, "xyz");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 123: Null pointer and numeric zero | [%p][%x][%p][%X] */
    printf("\n========== TEST 123: Null pointer and numeric zero ==========\n");
    printf("Format: %s + SEP\n", "[%p][%x][%p][%X]");
    ft_n = ft_printf("[%p][%x][%p][%X]" SEP, (void *)NULL, 0u, (void *)&value, UINT_MAX);
    n = printf("[%p][%x][%p][%X]" "\n", (void *)NULL, 0u, (void *)&value, UINT_MAX);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 124: Very long literal text around conversion | START-aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa-[%d]-zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz-END */
    printf("\n========== TEST 124: Very long literal text around conversion ==========\n");
    printf("Format: %s + SEP\n", "START-aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa-[%d]-zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz-END");
    ft_n = ft_printf("START-aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa-[%d]-zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz-END" SEP, 123);
    n = printf("START-aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa-[%d]-zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz-END" "\n", 123);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 125: Twelve consecutive integer conversions | [%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d] */
    printf("\n========== TEST 125: Twelve consecutive integer conversions ==========\n");
    printf("Format: %s + SEP\n", "[%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d]");
    ft_n = ft_printf("[%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d]" SEP, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    n = printf("[%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d]" "\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 126: Twelve characters with alternating NUL | [%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c] */
    printf("\n========== TEST 126: Twelve characters with alternating NUL ==========\n");
    printf("Format: %s + SEP\n", "[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]");
    ft_n = ft_printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]" SEP, '\0', 'a', '\0', 'b', '\0', 'a', '\0', 'b', '\0', 'a', '\0', 'b');
    n = printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]" "\n", '\0', 'a', '\0', 'b', '\0', 'a', '\0', 'b', '\0', 'a', '\0', 'b');
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    /* TEST 127: Twenty consecutive percent conversions | [%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%] */
    printf("\n========== TEST 127: Twenty consecutive percent conversions ==========\n");
    printf("Format: %s + SEP\n", "[%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%]");
    ft_n = ft_printf("[%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%]" SEP);
    n = printf("[%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%][%%]" "\n");
    ft_printf("ft_printf: %d" SEP "printf:%d\n", ft_n, n);
    assert_return(ft_n, n);

    return (0);
}
