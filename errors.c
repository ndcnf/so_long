/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nadia <Nadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:13:24 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/10 11:18:24 by Nadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CHANGER HEADER !!!

#include	"so_long.h"

void	errorminator(char *s)
{
	ft_printf(ERROR);
	ft_printf(s);
	exit(EXIT_FAILURE);
}

void	check_items(t_board *bd)
{
	if (bd->itm->c <= 0)
		errorminator(ERR_COLL);
	if (bd->itm->e != 1)
		errorminator(ERR_EXIT);
	if (bd->itm->zero <= 0)
		errorminator(ERR_GRD);
	if (bd->itm->p != 1)
		errorminator(ERR_PLYR);
}

void	check_walls(t_board *bd)
{
	int	i;
	int	wall_cnt;
	int	real_cnt;

	i = -1;
	real_cnt = 0;
	wall_cnt = (bd->map.x_len - 1 + bd->map.y_len - 1) * 2;
	if (!bd->itm->one)
		errorminator(ERR_WLL);
	while (bd->map.map2d[0][++i] == '1')
		real_cnt++;
	i = -1;
	while (bd->map.map2d[bd->map.y_len - 1][++i] == '1')
		real_cnt++;
	i = -1;
	while (bd->map.map2d[++i][0] == '1' && i < bd->map.y_len - 1)
		real_cnt++;
	i = -1;
	while (bd->map.map2d[++i][bd->map.x_len - 2] == '1'
		&& i < bd->map.y_len - 1)
		real_cnt++;
	if (wall_cnt != real_cnt)
		errorminator(ERR_WLL);
}

void	check_args(int argc)
{
	if (argc != 2)
		errorminator(ERR_ARG);
}
