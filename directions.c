/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nadia <Nadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:54:33 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/10 12:12:14 by Nadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_board *bd, int future_x, int future_y)
{
	future_y = bd->p1->y - IMG_PXL;
	future_x = bd->p1->x;
	if (check_move(bd, future_x, future_y))
	{
		bd->map.y = bd->p1->y - IMG_PXL;
		bd->p1->y = bd->map.y;
	}
}

void	go_down(t_board *bd, int future_x, int future_y)
{
	future_y = bd->p1->y + IMG_PXL;
	future_x = bd->p1->x;
	if (check_move(bd, future_x, future_y))
	{
		bd->map.y = bd->p1->y + IMG_PXL;
		bd->p1->y = bd->map.y;
	}
}

void	go_left(t_board *bd, int future_x, int future_y)
{
	future_x = bd->p1->x - IMG_PXL;
	future_y = bd->p1->y;
	if (check_move(bd, future_x, future_y))
	{
		bd->map.x = bd->p1->x - IMG_PXL;
		bd->p1->x = bd->map.x;
	}
}

void	go_right(t_board *bd, int future_x, int future_y)
{
	future_x = bd->p1->x + IMG_PXL;
	future_y = bd->p1->y;
	if (check_move(bd, future_x, future_y))
	{
		bd->map.x = bd->p1->x + IMG_PXL;
		bd->p1->cd_x = bd->map.x / IMG_PXL;
		bd->p1->x = bd->map.x;
	}
}
