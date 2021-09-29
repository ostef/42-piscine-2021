NAME = rush-02
GCC_FLAGS = -Wall -Wextra -Werror
SRC_FILES = ./ft_number.c\
			./ft_dict.c\
			./ft_dict_memory.c\
			./ft_parse.c\
			./ft_file.c\
			./ft_integer.c\
			./ft_print.c

${NAME}: ${SRC_FILES}
	gcc ${GCC_FLAGS} ${SRC_FILES} -o ${NAME}

all: ${NAME}

clean:

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: ${NAME} all clean fclean re
