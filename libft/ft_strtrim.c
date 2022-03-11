/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:56:04 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/05 12:24:03 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Example:
 * s1		"....,.,,..,,,.,Hell,,.,.,o.,.,.,,.,."
 * set		".,"
 * return:	"Hell,,.,.,o"
 * ____________________________________________________*/

static char	*first(char *str, char *c)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != c[j] && c[j])
			j++;
		if (!c[j])
			return (&str[i]);
		else
			i++;
	}
	return (0);
}

static char	*last(char *str, char *c)
{
	int	i;
	int	j;

	i = (ft_strlen(str) - 1);
	while (i >= 0)
	{
		j = 0;
		while (str[i] != c[j] && c[j])
			j++;
		if (!c[j])
			return (&str[i]);
		else
			i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*lean;
	char	*bgn;
	char	*end;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	bgn = first((char *)s1, (char *)set);
	end = last((char *)s1, (char *)set);
	if (!bgn && !end)
		return (ft_strdup(""));
	lean = (char *)malloc(sizeof(char) * (end - bgn + 2));
	if (lean == NULL)
		return (NULL);
	i = 0;
	while (i < end - bgn + 1)
	{
		lean[i] = bgn[i];
		i++;
	}
	lean[i] = '\0';
	return (lean);
}
