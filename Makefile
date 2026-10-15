NAME:= libftprintf.a
CC:= cc
CFLAGS:= -Wall -Werror -Wextra
PRINTF_PATH:= ../ft_printf
LIBFT_PATH:= ./libft
LIBFT:= ${LIBFT_PATH}/libft.a
SOURCES:=	${PRINTF_PATH}/print_char.c\
			${PRINTF_PATH}/print_str.c\
			${PRINTF_PATH}/print_int.c\
			${PRINTF_PATH}/print_uint.c\
			${PRINTF_PATH}/print_hex.c\
			${PRINTF_PATH}/print_ptr.c\
			${PRINTF_PATH}/utils_f_str.c\
			${PRINTF_PATH}/utils_format_props.c\
			${PRINTF_PATH}/utils_print.c\
			${PRINTF_PATH}/utils_numeric.c\
			${PRINTF_PATH}/utils_misc.c\
			${PRINTF_PATH}/ft_printf.c
OBJECTS:= 	${SOURCES:.c=.o}
all: ${NAME}
${NAME}: ${OBJECTS} ${LIBFT}
	ar r $@ ${OBJECTS}
	printf "OPEN ${LIBFT}\nADDLIB ${NAME}\nSAVE\nEND\n" | ar -M
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
${LIBFT}:
	make -C ${LIBFT_PATH}
clean:
	rm -f ${OBJECTS}
	make -C ${LIBFT_PATH} clean
fclean: clean
	rm -f ${NAME}
re: fclean all
.PHONY: all clean fclean re
