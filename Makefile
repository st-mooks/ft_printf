# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/20 10:57:47 by mbadarin          #+#    #+#              #
#    Updated: 2026/10/20 11:00:08 by mbadarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ft_printf's makefile
NAME:= libftprintf.a
CC:= cc
CFLAGS:= -Wall -Werror -Wextra
PRINTF_PATH:= .
LIBFT_PATH:= ./libft
LIBFT:= ${LIBFT_PATH}/libft.a
SOURCES:=	${PRINTF_PATH}/utils_print.c\
			${PRINTF_PATH}/utils_numeric.c\
			${PRINTF_PATH}/utils_char_str.c\
			${PRINTF_PATH}/utils_args.c\
			${PRINTF_PATH}/ft_printf.c
OBJECTS:= 	${SOURCES:.c=.o}
HEADER:= ft_printf.h
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
