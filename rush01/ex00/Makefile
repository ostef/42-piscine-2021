# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soumanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 13:20:45 by soumanso          #+#    #+#              #
#    Updated: 2021/09/12 20:13:59 by mverger          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		:= rush01
RM			:= rm -rf
CC			:= gcc
CFLAGS		:= -Werror -Wextra -Wall
CSRC		:=./ft_string.c ./ft_check.c ./ft_solve.c
COBJ		:= $(CSRC:.c=.o)
.SUFFIXES:
all:		$(NAME)
clean:
	$(RM) $(COBJ) $(BONUSOBJ)
fclean:		clean
	$(RM) $(NAME)
re:		fclean all
%.o:	%.c	ft_skyscraper.h
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): main.c	$(COBJ) ft_skyscraper.h
	$(CC) $(CFLAGS) -o $(NAME) main.c $(COBJ)
.PHONY:
		all fclean clean re
