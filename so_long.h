/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:57:20 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/06 12:06:18 by nchennaf         ###   ########.fr       */
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
# define X_BTN 17

# define WIN_TITLE "The Untold Legend of Diana And the Evil Shrubs"
# define WIN_H 512
# define WIN_W 512
# define IMG_PXL 32 //vraiment utile ou redondant ?

# define IMG_P1 "./sprites/blob01.xpm"
# define IMG_P2 "./sprites/jumino.xpm"
# define IMG_E1 "./sprites/heart_locked.xpm"
# define IMG_E2 "./sprites/heart_unlocked.xpm"
# define IMG_C "./sprites/fruit00.xpm"
# define IMG_WLL1 "./sprites/shrub00.xpm"
# define IMG_WLL2 "./sprites/shrub01.xpm"
# define IMG_GRD1 "./sprites/ground00.xpm"
# define IMG_GRD2 "./sprites/ground01.xpm"

# define ERROR "Error\n"
# define ERR_ARG "Nombre d'arguments invalide\n"
# define ERR_FILE "Erreur avec le fichier\n"
# define ERR_ITEM "La carte contient un ou plusieurs item(s) invalide(s)\n"
# define ERR_SHP "La forme de la carte est invalide\n"
# define ERR_PLYR "La carte doit comporter un joueur obligatoirement\n"
# define ERR_COLL "La carte doit comporter au moins un objet a collectionner\n"
# define ERR_EXIT "La carte doit comporter une sortie obligatoirement\n"
# define ERR_WLL "La carte doit etre entouree de murs\n"
# define ERR_GRD "La carte doit comporter au moins un sol\n"

/********************************************
|	Manages the current coordinates			|
********************************************/
typedef struct s_map
{
	int		x;
	int		y;
	int		x_len;
	int		y_len;
	char	*content;
}	t_map;

/********************************************
|	Manages the sprites						|
********************************************/
typedef struct s_sprite
{
	int		w;
	int		h;
	void	*img;
}	t_sprite;

/********************************************
|	Counts every item on the map			|
********************************************/
typedef struct s_items
{
	int	p;
	int	e;
	int	one;
	int	zero;
	int	c;
}	t_items;

typedef struct s_player
{
	int	steps;
	int	x;
	int	y;
}	t_player;

/********************************************
|	Manages the game board					|
********************************************/
typedef struct s_board
{
	t_map		map;
	t_sprite	spr;
	t_items		itm;
	t_player	p1;
	void		*mlx;
	void		*img;
	void		*win;
	int			w;
	int			h;
}	t_board;

int		key_on(int key, void *param);
void	item_on_map(t_board *bd);
int		close_win(void);
void	check_file(t_board *bd, char **argv);
void	check_args(int argc);
void	check_items(t_board *bd);
void	errorminator(char *s);
void	init_items(t_board *bd);
void	init_map(t_board *bd);
void	check_walls(t_board *bd);
void	move_up(t_board *bd);

#endif
