/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:36:28 by nchennaf          #+#    #+#             */
/*   Updated: 2022/03/23 17:42:50 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	init_sprites(t_board *bd)
{
	bd->wll.type = mlx_xpm_file_to_image(bd->mlx, IMG_WLL1, &bd -> w, &bd -> h);
	bd->grd.type = mlx_xpm_file_to_image(bd -> mlx, IMG_GRD1, &bd -> w, &bd -> h);
	bd->p.type = mlx_xpm_file_to_image(bd -> mlx, IMG_P1, &bd -> w, &bd -> h);
	bd->c.type = mlx_xpm_file_to_image(bd -> mlx, IMG_C, &bd -> w, &bd -> h);
	bd->e.type = mlx_xpm_file_to_image(bd -> mlx, IMG_E, &bd -> w, &bd -> h);
}*/

/* CODE DE CLAIRE a etudier

[ ] Changer item_on_map avec les mlx_put_image_to_window correspondants

*/


/*void	define_image(t_game  *gm)
{
	int	i;
	void *w;

	i = 1;
	while(gm->map.map[i] != '\n')
		i++;
	gm->largeur = i;
	i = 1;
	w = gm->win.win;
	while (gm->map.map[i] != '\0')
	//while (i < 8)
	{
		printf("%d\n", gm->largeur);
		//printf("%d\n", ((i - 1) / gm ->largeur) * 32);
		if (gm->map.map[i] == '1')
			mlx_put_image_to_window(gm->mlx, w, gm ->wal.img, ((i - 1) % gm ->largeur) * 32, ((i - 1) / gm ->largeur) * 32);
		else if (gm->map.map[i] == '0')
			mlx_put_image_to_window(gm ->mlx, w, gm ->wat.img, ((i - 1) % gm ->largeur) * 32, ((i - 1) / gm ->largeur) * 32);
		else if (gm->map.map[i] == 'P')
			mlx_put_image_to_window(gm ->mlx, w, gm ->go.img, ((i - 1) % gm ->largeur) * 32, ((i - 1) / gm ->largeur) * 32);
		else if (gm->map.map[i] == 'C')
			mlx_put_image_to_window(gm ->mlx, w, gm ->brd.img, ((i - 1) % gm ->largeur) * 32, ((i - 1) / gm ->largeur) * 32);
		else if (gm->map.map[i] == 'E')
			mlx_put_image_to_window(gm ->mlx, w, gm ->ex.img, ((i - 1) % gm ->largeur) * 32, ((i - 1) / gm ->largeur) * 32);

		i++;
	}
}*/
