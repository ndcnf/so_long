CC =	CC
FLAGS =	-Werror -Wextra -Wall
NAME =	so_long
AR =	ar rcs
SRC =	so_long.c
OBJ =	${SRC:.c=.o}

all:	${NAME}

%.o:	%.c
		${CC} ${FLAGS} -Imlx -c $< -o $@
${NAME}:	${OBJ}
		${CC} ${OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean
