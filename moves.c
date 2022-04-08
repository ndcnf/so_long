/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nadia <Nadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:59:54 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/08 20:11:37 by Nadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	move(t_board *bd, int direction)
{
	int	future_x;
	int	future_y;

	pathfinder(bd, IMG_GRD2, bd->p1->x, bd->p1->y);
	if (direction == KEY_UP)
	{
		future_y = bd->p1->y - IMG_PXL;
		future_x = bd->p1->x;
		if(check_move(bd, future_x, future_y))
		{
			bd->map.y = bd->p1->y - IMG_PXL;
			bd->p1->y = bd->map.y;
		}
	}
	else if (direction == KEY_DWN)
	{
		future_y = bd->p1->y + IMG_PXL;
		future_x = bd->p1->x;
		if(check_move(bd, future_x, future_y))
		{
			bd->map.y = bd->p1->y + IMG_PXL;
			bd->p1->y = bd->map.y;
		}
	}
	else if (direction == KEY_LFT)
	{
		future_x = bd->p1->x - IMG_PXL;
		future_y = bd->p1->y;
		if(check_move(bd, future_x, future_y))
		{
			bd->map.x = bd->p1->x - IMG_PXL;
			bd->p1->x = bd->map.x;
		}
	}
	else if (direction == KEY_RGT)
	{
		future_x = bd->p1->x + IMG_PXL;
		future_y = bd->p1->y;
		if(check_move(bd, future_x, future_y))
		{
			bd->map.x = bd->p1->x + IMG_PXL;
			bd->p1->cd_x = bd->map.x / IMG_PXL;
			bd->p1->x = bd->map.x;
		}
	}
	else
		errorminator(ERR_WTF);
	pathfinder(bd, IMG_P1, bd->p1->x, bd->p1->y);
	//ft_printf("you are here : (%d;%d)\n", bd->p1->x, bd->p1->y);
	//ft_printf("coord en humain (%d;%d)\n", (bd->p1->x/IMG_PXL), (bd->p1->y/IMG_PXL));
}

int	check_move(t_board *bd, int move_x, int move_y)
{
	char	cd;

	cd = bd->map.map2d[move_y/IMG_PXL][move_x/IMG_PXL];
	if	(bd->itm->c != 0 && cd == 'E')
	{
		return (0);
	}
	else if (cd != '1')
	{
		if(cd == 'C')
			bd->itm->c--;
		if (bd->itm->c == 0)
			pathfinder(bd, IMG_E2, bd->itm->x_e, bd->itm->y_e);
		if (bd->itm->c == 0 && cd == 'E')
			ft_printf("BRAVO, t'es sortie\n");

		bd->p1->cd_x = bd->p1->x/IMG_PXL;
		bd->p1->cd_y = bd->p1->y/IMG_PXL;
		ft_printf("steps: %d\n\n", ++bd->p1->steps);	
		return(1);
	}
	else
		return(0);
}
