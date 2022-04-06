/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:34:13 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/06 12:58:56 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(int argc, char *argv[])
{
	t_board	bd;

	check_args(argc);
	check_file(&bd, argv);
	init_items(&bd);
	init_map(&bd);

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
