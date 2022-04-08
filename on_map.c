/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nadia <Nadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:53:17 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/09 00:05:52 by Nadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//CHANGER LE HEADER !!!!!

void	define_player(t_board *bd)
{
	bd->itm->p++;
	bd->p1->x = bd->map.x;
	bd->p1->y = bd->map.y;
	bd->p1->cd_x = bd->p1->x / IMG_PXL;
	bd->p1->cd_y = bd->p1->y / IMG_PXL;
}
