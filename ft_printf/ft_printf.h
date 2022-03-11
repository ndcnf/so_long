/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:41:22 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/19 19:54:06 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ft_putchar_fd_int(char c, int fd);
int		ft_putstr_fd_int(char *s, int fd);
size_t	ft_putnbr_fd_sizet(int n, int fd);
size_t	ft_putunbr_fd(unsigned int n, int fd);
int		ft_hexa(unsigned long n, char c, int fd);

#endif
