/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:38:16 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/05 20:34:22 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	sum;

	sum = count * size;
	ptr = (char *)malloc(sum);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, sum);
	return (ptr);
}
