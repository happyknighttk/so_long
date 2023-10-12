/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:49:53 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/12 13:39:23 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycode_check(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_or_error("Exiting via ESC", game);
	else if (keycode == UP)
		player_move_up(game);
	else if (keycode == DOWN)
		player_move_down(game);
	else if (keycode == LEFT)
		player_move_left(game);
	else if (keycode == RIGHT)
		player_move_right(game);
	return (0);
}

int	xclose(t_game *game)
{
	exit_or_error("Exiting game via X", game);
	return (0);
}

void	initialize_game_start(t_game *game)
{
	game->collectible_flag = 0;
	game->exit_flag = 0;
	game->player_flag = 0;
	game->player.player_collect = 0;
	game->player.player_move = 0;
	game->img.img_height = 64;
	game->img.img_width = 64;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("%s", "There has to be 2 arguments!");
		return (1);
	}
	game.mlx = mlx_init();
	create_window(&game, argv[1]);
	initialize_game_start(&game);
	render_map(&game, argv[1]);
	mlx_hook(game.win.win, 17, 0, xclose, &game);
	mlx_hook(game.win.win, 2, 0, keycode_check, &game);
	mlx_loop(game.mlx);
}
