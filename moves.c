/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:59:54 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/06 18:38:23 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	move_up(t_board *bd)
{
	int	past_y;

	past_y = bd->p1->y;

	//verifier si le move est legal
	//verifier si collectible, alors decrementer le compteur de collectibles (bd->itm.c--)

	bd->spr->img = mlx_xpm_file_to_image(bd->mlx, IMG_GRD2, &bd->spr->w, &bd->spr->h);
	mlx_put_image_to_window(bd->mlx, bd->win, bd->spr->img, bd->p1->x, past_y);

	bd->map->y = bd->p1->y - IMG_PXL;
	bd->p1->y = bd->map->y;
	ft_printf("you are here: (%d;%d)\n", bd->p1->x, bd->p1->y);

	bd->spr->img = mlx_xpm_file_to_image(bd->mlx, IMG_P2, &bd->spr->w, &bd->spr->h);
	mlx_put_image_to_window(bd->mlx, bd->win, bd->spr->img, bd->p1->x, bd->p1->y);

	bd->p1->steps++;
	ft_printf("steps: %d\n", bd->p1->steps);
}

void	move_down(t_board *bd)
{
	int	past_y;

	past_y = bd->p1->y;

	//verifier si le move est legal
	//verifier si collectible, alors decrementer le compteur de collectibles (bd->itm.c--)

	bd->spr->img = mlx_xpm_file_to_image(bd->mlx, IMG_GRD2, &bd->spr->w, &bd->spr->h);
	mlx_put_image_to_window(bd->mlx, bd->win, bd->spr->img, bd->p1->x, past_y);

	bd->map->y = bd->p1->y + IMG_PXL;
	bd->p1->y = bd->map->y;
	ft_printf("you are here: (%d;%d)\n", bd->p1->x, bd->p1->y);

	bd->spr->img = mlx_xpm_file_to_image(bd->mlx, IMG_P2, &bd->spr->w, &bd->spr->h);
	mlx_put_image_to_window(bd->mlx, bd->win, bd->spr->img, bd->p1->x, bd->p1->y);

	bd->p1->steps++;
	ft_printf("steps: %d\n", bd->p1->steps);
}

void	move_left(t_board *bd)
{
	int	past_x;

	past_x = bd->p1->x;
	//verifier si le move est legal
	//verifier si collectible, alors decrementer le compteur de collectibles (bd->itm.c--)

	bd->spr->img = mlx_xpm_file_to_image(bd->mlx, IMG_GRD2, &bd->spr->w, &bd->spr->h);
	mlx_put_image_to_window(bd->mlx, bd->win, bd->spr->img, past_x, bd->p1->y);

	bd->map->x = bd->p1->x - IMG_PXL;
	bd->p1->x = bd->map->x;
	ft_printf("you are here: (%d;%d)\n", bd->p1->x, bd->p1->y);

	bd->spr->img = mlx_xpm_file_to_image(bd->mlx, IMG_P2, &bd->spr->w, &bd->spr->h);
	mlx_put_image_to_window(bd->mlx, bd->win, bd->spr->img, bd->p1->x, bd->p1->y);

	bd->p1->steps++;
	ft_printf("steps: %d\n", bd->p1->steps);
}

void	move_right(t_board *bd)
{
	int	past_x;

	past_x = bd->p1->x;
	//verifier si le move est legal
	//verifier si collectible, alors decrementer le compteur de collectibles (bd->itm.c--)

	bd->spr->img = mlx_xpm_file_to_image(bd->mlx, IMG_GRD2, &bd->spr->w, &bd->spr->h);
	mlx_put_image_to_window(bd->mlx, bd->win, bd->spr->img, past_x, bd->p1->y);

	bd->map->x = bd->p1->x + IMG_PXL;
	bd->p1->x = bd->map->x;
	ft_printf("you are here: (%d;%d)\n", bd->p1->x, bd->p1->y);

	bd->spr->img = mlx_xpm_file_to_image(bd->mlx, IMG_P2, &bd->spr->w, &bd->spr->h);
	mlx_put_image_to_window(bd->mlx, bd->win, bd->spr->img, bd->p1->x, bd->p1->y);

	bd->p1->steps++;
	ft_printf("steps: %d\n", bd->p1->steps);
}
