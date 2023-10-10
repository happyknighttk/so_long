/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:22:39 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/09 16:59:27 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, int x, int y)
{
	game->img.image = mlx_xpm_file_to_image(game->mlx, game->img.path,
			&game->img.img_width, &game->img.img_height);
	mlx_put_image_to_window(game->mlx, game->win.win, game->img.image, x, y);
}

void	floor_update(t_game *game)
{
	game->img.path = "./assets/floor.xpm";
	put_image(game, game->player.x, game->player.y);
}
