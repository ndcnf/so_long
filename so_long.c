/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:43:53 by nchennaf          #+#    #+#             */
/*   Updated: 2022/02/28 10:19:43 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "mlx/mlx.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	key_on(int key, void *param)
{
	printf("key : %d\n", key);
	printf("param : %p\n", param);

	ft_putchar('X');
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
	void	*mlx;
	void	*img;
	void	*win_ptr;
	char	*relative_path = "./sprites/tile027.xpm"; //buisson
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, 512, 512, "The Legend of Diana");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	printf("largeur [%d] - hauteur [%d] \n", img_width, img_height);
	x = 0;
	y = 0;

	while (x < 512)
	{
		mlx_put_image_to_window(mlx, win_ptr, img, x, 0);
		x += img_width;
	}
/*
	mlx_put_image_to_window(mlx, win_ptr, img, 16, 0);
	mlx_put_image_to_window(mlx, win_ptr, img, 32, 0);
*/
	mlx_loop(mlx);
}
