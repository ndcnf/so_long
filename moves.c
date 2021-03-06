/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:59:54 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/11 10:55:44 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	move(t_board *bd, int direction)
{
	int	future_x;
	int	future_y;

	future_x = 0;
	future_y = 0;
	pathfinder(bd, IMG_GRD2, bd->p1->x, bd->p1->y);
	if (direction == KEY_UP)
		go_up(bd, future_x, future_y);
	else if (direction == KEY_DWN)
		go_down(bd, future_x, future_y);
	else if (direction == KEY_LFT)
		go_left(bd, future_x, future_y);
	else if (direction == KEY_RGT)
		go_right(bd, future_x, future_y);
	else
		errorminator(ERR_WTF);
	pathfinder(bd, IMG_BOX, 0, 0);
	mlx_string_put(bd->mlx, bd->win, 6, 25, 0x0, ft_itoa(bd->p1->steps));
}

int	check_move(t_board *bd, int move_x, int move_y)
{
	char	cd;

	cd = ft_toupper(bd->map.map2d[move_y / IMG_PXL][move_x / IMG_PXL]);
	if (bd->itm->c != 0 && cd == 'E')
	{
		return (0);
	}
	else if (cd != '1')
	{
		if (cd == 'C')
		{
			bd->itm->c--;
			bd->map.map2d[move_y / IMG_PXL][move_x / IMG_PXL] = '0';
		}
		if (bd->itm->c == 0)
			pathfinder(bd, IMG_E2, bd->itm->x_e, bd->itm->y_e);
		if (bd->itm->c == 0 && cd == 'E')
			close_win();
		bd->p1->cd_x = bd->p1->x / IMG_PXL;
		bd->p1->cd_y = bd->p1->y / IMG_PXL;
		ft_printf("steps: %d\n", ++bd->p1->steps);
		return (1);
	}
	else
		return (0);
}

void	wololo(t_board *bd)
{
	char	**conv_map;
	int		x;
	int		y;
	int		i;

	i = 0;
	conv_map = malloc(bd->map.y_len * sizeof(int *));
	if (!conv_map)
		return ;
	y = 0;
	while (y < bd->map.y_len)
	{
		x = 0;
		conv_map[y] = malloc((bd->map.x_len - 1) * sizeof(int));
		if (!conv_map[y])
			return ;
		while (x < (bd->map.x_len - 1))
		{
			conv_map[y][x++] = bd->map.content[i];
			i++;
		}
		i++;
		y++;
	}
	bd->map.map2d = conv_map;
}
