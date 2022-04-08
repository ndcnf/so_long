/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nadia <Nadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:59:54 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/08 19:47:52 by Nadia            ###   ########.fr       */
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
	bd->p1->steps++;
	//ft_printf("you are here : (%d;%d)\n", bd->p1->x, bd->p1->y);
	//ft_printf("coord en humain (%d;%d)\n", (bd->p1->x/IMG_PXL), (bd->p1->y/IMG_PXL));
	//ft_printf("p1.x(mod)x_len = %d\n", (bd->p1->x%bd->map.x_len));
	ft_printf("steps: %d\n\n", bd->p1->steps);
	//ft_printf("map 2d %c [%d][%d]\n", bd->map.map2d[bd->p1->cd_y][bd->p1->cd_x], bd->p1->cd_x, bd->p1->cd_y);
}

int	check_move(t_board *bd, int move_x, int move_y)
{

	//bd->p1->cd_x = bd->p1->x/IMG_PXL;
	//bd->p1->cd_y = bd->p1->y/IMG_PXL;

	if (bd->map.map2d[move_y/IMG_PXL][move_x/IMG_PXL] != '1')
	{
		return(1);
	}
	else
		return(0);
}
