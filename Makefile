# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 15:43:45 by nchennaf          #+#    #+#              #
#    Updated: 2022/02/15 15:43:45 by nchennaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	CC
FLAGS =	-Werror -Wextra -Wall -g
NAME =	so_long
AR =	ar rcs
SRC =	so_long.c
OBJ =	${SRC:.c=.o}

all:	${NAME}

%.o:	%.c
		${CC} ${FLAGS} -Imlx -c $< -o $@
${NAME}:	${OBJ}
		${CC} ${OBJ} ${FLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
exec:	all
		./so_long
clean:
			rm -rf ${OBJ}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean
