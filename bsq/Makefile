# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 15:59:34 by cben-bar          #+#    #+#              #
#    Updated: 2021/09/21 18:00:48 by soumanso         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= bsq
SRCS		= ./ft_bsq.c ./ft_file.c ./ft_parse.c ./ft_print.c ./ft_misc.c ./ft_map.c
OBJS		= ${SRCS:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra 
RM			= rm -f

${NAME}:	${OBJS}
			${CC} -c ${CFLAGS} ${SRCS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}

.PHONY:		all clean fclen re ${NAME}
