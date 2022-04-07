/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:59:54 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/07 11:22:38 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	move(t_board *bd, int direction)
{
	//verifier si le move est legal
	//verifier si collectible, alors decrementer le compteur de collectibles (bd->itm.c--)

	pathfinder(bd, IMG_GRD2, bd->p1->x, bd->p1->y);
	if (direction == KEY_UP)
	{
		bd->map->y = bd->p1->y - IMG_PXL;
		bd->p1->y = bd->map->y;
	}
	else if (direction == KEY_DWN)
	{
		bd->map->y = bd->p1->y + IMG_PXL;
		bd->p1->y = bd->map->y;
	}
	else if (direction == KEY_LFT)
	{
		bd->map->x = bd->p1->x - IMG_PXL;
		bd->p1->x = bd->map->x;
	}
	else if (direction == KEY_RGT)
	{
		bd->map->x = bd->p1->x + IMG_PXL;
		bd->p1->x = bd->map->x;
	}
	else
		errorminator(ERR_WTF);
	pathfinder(bd, IMG_P2, bd->p1->x, bd->p1->y);
	bd->p1->steps++;
	ft_printf("steps: %d\n", bd->p1->steps);
}
