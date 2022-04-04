/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nadia <Nadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:34:13 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/04 20:34:34 by Nadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

//MODIFIER LE HEADER !!!!

int	main(int argc, char *argv[])
{
	t_board	bd;

	check_args(argc);
	check_file(&bd, argv);
	init_items(&bd);

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
	check_items(&bd);
	mlx_key_hook(bd.win, key_on, &bd.win); // gere les entrees des touches
	mlx_hook(bd.win, X_BTN, 0, close_win, &bd);
	mlx_loop(bd.mlx); //permet de boucler

	return (EXIT_SUCCESS);
}
