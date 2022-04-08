/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nadia <Nadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:34:13 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/08 16:31:21 by Nadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(int argc, char *argv[])
{
	t_board	bd;

	allowance(&bd);
	check_args(argc);
	check_file(&bd, argv);
	init_map(&bd);
	init_items(&bd);
	read_map(&bd);

	check_items(&bd);
	wololo(&bd);
	mlx_key_hook(bd.win, key_on, &bd); // gere les entrees des touches
	mlx_hook(bd.win, X_BTN, 0, close_win, &bd);
	mlx_loop(bd.mlx); //permet de boucler

	return (EXIT_SUCCESS);
}
