*This project has been created as part of the 42 curriculum by mbadarin.*

# LIBFT

## A 42 Amman Porject

### Description

A library conatinig my impliminations of several functions that do string, memory, and linked list manipulation.

### Instructions

Use the provided make file to create an archive containig the preprocessed object files:

- Create .o files and add them to libft.a archive file:
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

- Manual pages for each implemented function (if available).
- [Geeksforgeeks.org](https://www.geeksforgeeks.org)
- [Stackoverflow.com](https://www.stackoverflow.com)
- [Freebsd.org](https://man.freebsd.org/cgi/man.cgi)
- [Man7.org](https://www.man7.org/linux/man-pages/index.html)

Use of AI was limited, and mainly used with explicit prompts such as *"I am a new C learner, facing issue (X). Do not give answers. Act as a socratic tutor and ask questions that prod me in the reight direction."*

### Detailed desriptions

| ID | Function | Prototype | Return type/value | Description |
| -- | -------- | --------- | ----------------- | ----------- |
| 1 | ft_isalpha | int ft_isalpha(int c) | int: 1 if true, 0 if false | Checks if a character is a letter in the English alphabet (either upper and lower case). |
| 2 | ft_isdigit | int ft_isdigit(int c) | same as above | Checks if a character is a digit (0-9). |
| 3 | ft_isalnum | int ft_isalnum(int c) | same as above | Checks if a character is either a digit or a letter in the English alphabet. (Equivalent to ft_isalpha \|\| ft_isdigit). |
| 4 | ft_isascii | int ft_isascii(int c) | same as above | Checks if a character is a valid ASCII character (0-127 decimal). |
| 5 | ft_isprint | int ft_isprint(int c) | same as above | Checks if a character is a printable ASCII character (32-126 decimal). |
| 6 | ft_toupper | int ft_toupper(int c) | int | Converts a letter in the English alphabet to uppercase. |
| 7 | ft_tolower | int ft_tolower(int c) | int | converts  a letter in the English alphabet to lowercase. |
| 8 | ft_atoi | int ft_atoi(char \*nptr) | int | Converts the first section of a string into int. Skips the leading white spaces as defined by isspace. Reads exactly one sign character. Stops at the first non-digit character afterwards.|
| 9 | ft_itoa | char \*ft_itoa(int n) | char \* | Converts a given integer to a valid C string. |
| 10 | ft_strlen | size_t ft_strlen(const char \*str) | size_t | Returns the length of a given string. |
| 11 | ft_strlcpy | size_t ft_strlcpy(char \*dest, const char \*src, size_t size) | size_t: Length of *src* | Copies a maximum of *size - 1* characters from *src* to *dest*. The resulting string is a valid C string. *size* should be provided as the total buffer size of *dest* -including the trailing terminating character-. (compare to ft_memcpy below). |
| 12 | ft_strlcat | size_t ft_strlcat(char \*dest, const char \*src, size_t size) | size_t: Length of *dest* + length of *src* | Concatenates a maximum of *size - 1* character from *src* to the end of *dest*, overwriting *dest*'s terminating character. The resulting string is a valid C string. *size* should be provided as the total buffer size that will fit the resulting string -including the trailing terminating character-. |
| 13 | ft_strchr | char \*ft_strchr(char \*s, int c) | char \* | Finds the first instance of character *c* in string *s* and returns a pointer to that location, or (NULL) if none found. (compare to ft_strrchr, ft_memchar below). |
| 14 | ft_strrchr | char \*ft_strrchr(char \*s, int c) | cahr \* | Finds the last instance of character *c* in string *s* and returns a pointer to that location, or (NULL) if none found. (compare to ft_strchr above).
| 15 | ft_strnstr | char \*ft_strnstr(char \*big, char \*little, size_t len) | char \* | Finds the first occurance of the string *little* in the string *big* and returns a pointer to that location, or (NULL) if none found. |
| 16 | ft_strdup | char \*ft_strdup(const char \*s) | char \* | Creates a copy of *s* and returns its location in memory. |
| 17 | ft_split | char \*\*ft_split(const char \*s, char c) | char \*\*: List of split words | Splits *s* using the delimeter *c* and returns a list of the individual sub-strings. |
| 18 | ft_strjoin | char \*ft_strjoin(const char \*s1, const char \*s2) | char \*: Pointer to the joined string | Joins two strings (*s1* and *s2*) and retuns the location of the resulting string in memory. |
| 19 | ft_strncmp | int ft_strncmp(const char \*s1, const char \*s2, size_t n) | int: 0 if the strings are identical, the difference between the first differing characters otherwise | Compares two strings (*s1* and *s2*) up to the *n*th character. Returns (0) if the strings are identical, and the difference between the first differing characters otherwise. |
| 20 | ft_strtrim | char \*ft_strtrim(const char \*s1, const char \*set) | char \* | Trims the any occurances of a character contained in *set* from the start and end of *s1*. The search stops when a character outside *set* is encountered. |
| 21 | ft_striteri | void ft_striteri(char \*s, void (\*f)(unsigned int, char \*)) | N/A | Iterates over sting *s* and calls function *f* over each character. *f* takes the index of the character as well as the value of the character itself by address as parameters. |
| 22 | ft_strmapi | char \*ft_strmapi(const char \*s, char (\*f)(unsigned int, char)) | char \* | Takes sting *s*, Iterates over it and calls function *f* to each character and return a new string that reflects the changes made by the *f*. *f* takes the index of the character as well as the value of the character itself. |
| 23 | ft_substr | char \*ft_substr(cosnt char \*s, unsigned int start, size_t len) | char \* | Creates a substring of *s* that starts at index *start* and has a maximum length of *len* and returns it. |
| 24 | ft_putchar_fd | void ft_putchar_fd(char c, int fd) | N/A | Writes character *c* into file descriptor *fd*. |
| 25 | ft_putstr_fd | void ft_putstr_fd(char \*s, int fd) | N/A | Writes string *s* into file descriptior *fd*. |
| 26 | ft_putnbr_fd | void ft_putnbr_fd(int n, int fd) | N/A | Writes integer *n* into file descriptor *fd*. |
| 27 | ft_putendl_df | void ft_putendl_fd(char \*s, int fd) | N/A | Writes string *s* into file descriptor *fd*, followed by a newline into the same *fd*. |
| 28 | ft_memset | void \*ft_memset(void \*s, int c, size_t n) | void\* | Sets *n* bytes to *c* starting at address *s*. |
| 29 | ft_bzero | void ft_bzero(void \*s, size_t n) | N/A | Sets *n* bytes to (0) starting at address *s*. |
| 30 | ft_calloc | void \*ft_calloc(size_t nmemb, size_t size) | void \*: A pointer to the first member of the list | Allocates *nmemb* elements in memory, each with size *size*, and sets the value of each byte to (0). Returns a pointer to the address of the first member allocated. In case either *nmemb* or *size* is (0), returns a freeable pointer. In case *nmemb* \* *size* would overflow the size_t limit, reutrns (NULL). |
| 31 | ft_memchr | void \*ft_memchar(void \*s, int c, size_t n) | void \* | Finds the first instance of character *c* starting at address *s*, looking upto *n* bytes, and returns a pointer to that location, or (NULL) if none found. (compare to ft_strchr above). |
| 32 | ft_memcpy | void \*ft_memcpy(void \*dest, const void \*src, size_t n) | void \* | Copies *n* bytes from buffer *src* into buffer *dest*. Not safe in case of overlapping of buffers. |
| 33 | ft_memcmp | int ft_memcmp(void \*s1, void \*s2, sizt_t n) | int: 0 if the buffers are identical, the difference between the first differing bytes otherwise | Compares the first *n* bytes of buffer *s1* and buffer *s2*. Returns (0) if the buffers are identical, and the difference between the first differing bytes otherwise. |
| 34 | ft_memmove | void \*ft_memmove(void \*dest, const void \*src, size_t n) | void \* | Copies *n* bytes from buffer *src* into buffer *dest*. Checks for overlapping and adjusts copying direction to avoid overwriting the *src* before copying it. |
| 35 | ft_lstnew | t_list \*ft_lstnew(void \*content) | t_list \* | Creates a new t_list node and sets its content to *content*. |
| 36 | ft_lstsize | unisgned int ft_lst_size(t_list \*lst) | unsigned int: Number of nodes | Returns the total number of nodes in a t_list starting at *lst*. |
| 37 | ft_lstlast | t_list \*ft_lstlast(t_list \*lst) | t_list: Last element | Returns the last element of a t_list *lst*. |
| 38 | ft_lstadd_front | void ft_lstadd_front(t_list \*\*lst, t_list new) | N/A | Adds a new node *node* at the start of t_list *lst*. (Compare to ft_lstadd_back below). |
| 39 | ft_lstadd_back | void ft_lstadd_back(t_list \*\*lst, t_list new) | N/A | Adds a new node *node* at the end of t_list *lst*. (Compare to ft_lstadd_front above). |
| 40 | ft_lstdelone | void ft_lstdelone(t_list \*lst, void (\*del)(void \*)) | N/A | Deletes one node *lst* only and uses function *del* to delete its content. |
| 41 | ft_lstclear | void ft_lstclear(t_list \*\*lst, void (\*del)(void \*)) | N/A | Deletes node *lst* and all subsequent nodes, and uses function *del* to delete its contents. |
| 42 | ft_lstiter | void ft_lstiter(t_list \*lst, void(\*f)(void \*)) | N/A | Iterates over every node in t_list *lst* and calls function *f* over the content of each node. |
| 43 | ft_lstmap | t_list \*ft_lstmap(t_list \*lst, void \*(\*f)(void \*), void (\*d)(void \*)) | t_list | Iterates over t_list *lst*, calling function *f* over content of each node, which are used to create and return a new t_list. Function *d* is used to delete the contents of the newly created t_list if needed. |
