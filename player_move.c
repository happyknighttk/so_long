/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:20:49 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/09 16:58:48 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move_check(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	else if (game->map[y][x] == 'C')
	{
		game->player.player_collect++;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->player.player_collect != game->collectible_flag)
			return (0);
		exit_or_error("Congratulations! You win!", game);
	}
	return (1);
}

void	player_move_up(t_game *game)
{
	int	y;
	int	x;

	y = game->player.y - SIZE;
	x = game->player.x;
	if (player_move_check(game, (x / SIZE), (y / SIZE)))
	{
		game->player.player_move++;
		ft_printf("Moves: %d\n", game->player.player_move);
		floor_update(game);
		game->img.path = "./assets/player_right.xpm";
		game->player.x = x;
		game->player.y = y;
		put_image(game, x, y);
	}
}

void	player_move_down(t_game *game)
{
	int	y;
	int	x;

	y = game->player.y + SIZE;
	x = game->player.x;
	if (player_move_check(game, (x / SIZE), (y / SIZE)))
	{
		game->player.player_move++;
		ft_printf("Moves: %d\n", game->player.player_move);
		floor_update(game);
		game->img.path = "./assets/player_right.xpm";
		game->player.x = x;
		game->player.y = y;
		put_image(game, x, y);
	}
}

void	player_move_left(t_game *game)
{
	int	y;
	int	x;

	y = game->player.y;
	x = game->player.x - SIZE;
	if (player_move_check(game, (x / SIZE), (y / SIZE)))
	{
		game->player.player_move++;
		ft_printf("Moves: %d\n", game->player.player_move);
		floor_update(game);
		game->img.path = "./assets/player_left.xpm";
		game->player.x = x;
		game->player.y = y;
		put_image(game, x, y);
	}
}

void	player_move_right(t_game *game)
{
	int	y;
	int	x;

	y = game->player.y;
	x = game->player.x + SIZE;
	if (player_move_check(game, (x / SIZE), (y / SIZE)))
	{
		game->player.player_move++;
		ft_printf("Moves: %d\n", game->player.player_move);
		floor_update(game);
		game->img.path = "./assets/player_right.xpm";
		game->player.x = x;
		game->player.y = y;
		put_image(game, x, y);
	}
}
