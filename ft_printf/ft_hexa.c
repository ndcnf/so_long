/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:48:06 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/19 18:01:34 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long n, char c, int fd)
{
	int		cnt;
	char	*hexarray_lwr;
	char	*hexarray_upr;

	hexarray_lwr = "0123456789abcdef";
	hexarray_upr = "0123456789ABCDEF";
	cnt = 0;
	if (n >= 0 && n < 16)
	{
		if (c == 'x')
			return (write(fd, &hexarray_lwr[n % 16], 1));
		else
			return (write(fd, &hexarray_upr[n % 16], 1));
	}
	else
	{
		cnt += ft_hexa(n / 16, c, fd);
		if (c == 'x')
			return (write(fd, &hexarray_lwr[n % 16], 1) + cnt);
		else
			return (write(fd, &hexarray_upr[n % 16], 1) + cnt);
	}
	return (cnt);
}
