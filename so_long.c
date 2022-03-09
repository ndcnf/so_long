/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:43:53 by nchennaf          #+#    #+#             */
/*   Updated: 2022/03/09 14:34:30 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

/********************************************
|	Gestion des touches pressees 			|
|	Affiche w a s d ou X selon input		|
|	Statut : affiche juste, rien d'autre	|
********************************************/
int	key_on(int key, void *param)
{
	printf("key : %d\n", key);
	printf("param : %p\n", param);

	if (key == 53)
		ft_putstr("Escape is an option");
	else if (key == 13 || key == 126)
		ft_putstr("Up");
	else if (key == 0 || key == 123)
		ft_putstr("Left");
	else if (key == 1 || key == 125)
		ft_putstr("Down");
	else if (key == 2 || key == 124)
		ft_putstr("Right");
	else
		ft_putstr("I don't understand this direction!");
	ft_putchar('\n');

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

int	main(void)
{
	t_board	bd;

	// definir la taille du board / fenetre
	bd.h = 512;
	bd.w = 512;
	bd.spr.path = "./sprites/tile000.xpm";

	bd.mlx = mlx_init();
	bd.win = mlx_new_window(bd.mlx, bd.h, bd.w, "The Legend of Diana");
	bd.img = mlx_xpm_file_to_image(bd.mlx, bd.spr.path, &bd.spr.w, &bd.spr.h);

	bd.map.x = 0;
	bd.map.y = 0;

	// Affiche une seule image sur l'entier de la fenetre
	// Va remplir la ligne des x d'abord, puis la suivante a la fin de la ligne
	while (bd.map.y < bd.h)
	{
		while (bd.map.x < bd.w)
		{
			mlx_put_image_to_window(bd.mlx, bd.win, bd.img, bd.map.x, bd.map.y);
			bd.map.x += bd.spr.w;
		}
		bd.map.y += bd.spr.w;
		bd.map.x = 0;
	}

	mlx_key_hook(bd.win, key_on, &bd.win); // gere les entrees des touches
	mlx_loop(bd.mlx); //permet de boucler
}
