/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:43:53 by nchennaf          #+#    #+#             */
/*   Updated: 2022/02/15 15:44:02 by nchennaf         ###   ########.fr       */
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

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "The Legend of Diana");
	img = mlx_new_image(mlx_ptr, 500, 500);

	mlx_pixel_put(mlx_ptr, win_ptr, 250, 20, 0x00FF00FF);
	mlx_key_hook(win_ptr, key_on, &win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
