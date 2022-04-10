/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nadia <Nadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:34:13 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/10 14:38:39 by Nadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//CHANGER HEADER!!!

#include	"so_long.h"

int	main(int argc, char *argv[])
{
	t_board	bd;

	allowance(&bd);
	check_args(argc);
	check_file(&bd, argv);
	init_map(&bd);
	init_items(&bd);
	render_map(&bd);
	wololo(&bd);
	check_walls(&bd);
	check_items(&bd);
	mlx_key_hook(bd.win, key_on, &bd);
	mlx_hook(bd.win, X_BTN, 0, close_win, &bd);
	mlx_loop(bd.mlx);
	return (EXIT_SUCCESS);
}
