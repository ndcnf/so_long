/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:08:10 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/08 17:52:10 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	value;

	sign = 1;
	i = 0;
	value = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' || \
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		value = str[i] - '0';
		while (str[++i] >= '0' && str[i] <= '9' && str[i] != '\0')
		{
			value = (value * 10) + (str[i] - '0');
		}
	}
	return (value * sign);
}
