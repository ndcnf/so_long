/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nadia <Nadia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:45:27 by Nadia             #+#    #+#             */
/*   Updated: 2022/04/04 20:34:46 by Nadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

//MODIFIER LE HEADER !!!!

void	move_up(t_board *bd)
{
	t_sprite	sprite;

	sprite.img = mlx_xpm_file_to_image(bd->mlx, IMG_GRD1, &sprite.w, &sprite.h);
	mlx_put_image_to_window(bd->mlx, bd->win, sprite.img, bd->p1.x, bd->p1.y);
	
	//verifier si le move est legal
	//verifier si collectible, alors decrementer le compteur de collectibles
	sprite.img = mlx_xpm_file_to_image(bd->mlx, IMG_P2, &sprite.w, &sprite.h);
	mlx_put_image_to_window(bd->mlx, bd->win, sprite.img, bd->map.x, bd->map.y);

	bd->p1.steps++;
}