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
	t_sprite	sprt;
	void		*mlx;
	void		*img;
	void		*win;
	int			win_w;
	int			win_h;
} t_board;












#endif
