/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:57:20 by nchennaf          #+#    #+#             */
/*   Updated: 2022/03/09 14:37:17 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"

typedef struct s_map
{
	int		x;
	int		y;
} t_map;

typedef struct s_sprite
{
	int		w;
	int		h;
	char	*path;
} t_sprite;

typedef struct s_board
{
	t_map		map;
	t_sprite	spr;
	void		*mlx;
	void		*img;
	void		*win;
	int			w; //win_w
	int			h; //win_h
} t_board;

int	key_on(int key, void *param);

#endif
