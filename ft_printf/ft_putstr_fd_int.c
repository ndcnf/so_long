/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:31:09 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/17 13:46:34 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_int(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return (write(fd, "(null)", 6));
	i = 0;
	while (s[i])
	{
		ft_putchar_fd_int(s[i], fd);
		i++;
	}
	return (i);
}
