# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soumanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 22:59:10 by soumanso          #+#    #+#              #
#    Updated: 2021/09/14 15:40:18 by soumanso         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= ft_hexdump
GCC_FLAGS	= -Wall -Wextra -Werror
SRC_FILES	= ./ft_hexdump.c ./ft_file.c ./ft_print.c ./ft_string.c

${NAME}: ${OBJ_FILES}
	gcc ${GCC_FLAGS} ${SRC_FILES} -o ${NAME}

all: ${NAME}

clean:

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re ${NAME}
