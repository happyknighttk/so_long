/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:50:44 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/11 20:59:20 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_game_winnable(char **tmp_map, int x, int y)
{
	tmp_map[y][x] = 'x';
	if (tmp_map[y][x - 1] != '1' && tmp_map[y][x - 1] != 'x'
		&& tmp_map[y][x - 1] != 'E')
		is_game_winnable(tmp_map, x - 1, y);
	if (tmp_map[y + 1][x] != '1' && tmp_map[y + 1][x] != 'x'
		&& tmp_map[y + 1][x] != 'E')
		is_game_winnable(tmp_map, x, y + 1);
	if (tmp_map[y - 1][x] != '1' && tmp_map[y - 1][x] != 'x'
		&& tmp_map[y - 1][x] != 'E')
		is_game_winnable(tmp_map, x, y - 1);
	if (tmp_map[y][x + 1] != '1' && tmp_map[y][x + 1] != 'x'
		&& tmp_map[y][x + 1] != 'E')
		is_game_winnable(tmp_map, x + 1, y);
	else
		tmp_map[y][x] = 'x';
}

void	invalid_game_exit(char **map, t_game game)
{
	ft_printf("Error\nThe game is not winnable!\n");
	destroy_map(map, game);
	exit(1);
}

void	is_game_really_winnable(char **tmp_map, t_game game)
{
	int	y;
	int	x;

	y = 0;
	while (tmp_map[y] && y < game.win.height / SIZE)
	{
		x = 0;
		while (tmp_map[y][x])
		{
			if (tmp_map[y][x] == 'E')
				if (tmp_map[y - 1][x] != 'x' && tmp_map[y + 1][x] != 'x'
					&& tmp_map[y][x - 1] != 'x' && tmp_map[y][x + 1] != 'x')
					invalid_game_exit(tmp_map, game);
			if (tmp_map[y][x] == 'C' || tmp_map[y][x] == 'P')
				invalid_game_exit(tmp_map, game);
			x++;
		}
		y++;
	}
}

void	game_check(t_game *game)
{
	int	i;
	int	j;

	line_size_check(game);
	i = 0;
	while (game->map[i] && i < game->win.height / SIZE)
	{
		j = 0;
		while (game->map[i][j++])
		{
			if (!(ft_strchr("1PCE0\n", game->map[i][j])))
				exit_or_error("Error\nForeign element in map!", game);
			if (game->map[i][j] == 'C')
				game->collectible_flag++;
			if (game->map[i][j] == 'P')
			{
				game->player.x = j * SIZE;
				game->player.y = i * SIZE;
				game->player_flag++;
			}
		}
		i++;
	}
	component_check(game);
	wall_check(game);
}
