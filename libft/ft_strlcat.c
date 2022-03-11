/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:41:13 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/05 20:31:28 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*-----------------------------------------------------------------------*
strlcat() appends string src to the end of dst.
It will append at most (dstsize - (strlen(dst) - 1)) characters.
It will then NUL-terminate, unless dstsize is 0 or the original dst string
was longer than dstsize.
*-----------------------------------------------------------------------*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	i = dst_len;
	j = 0;
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	while (src[j] && (i < (dstsize - 1)))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (src_len + dst_len);
}
