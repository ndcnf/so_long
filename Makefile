# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 15:43:45 by nchennaf          #+#    #+#              #
#    Updated: 2022/04/07 17:37:55 by nchennaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	CC
FLAGS =	-Wall -Wextra -Werror -g -fsanitize=address
NAME =	so_long
AR =	ar rcs
SRC =	so_long.c \
		init.c \
		errors.c \
		main.c \
		moves.c
DIR_FTPRINTF = ./ft_printf/
LIB_FTPRINTF = ftprintf
DIR_LIBFT = ./libft/
LIB_LIBFT = ft
DIR_GNL = ./get_next_line/
LIB_GNL = gnl

OBJ =	${SRC:.c=.o}

all:	${NAME}

%.o:	%.c
		${CC} ${FLAGS} -Imlx -c $< -o $@
${NAME}:	${OBJ}
		${MAKE} -C ${DIR_FTPRINTF}
		${MAKE} -C ${DIR_LIBFT}
		${MAKE} -C ${DIR_GNL}
		${CC} ${OBJ} ${FLAGS} \
		-L${DIR_FTPRINTF} -l${LIB_FTPRINTF} \
		-L${DIR_LIBFT} -l${LIB_LIBFT} \
		-L${DIR_GNL} -l${LIB_GNL} \
		-Lmlx -lmlx \
		-framework OpenGL -framework AppKit -o ${NAME}
exec:	all
		./so_long
norm:	all
		norminette ${SRC} so_long.h
clean:
			rm -rf ${OBJ}
			${MAKE} -C ${DIR_LIBFT} clean
			${MAKE} -C ${DIR_FTPRINTF} clean
			${MAKE} -C ${DIR_GNL} clean

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean
