/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nadia <Nadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:43:53 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/08 20:13:48 by Nadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

/********************************************
|	Manage which key has been pressed		|
|	Directions are w, a, s, d and ESC		|
|	Statut : ESC OK, reste a gerer les directions		|
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
	else
		;
	return (EXIT_SUCCESS);
}

/********************************************
|	Seeks the path to the right image		|
|	and render it on window					|
********************************************/
void	pathfinder(t_board *bd, char *path, int x, int y)
{
	bd->spr->img = mlx_xpm_file_to_image(bd->mlx, path, &bd->spr->w, &bd->spr->h);
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
		{
			pathfinder(bd, IMG_WLL2, bd->map.x, bd->map.y);
			bd->itm->one++;
		}
		else if (c == '0')
		{
			pathfinder(bd, IMG_GRD1, bd->map.x, bd->map.y);
			bd->itm->zero++;
		}
		else if (c == 'P')
		{
			pathfinder(bd, IMG_P1, bd->map.x, bd->map.y);
			bd->itm->p++;
			bd->p1->x = bd->map.x;
			bd->p1->y = bd->map.y;
			bd->p1->cd_x = bd->p1->x/IMG_PXL;
			bd->p1->cd_y = bd->p1->y/IMG_PXL;
		}
		else if (c == 'C')
		{
			pathfinder(bd, IMG_C, bd->map.x, bd->map.y);
			bd->itm->c++;
		}
		else if (c == 'E')
		{
			pathfinder(bd, IMG_E1, bd->map.x, bd->map.y);
			bd->itm->e++;
			bd->itm->x_e = bd->map.x;
			bd->itm->y_e = bd->map.y;
		}
		else if (c == '\n')
			;
		else
			errorminator(ERR_ITEM);
	}
}

int	close_win(void)
{
	ft_printf("So long!\n(and thanks for all the fish!)\n");
	exit(EXIT_SUCCESS);
}

void	check_file(t_board *bd, char **argv)
{
	int		fd;
	char	*tempura;
	char	*gnl;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		errorminator(ERR_FILE);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		errorminator(ERR_FILE);
	bd->map.y_len = 0;
	bd->map.x_len = 0;
	gnl = get_next_line(fd);
	bd->map.content = ft_strdup("");
	while (gnl != NULL)
	{
		if (bd->map.x_len && bd->map.x_len != ft_printf("%s", gnl))
			errorminator(ERR_SHP);
		bd->map.x_len = ft_printf("%s", gnl);
		tempura = bd->map.content;
		bd->map.content = ft_strjoin(bd->map.content, gnl);
		free(tempura);
		free(gnl);
		gnl = get_next_line(fd);
		bd->map.y_len++;
	}
	close(fd);
	ft_printf("map.content :\n\n%s\n", bd->map.content);
}


