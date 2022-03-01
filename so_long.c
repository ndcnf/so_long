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

#include	"so_long.h"

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
	t_board	bd;

	bd.win_h = 512;
	bd.win_w = 512;
	bd.sprt.path = "./sprites/tile000.xpm";

	bd.mlx = mlx_init();
	bd.win = mlx_new_window(bd.mlx, bd.win_h, bd.win_w, "The Legend of Diana");
	bd.img = mlx_xpm_file_to_image(bd.mlx, bd.sprt.path, &bd.sprt.w, &bd.sprt.h);
	
	bd.map.x = 0;
	bd.map.y = 0;

	while (bd.map.y < bd.win_h)
	{
		while (bd.map.x < bd.win_w)
		{
			mlx_put_image_to_window(bd.mlx, bd.win, bd.img, bd.map.x, bd.map.y);
			bd.map.x += bd.sprt.w;
		}
		bd.map.y += bd.sprt.w;
		bd.map.x = 0;
	}
	mlx_loop(bd.mlx);
}
