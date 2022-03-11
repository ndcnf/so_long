/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:29:57 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/05 19:33:22 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_cnt(int n)
{
	int			count;
	long int	n_val;

	count = 0;
	n_val = (long)n;
	if (n < 0)
	{
		count++;
		n_val = -n_val;
	}
	if (n_val == 0)
		count++;
	while (n_val > 0)
	{	
		count++;
		n_val /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			cnt;
	long int	n_val;

	cnt = char_cnt(n);
	nbr = (char *)malloc(sizeof(char) * (cnt + 1));
	if (nbr == NULL || cnt == 0)
		return (NULL);
	n_val = (long)n;
	nbr[cnt] = '\0';
	if (n_val < 0)
	{
		nbr[0] = '-';
		n_val = -n_val;
	}
	else if (n_val == 0)
		nbr[cnt - 1] = '0';
	while (n_val > 0)
	{
		nbr[cnt - 1] = (n_val % 10) + '0';
		n_val /= 10;
		cnt--;
	}
	return (nbr);
}
