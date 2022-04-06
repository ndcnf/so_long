/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:36:28 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/06 12:52:12 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_items(t_board *bd)
{
	bd->itm.p = 0;
	bd->itm.e = 0;
	bd->itm.one = 0;
	bd->itm.zero = 0;
	bd->itm.c = 0;
	bd->p1.steps = 0;
}

void	init_map(t_board *bd)
{
	bd->h = bd->map.y_len * IMG_PXL;
	ft_printf("cnt : %d\n", bd->map.x_len);
	bd->w = (bd->map.x_len - 1) * IMG_PXL;
	ft_printf("i : %d\n", bd->map.y_len);
	bd->mlx = mlx_init();
	bd->win = mlx_new_window(bd->mlx, bd->w, bd->h, WIN_TITLE);
	bd->map.x = 0;
	bd->map.y = 0;
}
