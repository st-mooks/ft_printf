*This project has been created as part of the 42 curriculum by mbadarin.*

# FT_PRINTF

## A 42 Amman Porject

### Description

A basic implementation of C's printf created as a requirement of "**Milestone 1**" of 42 Amman's core curriculum.

This implemetation handles a subset of the *character specifiers* (and *flags* in the bonus section) supported in the original. It **does not** implemet any of the buffer management behaviours of the original printf.


### Instructions

Use the provided make file to create an archive containig the preprocessed object files:

- Create .o files (from both the **./** and **../libft** directories) and add them to libprintf.a library:
```
make
#OR
make all
```
- Delete all .o files:
```
make clean
```
- Delete all .o files *AND* libft.a:
```
make fclean
```
- Delete all .o files and libft.a, then run **make all**:
```
make re
```

### Resources

- Manual page printf.
- [Geeksforgeeks.org](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
- [cplusplus.com](https://cplusplus.com/reference/cstdio/printf/)
- [Laboratoire d'informatique de l'École polytechnique](https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html)
- [cppreference.com](https://en.cppreference.com/c/io/fprintf)
- [GCC, the GNU Compiler Collection](https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html)
- [Medium.com](https://medium.com/@nyangaresibrian/variadic-functions-1e148f21c898) and [Medium.com](https://medium.com/@sreehema2025/understanding-buffers-in-c-why-your-printf-might-not-show-up-immediately-98c4d9d60d75)[^1]
- [Stackoverflow.com](https://stackoverflow.com/questions/45385807/what-is-it-with-printf-sending-output-to-buffer)[^1]

[^1]: Note: Last two references concern printf's buffering, which, while not implemented in this version, is still a note worthy behaviour to be aware of.

Use of AI was limited, and mainly used with explicit prompts such as *"I am a new C learner, facing issue (X). Do not give answers. Act as a socratic tutor and ask questions that prod me in the reight direction."*  and for the purpose of generating test cases.

### Detailed desriptions

#### Mandatory

This implementation hadnles the following specifier characters:
- char (%c)
- char */string (%s)
- int (%i/%d)
- unsigned int (%u)
- hex (%x/%X) (small and captial respecitvely)
- pointer (%p)

#### Bonus

As well as the following flags:
| Flag | Valid targets | Description |
| ---- | ------------- | ----------- |
| '\#' | %x/%X | Add 0x or 0X at the beginning of hex |
| ' ' (single space) | %d/%i | Add a space at the beginning of int/hex (only if positive in the case of int) |
| '+' | %d/%i | Add the sign at the beginning of int even if positive |
| '.' | %s/%d/%i/%u/%x/%X | Set the precision of the argument by the int that directly follows the flag; <ul><li>For %n/%i%x/%X; sets the minimum number of digits to be printed. If the number of digits is larger than specified precision, the number is not truncated. If the specified precision is larger, pad the remaining spaces with leading zeros.</li><li>For %s; truncate the string to the set precision. If the precision is larger than the length of the supplied string, this flag has no effect.</li>|
| '-' | %c/%s/%d/%i/%u/%x/%X/%p | Left justify the content of the argument (see minimum width below). By default without this flag, the printing is done right justified. |
| '0' | %d/%i/%u/%x/%X/%p | Fill the left paces resulting from the width (see minimum width below) with zeros. The flags '-' and '.' cancel the effects of this flag. |

**Minimum width**: Minimum width can be provided as an int to specify the minimum number of characters to be printed. In case the width was smaller than the actual length of the argument's content or its precision, the content is not truncated.

The format of the specifier string is as follows:
```
%[flag][width][.precision][specifier character]
```