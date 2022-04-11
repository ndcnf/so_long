/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:36:28 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/11 11:12:26 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allowance(t_board *bd)
{
	bd->itm = malloc(sizeof(t_items));
	if (!bd->itm)
		errorminator(RKO);
	bd->p1 = malloc(sizeof(t_player));
	if (!bd->p1)
		errorminator(RKO);
	bd->spr = malloc(sizeof(t_sprite));
	if (!bd->spr)
		errorminator(RKO);
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
}

void	init_map(t_board *bd)
{
	bd->h = bd->map.y_len * IMG_PXL;
	bd->w = (bd->map.x_len - 1) * IMG_PXL;
	bd->mlx = mlx_init();
	bd->win = mlx_new_window(bd->mlx, bd->w, bd->h, WIN_TITLE);
	bd->map.x = 0;
	bd->map.y = 0;
}

void	process_map(t_board *bd, int fd)
{
	char	*tempura;
	char	*gnl;

	bd->map.y_len = 0;
	bd->map.x_len = 0;
	gnl = get_next_line(fd);
	bd->map.content = ft_strdup("");
	while (gnl != NULL)
	{
		if (bd->map.x_len && bd->map.x_len != (int)ft_strlen(gnl))
			errorminator(ERR_SHP);
		bd->map.x_len = (int)ft_strlen(gnl);
		tempura = bd->map.content;
		bd->map.content = ft_strjoin(bd->map.content, gnl);
		free(tempura);
		free(gnl);
		gnl = get_next_line(fd);
		bd->map.y_len++;
	}
}

void	render_map(t_board *bd)
{
	while (bd->map.y <= bd->h)
	{
		while (bd->map.x <= bd->w)
		{
			item_on_map(bd);
			bd->map.x += IMG_PXL;
		}
		bd->map.y += IMG_PXL;
		bd->map.x = 0;
	}
}
