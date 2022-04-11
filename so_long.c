/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:43:53 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/11 10:56:09 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

/********************************************
|	Manage which key has been pressed		|
|	Directions are w, a, s, d and ESC		|
********************************************/
int	key_on(int key, t_board *bd)
{
	if (key == KEY_ESC)
		close_win();
	else if (key == KEY_W || key == KEY_UP)
		move(bd, KEY_UP);
	else if (key == KEY_A || key == KEY_LFT)
		move(bd, KEY_LFT);
	else if (key == KEY_S || key == KEY_DWN)
		move(bd, KEY_DWN);
	else if (key == KEY_D || key == KEY_RGT)
		move(bd, KEY_RGT);
	return (EXIT_SUCCESS);
}

/********************************************
|	Seeks the path to the right image		|
|	and render it on window					|
********************************************/
void	pathfinder(t_board *bd, char *path, int x, int y)
{
	char	*img;

	img = mlx_xpm_file_to_image(bd->mlx, path, &bd->spr->w, &bd->spr->h);
	bd->spr->img = img;
	mlx_put_image_to_window(bd->mlx, bd->win, bd->spr->img, x, y);
}

void	item_on_map(t_board *bd)
{
	static size_t	i = -1;
	char			c;

	if (!bd->map.content)
		return ;
	if (++i < ft_strlen(bd->map.content))
	{
		c = ft_toupper(bd->map.content[i]);
		pathfinder(bd, IMG_GRD1, bd->map.x, bd->map.y);
		if (c == '1')
			define_walls(bd);
		else if (c == '0')
			hello_ground(bd);
		else if (c == 'P')
			define_player(bd);
		else if (c == 'C')
			define_collectibles(bd);
		else if (c == 'E')
			define_exit(bd);
		else if (c == '\n')
			;
		else
			errorminator(ERR_ITEM);
	}
}

int	close_win(void)
{
	ft_printf(BYE);
	exit(EXIT_SUCCESS);
}

void	check_file(t_board *bd, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		errorminator(ERR_FILE);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		errorminator(ERR_FILE);
	process_map(bd, fd);
	close(fd);
}
