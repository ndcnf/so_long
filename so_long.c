/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:43:53 by nchennaf          #+#    #+#             */
/*   Updated: 2022/03/18 18:26:06 by nchennaf         ###   ########.fr       */
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
	{
		ft_printf("Escape is an option\n");
		exit(0);
	}
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
	return (0);
}

/*int	main()
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*path;
	int		img_w;
	int		img_h;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, 500, 500, "The Legend of Diana");
	//img = mlx_new_image(mlx, 500, 500);
	path = "./sprites/tile027.xpm";
	img = mlx_xpm_file_to_image(mlx, path, &img_w, &img_h);

	//mlx_pixel_put(mlx, win_ptr, 250, 20, 0x00FF00FF);
	mlx_key_hook(win_ptr, key_on, &win_ptr);
	mlx_loop(mlx);
	return (0);
}
*/

int	read_map(char *s)
{
	(void)s;
	return 0;
}

/*char	pathfinder(char c)
{



	return (path);
}*/

int	item_on_map(char *s)
{
	int 		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '1')
		{
			ft_printf("It's a shrub!");
			//mlx_put_image_to_window();
		}
		else if (s[i] == '0')
			ft_printf("Hello ground!");
		else if (s[i] == 'P')
			ft_printf("Hey, playa!");
		else if (s[i] == 'C')
			ft_printf("Collect'em all!");
		else if (s[i] == 'E')
			ft_printf("Sors, t'as plus l'temps!");
		else if (s[i] == '\n')
			ft_printf("Have you returned?");
		else
			ft_printf("I don't think so, it's not valid");
		ft_printf("\n");
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_board	bd;
	int		fd;
	char	*gnl;
	int		cnt;

	if (argc != 2)
	{
		ft_printf(ERROR ERR_ARG);
		return (0);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf(ERROR ERR_FD);
		return (-1);
	}

	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		cnt = ft_printf("%s", gnl);
		ft_printf("d : %d\n", cnt); // nbre d images a afficher par ligne (-1)
		item_on_map(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);

	init_sprites(&bd);
	// definir la taille du board / fenetre
	bd.h = WIN_H;
	bd.w = WIN_W;

	// Definir le path selon le fichier .ber, donc foret d'if a gerer ici prochainement
	bd.spr.path = IMG_WLL1;

	bd.mlx = mlx_init();
	bd.win = mlx_new_window(bd.mlx, bd.h, bd.w, WIN_TITLE);
	//bd.img = mlx_xpm_file_to_image(bd.mlx, bd.spr.path, &bd.spr.w, &bd.spr.h);

	bd.map.x = 0;
	bd.map.y = 0;

	// Affiche une seule image sur l'entier de la fenetre
	// Va remplir la ligne des x d'abord, puis la suivante a la fin de la ligne
	while (bd.map.y < bd.h)
	{
		while (bd.map.x < bd.w)
		{
			bd.img = mlx_xpm_file_to_image(bd.mlx, bd.spr.path, &bd.spr.w, &bd.spr.h);
			mlx_put_image_to_window(bd.mlx, bd.win, bd.img, bd.map.x, bd.map.y);
			bd.map.x += bd.spr.w;
		}
		bd.map.y += bd.spr.w;
		bd.map.x = 0;
	}

	mlx_key_hook(bd.win, key_on, &bd.win); // gere les entrees des touches
	mlx_loop(bd.mlx); //permet de boucler

	return (0);
}
