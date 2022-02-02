CC =	CC
FLAGS =	-Werror -Wextra -Wall
NAME =	so_long.a
AR =	ar rcs
SRC =	#liste des fichiers \
		# a inclure ici
OBJ =	${SRC:.c=.o}

all:	${NAME}

%.o:	%.c
		$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
${NAME}:	${OBJ}
		$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
			rm -rf *.o

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean