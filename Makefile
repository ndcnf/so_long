CC =	CC
FLAGS =	-Werror -Wextra -Wall
NAME =	so_long.a
AR =	ar rcs
SRC =	#liste des fichiers \
		# a inclure ici
OBJ =	${SRC:.c=.o}

all:	${NAME}

%.o:	%.c
		${CC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJ}
			${AR} ${NAME} ${OBJ}

clean:
			rm -rf *.o

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean