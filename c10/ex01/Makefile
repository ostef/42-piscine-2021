# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soumanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 22:59:10 by soumanso          #+#    #+#              #
#    Updated: 2021/09/14 15:40:59 by soumanso         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= ft_cat
GCC_FLAGS	= -Wall -Wextra -Werror
SRC_FILES	= ./ft_cat.c ./ft_string.c

${NAME}: ${SRC_FILES}
	gcc ${GCC_FLAGS} ${SRC_FILES} -o ${NAME}

all: ${NAME}

clean:

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re ${NAME}
