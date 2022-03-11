/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:36:02 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/05 10:55:22 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr_s;
	char	ptr_c;

	i = 0;
	ptr_s = (char *)s;
	ptr_c = (char)c;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (ptr_s[i] == ptr_c)
			return ((char *)&ptr_s[i]);
		i++;
	}
	return (NULL);
}
