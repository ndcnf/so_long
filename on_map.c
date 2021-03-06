/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:53:17 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/11 10:55:53 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	define_player(t_board *bd)
{
	pathfinder(bd, IMG_P1, bd->map.x, bd->map.y);
	bd->itm->p++;
	bd->p1->x = bd->map.x;
	bd->p1->y = bd->map.y;
	bd->p1->cd_x = bd->p1->x / IMG_PXL;
	bd->p1->cd_y = bd->p1->y / IMG_PXL;
}

void	define_walls(t_board *bd)
{
	pathfinder(bd, IMG_WLL2, bd->map.x, bd->map.y);
	bd->itm->one++;
}

void	hello_ground(t_board *bd)
{
	pathfinder(bd, IMG_GRD1, bd->map.x, bd->map.y);
	bd->itm->zero++;
}

void	define_collectibles(t_board *bd)
{
	pathfinder(bd, IMG_C, bd->map.x, bd->map.y);
	bd->itm->c++;
}

void	define_exit(t_board *bd)
{
	pathfinder(bd, IMG_E1, bd->map.x, bd->map.y);
	bd->itm->e++;
	bd->itm->x_e = bd->map.x;
	bd->itm->y_e = bd->map.y;
}
