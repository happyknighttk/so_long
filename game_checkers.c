/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:50:44 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/09 16:52:29 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_game_winnable(char **tmp_map, int x, int y)
{
	tmp_map[y][x] = 'x';
	if (tmp_map[y][x - 1] != '1' && tmp_map[y][x - 1] != 'x')
		is_game_winnable(tmp_map, x - 1, y);
	if (tmp_map[y + 1][x] != '1' && tmp_map[y + 1][x] != 'x')
		is_game_winnable(tmp_map, x, y + 1);
	if (tmp_map[y - 1][x] != '1' && tmp_map[y - 1][x] != 'x')
		is_game_winnable(tmp_map, x, y - 1);
	if (tmp_map[y][x + 1] != '1' && tmp_map[y][x + 1] != 'x')
		is_game_winnable(tmp_map, x + 1, y);
	else
		tmp_map[y][x] = 'x';
}

void	is_game_really_winnable(char **tmp_map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (tmp_map[y])
	{
		while (tmp_map[y][x] != '\0')
		{
			if (tmp_map[y][x] == 'E' || tmp_map[y][x] == 'C' \
					|| tmp_map[y][x] == 'P')
			{
				ft_printf("bruhhhhh\n");
				destroy_map(tmp_map);
				exit(1);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	game_check(t_game *game)
{
	int	i;
	int	j;

	line_size_check(game);
	i = 0;
	while (game->map[i])
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
