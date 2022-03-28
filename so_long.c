/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:43:53 by nchennaf          #+#    #+#             */
/*   Updated: 2022/03/25 17:12:27 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

/********************************************
|	Gestion des touches pressees 			|
|	Gere w, a, s, d et ESC					|
|	Statut : affiche juste un message		|
********************************************/
int	key_on(int key, void *param)
{
	ft_printf("key : %d\n", key);
	ft_printf("param : %p\n", param);
	if (key == KEY_ESC)
		close_win();
	else if (key == KEY_W || key == KEY_UP)
		ft_printf("Up");
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

void	pathfinder(t_board *bd, char *path)
{
	t_sprite sprite;

	sprite.img = mlx_xpm_file_to_image(bd->mlx, path, &sprite.w, &sprite.h);
	mlx_put_image_to_window(bd->mlx, bd->win, sprite.img, bd->map.x, bd->map.y);
}

void	item_on_map(t_board *bd)
{
	static size_t	i = -1;

	if (!bd->map.content)
		return ;

	if (++i < ft_strlen(bd->map.content))
	{
		pathfinder(bd, IMG_GRD1);
		if (bd->map.content[i] == '1')
			pathfinder(bd, IMG_WLL2);
		else if (bd->map.content[i] == '0')
			pathfinder(bd, IMG_GRD2);
		else if (bd->map.content[i] == 'P')
			pathfinder(bd, IMG_P2);
		else if (bd->map.content[i] == 'C')
			pathfinder(bd, IMG_C);
		else if (bd->map.content[i] == 'E')
			pathfinder(bd, IMG_E);
		else if (bd->map.content[i] == '\n')
			ft_printf("Have you returned?\n");
		else
			ft_printf("I don't think so, it's not valid\n");
	}
}

int	close_win(void)
{
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_board	bd;
	int		fd;
	char	*gnl;
	int		cnt;
	int		i;

	if (argc != 2)
	{
		ft_printf(ERROR ERR_ARG);
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf(ERROR ERR_FD);
		return (EXIT_FAILURE);
	}

	i = 0;
	gnl = get_next_line(fd);
	bd.map.content = ft_strdup("");
	while (gnl != NULL)
	{
		cnt = ft_printf("%s", gnl);
		bd.map.content = ft_strjoin(bd.map.content, gnl);
		gnl = get_next_line(fd);
		i++;
	}
	close(fd);

	bd.h = i * IMG_PXL;
	ft_printf("cnt : %d\n", cnt);
	bd.w = (cnt - 1) * IMG_PXL;
	ft_printf("i : %d\n", i);

	bd.mlx = mlx_init();
	bd.win = mlx_new_window(bd.mlx, bd.w, bd.h, WIN_TITLE);

	bd.map.x = 0;
	bd.map.y = 0;

	while (bd.map.y <= bd.h)
	{
		while (bd.map.x <= bd.w)
		{
			item_on_map(&bd);
			bd.map.x += IMG_PXL;
		}
		bd.map.y += IMG_PXL;
		bd.map.x = 0;
	}

	mlx_key_hook(bd.win, key_on, &bd.win); // gere les entrees des touches
	mlx_hook(bd.win, X_BTN, 0, close_win, &bd);
	mlx_loop(bd.mlx); //permet de boucler

	return (EXIT_SUCCESS);
}
