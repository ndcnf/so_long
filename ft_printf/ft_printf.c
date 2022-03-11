/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:44:50 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/20 17:57:43 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choice(const char *s, int i, va_list args)
{
	if (s[i] == 's')
		return (ft_putstr_fd_int(va_arg(args, char *), 1));
	else if (s[i] == 'c')
		return (ft_putchar_fd_int((char)va_arg(args, int), 1));
	else if (s[i] == 'd' || s[i] == 'i')
		return (ft_putnbr_fd_sizet(va_arg(args, int), 1));
	else if (s[i] == '%')
		return (ft_putchar_fd_int('%', 1));
	else if (s[i] == 'x' || s[i] == 'X')
		return (ft_hexa(va_arg(args, unsigned int), s[i], 1));
	else if (s[i] == 'p')
	{
		ft_putstr_fd_int("0x", 1);
		return (ft_hexa((unsigned long)va_arg(args, void *), 'x', 1) + 2);
	}
	else if (s[i] == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1));
	else
	{
		ft_putchar_fd_int(s[i - 1], 1);
		return (ft_putchar_fd_int(s[i], 1) + 1);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		nbr;
	int		i;

	if (!s)
		return (0);
	va_start(args, s);
	nbr = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			nbr += ft_putchar_fd_int(s[i], 1);
		else
			nbr += ft_choice(s, ++i, args);
		i++;
	}
	va_end(args);
	return (nbr);
}
