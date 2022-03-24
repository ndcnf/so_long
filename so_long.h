/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:57:20 by nchennaf          #+#    #+#             */
/*   Updated: 2022/03/24 16:33:51 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include "./mlx/mlx.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LFT 123
# define KEY_DWN 125
# define KEY_RGT 124
# define KEY_ESC 53

# define WIN_TITLE "The Untold Legend of Diana And the Evil Shrubs (working title)"
# define WIN_H 512
# define WIN_W 512
# define IMG_PXL 16 //vraiment utile ou redondant ?

# define IMG_P1 "./sprites/blob01.xpm"
# define IMG_P2 "./sprites/darkJunimo.xpm"
# define IMG_E "./sprites/heart00.xpm"
# define IMG_C "./sprites/fruit00.xpm"
# define IMG_WLL1 "./sprites/shrub00.xpm"
# define IMG_WLL2 "./sprites/shrub01.xpm"
# define IMG_GRD1 "./sprites/ground00.xpm"
# define IMG_GRD2 "./sprites/ground01.xpm"

# define ERROR "Error\n"
# define ERR_ARG "Nombre d'arguments invalide\n"
# define ERR_FD "Erreur avec le descripteur de fichiers\n"

/********************************************
|	Manages the current coordinates			|
********************************************/
typedef struct s_map
{
	int		x;
	int		y;
}	t_map;

typedef struct s_sprite
{
	int		w;
	int		h;
	void	*img;
	//char	*path;
}	t_sprite;

/********************************************
|	Manages the game board					|
|	Includes the map and sprites structures	|
********************************************/
typedef struct s_board
{
	t_map		map;
	t_sprite	spr;
	void		*mlx;
	void		*img;
	void		*win;
	int			w;
	int			h;
	t_sprite	wll;
	t_sprite	p;
	t_sprite	e;
	t_sprite	c;
	t_sprite	grd;
}	t_board;

int		key_on(int key, void *param);
//int		item_on_map(char *s);
void	item_on_map(t_board *bd, char *s);
//void	init_sprites(t_board *bd);

#endif
