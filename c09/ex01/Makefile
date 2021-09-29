# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soumanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 14:40:50 by soumanso          #+#    #+#              #
#    Updated: 2021/09/21 21:37:47 by soumanso         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
INCLUDE_DIRS=./includes/
SRC_FILES = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJ_FILES = ${SRC_FILES:.c=.o}

.c.o:
	gcc ${CFLAGS} -c -I ${INCLUDE_DIRS} $< -o ${<:.c=.o}
	
${NAME}: ${OBJ_FILES}
	ar rc ${NAME} ${OBJ_FILES}

all: ${NAME}

clean:
	rm -f ${OBJ_FILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
