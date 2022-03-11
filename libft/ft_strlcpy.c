/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:37:21 by nchennaf          #+#    #+#             */
/*   Updated: 2021/10/22 16:26:01 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* -------------------------------------------------------------------------*

The function copies up to (dstsize - 1) characters from the NUL-terminated
string arc to dst, NUL-terminating the result.

EXAMPLE
dstsize = 3;

*src		A	B	C	D	\0
			|	|	|
*dst		A	B	\0

return = 4 (len of src);
 
*---------------------------------------------------------------------------*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*ptr_src;

	ptr_src = (char *)src;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(ptr_src));
	while (ptr_src[i] && i < (dstsize - 1))
	{
		dst[i] = ptr_src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(ptr_src));
}
