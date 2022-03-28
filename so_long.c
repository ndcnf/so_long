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

/********************************************
|	Seeks the path to the right image		|
|	and render it on window					|
********************************************/
void	pathfinder(t_board *bd, char *path)
{
	t_sprite sprite;

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
			pathfinder(bd, IMG_WLL2);
		else if (c == '0')
			pathfinder(bd, IMG_GRD2);
		else if (c == 'P')
			pathfinder(bd, IMG_P2);
		else if (c == 'C')
			pathfinder(bd, IMG_C);
		else if (c == 'E')
			pathfinder(bd, IMG_E);
		else if (c == '\n')
			ft_printf("Have you returned?\n");
		else
			ft_printf("I don't think so, it's not valid\n");
	}
}

int	close_win(void)
{
	exit(EXIT_SUCCESS);
}

void	check_args(int argc)
{
	if (argc != 2)
	{
		ft_printf(ERROR ERR_ARG);
		exit(EXIT_FAILURE);
	}
}

void	check_file(t_board *bd, char **argv)
{
	int		fd;
	char	*tempura;
	char	*gnl;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf(ERROR ERR_FILE);
		exit(EXIT_FAILURE);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		ft_printf(ERROR ERR_FILE);
		exit(EXIT_FAILURE);
	}
	bd->map.y_len = 0;
	gnl = get_next_line(fd);
	bd->map.content = ft_strdup("");
	while (gnl != NULL)
	{
		bd->map.x_len = ft_printf("%s", gnl);
		tempura = bd->map.content;
		bd->map.content = ft_strjoin(bd->map.content, gnl);
		free(tempura);
		free(gnl);
		gnl = get_next_line(fd);
		bd->map.y_len++;
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_board	bd;

	check_args(argc);
	check_file(&bd, argv);

	bd.h = bd.map.y_len * IMG_PXL;
	ft_printf("cnt : %d\n", bd.map.x_len);
	bd.w = (bd.map.x_len - 1) * IMG_PXL;
	ft_printf("i : %d\n", bd.map.y_len);

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
