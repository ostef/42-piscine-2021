# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soumanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 22:59:10 by soumanso          #+#    #+#              #
#    Updated: 2021/09/21 21:37:15 by soumanso         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= ft_tail
GCC_FLAGS	= -Wall -Wextra -Werror
SRC_FILES	= ./ft_tail.c ./ft_atoi.c ./ft_print.c ./ft_string.c

${NAME}: ${SRC_FILES}
	gcc ${GCC_FLAGS} ${SRC_FILES} -o ${NAME}

all: ${NAME}

clean:

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re ${NAME}
