/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:13:24 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/01 10:16:32 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	errorminator(char *s)
{
	ft_printf(ERROR);
	ft_printf(s);
	exit(EXIT_FAILURE);
}

void	check_items(t_board *bd)
{
	if (bd->itm.c <= 0)
		errorminator(ERR_COLL);
	if (bd->itm.e != 1)
		errorminator(ERR_EXIT);
	if (bd->itm.zero <= 0)
		errorminator(ERR_GRD);
	if (bd->itm.p != 1)
		errorminator(ERR_PLYR);
}

// verifier que la carte est entouree de murs.
// peut-etre voir apres la gestion des deplacements pour une meilleure idee
void	check_walls(t_board *bd)
{
	if (!bd->itm.one)
		errorminator(ERR_WLL);
}

void	check_args(int argc)
{
	if (argc != 2)
		errorminator(ERR_ARG);
}
