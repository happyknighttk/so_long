/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:01:29 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/09 17:07:22 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_game game)
{
	game.img.image = mlx_xpm_file_to_image(game.mlx, "./assets/wall.xpm",
			&game.img.img_width, &game.img.img_height);
	mlx_put_image_to_window(game.mlx, game.win.win,
		game.img.image, game.x, game.y);
}

void	put_player(t_game game)
{
	game.img.image = mlx_xpm_file_to_image(game.mlx,
			"./assets/player_right.xpm",
			&game.img.img_width, &game.img.img_height);
	mlx_put_image_to_window(game.mlx, game.win.win,
		game.img.image, game.x, game.y);
}

void	put_exit(t_game game)
{
	game.img.image = mlx_xpm_file_to_image(game.mlx, "./assets/AA.xpm",
			&game.img.img_width, &game.img.img_height);
	mlx_put_image_to_window(game.mlx, game.win.win,
		game.img.image, game.x, game.y);
}

void	put_collectible(t_game game)
{
	game.img.image = mlx_xpm_file_to_image(game.mlx, "./assets/collectible.xpm",
			&game.img.img_width, &game.img.img_height);
	mlx_put_image_to_window(game.mlx, game.win.win,
		game.img.image, game.x, game.y);
}
