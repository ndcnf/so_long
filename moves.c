/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:59:54 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/08 15:25:29 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	move(t_board *bd, int direction)
{
	int	may_i_move;

	may_i_move = 0;
	pathfinder(bd, IMG_GRD2, bd->p1->x, bd->p1->y);
	if (direction == KEY_UP)
	{
		may_i_move = bd->p1->y - IMG_PXL;
		if(check_move(bd, may_i_move))
		{
			bd->map->y = bd->p1->y - IMG_PXL;
			bd->p1->y = bd->map->y;
		}
	}
	else if (direction == KEY_DWN)
	{
		may_i_move = bd->p1->y + IMG_PXL;
		if(check_move(bd, may_i_move))
		{
			bd->map->y = bd->p1->y + IMG_PXL;
			bd->p1->y = bd->map->y;
		}
	}
	else if (direction == KEY_LFT)
	{
		may_i_move = bd->p1->x - IMG_PXL;
		if(check_move(bd, may_i_move))
		{
			bd->map->x = bd->p1->x - IMG_PXL;
			bd->p1->x = bd->map->x;
		}
	}
	else if (direction == KEY_RGT)
	{
		may_i_move = bd->p1->x + IMG_PXL;
		if(check_move(bd, may_i_move))
		{
			bd->map->x = bd->p1->x + IMG_PXL;
			bd->p1->x = bd->map->x;
		}
	}
	else
		errorminator(ERR_WTF);
	pathfinder(bd, IMG_P1, bd->p1->x, bd->p1->y);
	bd->p1->steps++;
	ft_printf("you are here : (%d;%d)\n", bd->p1->x, bd->p1->y);
	ft_printf("coord en humain (%d;%d)\n", (bd->p1->x/IMG_PXL), (bd->p1->y/IMG_PXL));
	ft_printf("p1.x(mod)x_len = %d\n", (bd->p1->x%bd->map->x_len));
	ft_printf("steps: %d\n\n", bd->p1->steps);
}

int	check_move(t_board *bd, int move)
{
	bd->p1->cd_x = bd->p1->x/IMG_PXL;
	bd->p1->cd_y = bd->p1->y/IMG_PXL;

	//ft_printf("operation : %d\n",(bd->p1->cd_y * (bd->map->x_len + 1)));
	ft_printf("y (%d) * x_len (%d + 1 : %d) = %d\n", bd->p1->cd_y, bd->map->x_len, (bd->map->x_len + 1), (bd->p1->cd_y * (bd->map->x_len + 1)));
	ft_printf("et donc : %d\n", (bd->p1->cd_y * (bd->map->x_len + 1) + bd->p1->cd_x));
	ft_printf("sous la map, ya ca : %d\n", (bd->map->content[(bd->p1->cd_y * (bd->map->x_len + 1) + bd->p1->cd_x)]));
	ft_printf("direction : %d\n\n", move);
	ft_printf("wololo : %s\n", bd->map->map2d[bd->p1->cd_x][bd->p1->cd_y]);
	//if (bd->map->content[(bd->p1->cd_y * bd->map->x_len + 1)
	//	+ (bd->p1->cd_x) + direction] == '1')

	//if (la case d apres n est pas un mur ou le coffre ferme)
		return(1);
	//else
	//	return(0);
}
