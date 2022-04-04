/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:13:24 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/04 17:35:05 by nchennaf         ###   ########.fr       */
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
	//check_walls(bd);
}

// verifier que la carte est entouree de murs.
// peut-etre voir apres la gestion des deplacements pour une meilleure idee
// ne fonctionne actuellement pas. Lance le jeu en arriere plan, sans afficher. Boucle infinie et/ou mauvaises conditions
void	check_walls(t_board *bd)
{
	int	i;

	i = 0;
	ft_printf("check AVANT itm.one : %d\n", bd->itm.one);
	ft_printf("check AVANT map.content[i] : %c - i : %d\n", bd->map.content[i], i);
	if (!bd->itm.one)
		errorminator(ERR_WLL);
	while (bd->map.content[i] != '\n')
		if (bd->map.content[i] != '1')
		{
			ft_printf("debut : %c\n", bd->map.content[i]);
			errorminator(ERR_WLL);
		}
		ft_printf("debut HB : %c\n", bd->map.content[i]);
		i++;
	i = bd->map.x_len;
	while (bd->map.content[i--] != '\n')
		if (bd->map.content[i] != '1')
		{
			ft_printf("fin : %c\n", bd->map.content[i]);
			errorminator(ERR_WLL);
		}
		ft_printf("fin HB : %c\n", bd->map.content[i]);
}

void	check_args(int argc)
{
	if (argc != 2)
		errorminator(ERR_ARG);
}
