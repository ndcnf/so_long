/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:36:28 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/06 17:20:17 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allowance(t_board *bd)
{
	bd->itm = malloc(sizeof(t_items));
	bd->p1 = malloc(sizeof(t_player));
	bd->spr = malloc(sizeof(t_sprite));
}

void	init_items(t_board *bd)
{
	bd->itm->p = 0;
	bd->itm->e = 0;
	bd->itm->one = 0;
	bd->itm->zero = 0;
	bd->itm->c = 0;
	bd->p1->steps = 0;
	bd->p1->x = 0;
	bd->p1->y = 0;
	ft_printf("steps origin: %d\n", bd->p1->steps);
}

void	init_map(t_board *bd)
{
	//allowance(bd);
	bd->h = bd->map->y_len * IMG_PXL;
	ft_printf("cnt : %d\n", bd->map->x_len);
	bd->w = (bd->map->x_len - 1) * IMG_PXL;
	ft_printf("i : %d\n", bd->map->y_len);
	bd->mlx = mlx_init();

	bd->win = mlx_new_window(bd->mlx, bd->w, bd->h, WIN_TITLE);

	bd->map->x = 0;
	bd->map->y = 0;
}

void	read_map(t_board *bd)
{
	while (bd->map->y <= bd->h)
	{
		while (bd->map->x <= bd->w)
		{
			item_on_map(bd);
			bd->map->x += IMG_PXL;
		}
		bd->map->y += IMG_PXL;
		bd->map->x = 0;
	}
}
