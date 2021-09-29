# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soumanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 02:20:45 by soumanso          #+#    #+#              #
#    Updated: 2021/09/13 02:36:25 by soumanso         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		:= do-op
CFLAGS		:= -Wall -Wextra -Werror
SRC_FILES	:= ft_doop.c ft_print.c ft_string.c ft_op.c

${NAME}:	${SRC_FILES}
	gcc ${CFLAGS} ${SRC_FILES} -o ${NAME}

all:	${NAME}

clean:

fclean:	clean
	rm ${NAME}

re:		fclean all

.PHONY:
	all fclean clean re ${NAME}
