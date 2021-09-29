# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soumanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 22:03:36 by soumanso          #+#    #+#              #
#    Updated: 2021/09/14 15:41:10 by soumanso         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= ft_display_file
GCC_FLAGS	= -Wall -Wextra -Werror
SRC_FILES	= ./ft_display_file.c

${NAME}: ${SRC_FILES}
	gcc ${GCC_FLAGS} ${SRC_FILES} -o ${NAME}

all: ${NAME}

clean:

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re ${NAME}
