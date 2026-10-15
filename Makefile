NAME:= libftprintf.a
CC:= cc
CFLAGS:= -Wall -Werror -Wextra
PRINTF_PATH:= ../ft_printf
LIBFT_PATH:= ../libft
SOURCES:= 	${PRINTF_PATH}/ft_printf.c\
			${PRINTF_PATH}/print_char.c\
			${PRINTF_PATH}/print_str.c\
			${PRINTF_PATH}/print_int.c\
			${PRINTF_PATH}/print_uint.c\
			${PRINTF_PATH}/print_hex.c\
			${PRINTF_PATH}/print_ptr.c\
			${PRINTF_PATH}/f_str.c\
			${PRINTF_PATH}/utils_format_props.c\
			${PRINTF_PATH}/utils_print.c\
			${PRINTF_PATH}/utils_numeric.c
OBJECTS:= ${SOURCES:.c=.o}
HEADER:= ${PRINTF_PATH}/ft_printf.h
LIBFT:= ${PRINTF_PATH}/libft.a
all: ${NAME} ${LIBFT}
${NAME}: ${OBJECTS} ${HEADER}
	ar r $@ $^
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
${LIBFT}:
	make -f ${LIBFT_PATH}/Makefile
	make -f ${LIBFT_PATH}/Makefile clean
clean:
	rm -f ${OBJECTS}
fclean: clean
	rm -f ${NAME} ${LIBFT}
re: fclean all
.PHONY: all clean fclean re
