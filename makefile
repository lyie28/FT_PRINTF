SRCS = $(wildcard sources/*.c) ./ft_printf.c ./ft_printf_two.c

OBJS = ${SRCS:.c=.o}

INCLUDES = ./includes

NAME = libftprintf.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}
			
$(NAME) : ${OBJS}
		$ ar rc libftprintf.a ${OBJS}

all: ${NAME}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

