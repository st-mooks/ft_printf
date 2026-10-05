NAME:= libftprintf.a
CC:= cc
CFLAGS:= -Wall -Werror -Wextra
SOURCES:= 
OBJECTS:= ${SOURCES:.c=.o}
LIBFT:= libft.h
HEADER:= libprintf.h
all: ${NAME}
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
${NAME}: ${OBJECTS}
	ar r $@ $^
clean:
	rm ${OBJECTS}
fclean: clean
	rm ${NAME}
re: fclean all
.PHONY: all clean fclean re
