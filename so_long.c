/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:43:53 by nchennaf          #+#    #+#             */
/*   Updated: 2022/04/06 13:01:34 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

/********************************************
|	Manage which key has been pressed		|
|	Directions are w, a, s, d and ESC		|
|	Statut : ESC OK, reste a gerer les directions		|
********************************************/
int	key_on(int key, void *param)
{
	ft_printf("key : %d\n", key);
	ft_printf("param : %p\n", param);
	if (key == KEY_ESC)
		close_win();
	else if (key == KEY_W || key == KEY_UP)
	{
		//ici l'appel de fonction pour monter
		//move_up(bd);
		ft_printf("Up");
	}
	else if (key == KEY_A || key == KEY_LFT)
		ft_printf("Left");
	else if (key == KEY_S || key == KEY_DWN)
		ft_printf("Down");
	else if (key == KEY_D || key == KEY_RGT)
		ft_printf("Right");
	else
		ft_printf("I don't understand this direction!");
	ft_printf("\n");
	return (EXIT_SUCCESS);
}

/********************************************
|	Seeks the path to the right image		|
|	and render it on window					|
********************************************/
void	pathfinder(t_board *bd, char *path)
{
	t_sprite	sprite;

	sprite.img = mlx_xpm_file_to_image(bd->mlx, path, &sprite.w, &sprite.h);
	mlx_put_image_to_window(bd->mlx, bd->win, sprite.img, bd->map.x, bd->map.y);
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
		pathfinder(bd, IMG_GRD1);
		if (c == '1')
		{
			pathfinder(bd, IMG_WLL2);
			bd->itm.one++;
		}
		else if (c == '0')
		{
			pathfinder(bd, IMG_GRD2);
			bd->itm.zero++;
		}
		else if (c == 'P')
		{
			pathfinder(bd, IMG_P2);
			bd->itm.p++;
			bd->p1.x = bd->map.x;
			bd->p1.y = bd->map.y;
		}
		else if (c == 'C')
		{
			pathfinder(bd, IMG_C);
			bd->itm.c++;
		}
		else if (c == 'E')
		{
			pathfinder(bd, IMG_E1);
			bd->itm.e++;
		}
		else if (c == '\n')
			;
		else
			errorminator(ERR_ITEM);
	}
}

int	close_win(void)
{
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
