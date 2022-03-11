/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:26:42 by nchennaf          #+#    #+#             */
/*   Updated: 2021/10/18 15:32:58 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t size)
{
	size_t	i;
	char	*ptr;

	ptr = b;
	i = 0;
	while (i < size)
	{
		ptr[i] = c;
		i++;
	}
	return (ptr);
}
