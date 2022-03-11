/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:31:33 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/17 13:44:08 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putunbr_fd(unsigned int n, int fd)
{
	size_t	count;

	count = 0;
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd_int(n + '0', fd);
		return (1);
	}
	else if (n >= 0)
	{
		count = ft_putnbr_fd_sizet(n / 10, fd);
		ft_putchar_fd_int((n % 10) + '0', fd);
		return (count + 1);
	}
	else if (n < 0)
		ft_putnbr_fd_sizet(n, fd);
	return (0);
}
