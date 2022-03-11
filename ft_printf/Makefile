# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 17:46:37 by nchennaf          #+#    #+#              #
#    Updated: 2022/03/11 13:15:13 by nchennaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra
NAME = libftprintf.a
AR = ar rcs
SRC =	ft_printf.c \
		ft_putchar_fd_int.c \
		ft_putstr_fd_int.c \
		ft_putnbr_fd_sizet.c \
		ft_hexa.c \
		ft_putunbr_fd.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean
