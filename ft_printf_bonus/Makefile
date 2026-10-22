# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/20 10:57:41 by mbadarin          #+#    #+#              #
#    Updated: 2026/10/22 12:00:56 by mbadarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libftprintf_bonus.a
CC:= cc
CFLAGS:= -Wall -Werror -Wextra
PRINTF_PATH:= .
LIBFT_PATH:= ../libft
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
			${PRINTF_PATH}/utils_build_str.c\
			${PRINTF_PATH}/utils_flags.c\
			${PRINTF_PATH}/utils_str.c\
			${PRINTF_PATH}/utils_arg_ptr.c\
			${PRINTF_PATH}/ft_printf_bonus.c
OBJECTS:= 	${SOURCES:.c=.o}
HEADER:= ft_printf_bonus.h
all: ${NAME} ${HEADER}
${NAME}: ${OBJECTS} ${LIBFT}
	ar r $@ ${OBJECTS}
	printf "OPEN ${NAME}\nADDLIB ${LIBFT}\nSAVE\nEND\n" | ar -M
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
${LIBFT}:
	make -C ${LIBFT_PATH}
clean:
	rm -f ${OBJECTS}
	make -C ${LIBFT_PATH} clean
fclean: clean
	rm -f ${NAME} ${LIBFT}
re: fclean all
.PHONY: all clean fclean re
