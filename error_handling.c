/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:25:17 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/09 16:52:04 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
}

void	exit_or_error(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	mlx_destroy_window(game->mlx, game->win.win);
	destroy_map(game->map);
	system("leaks so_long");
	exit(0);
}

void	component_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->exit_flag++;
			j++;
		}
		i++;
	}
	if (game->collectible_flag == 0)
		exit_or_error("Error\nThere are no collectibles on the map!", game);
	if (game->exit_flag == 0)
		exit_or_error("Error\nThere should be an exit on the map!", game);
	if (game->player_flag != 1)
		exit_or_error("Error\n\
			There should be only one player on the map!", game);
}

void	wall_check(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (game->win.height / SIZE))
	{
		x = 0;
		while (x < (game->win.width / SIZE))
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				exit_or_error("Error\n\
					The map must be surrounded by walls!", game);
			else if ((y == (game->win.height / SIZE - 1)
					|| x == (game->win.width / SIZE - 1))
				&& game->map[y][x] != '1')
				exit_or_error("Error\n\
					The map must be surrounded by walls!", game);
			x++;
		}
		y++;
	}
}

void	line_size_check(t_game *game)
{
	size_t	line;
	size_t	len;
	size_t	last_line;

	line = 0;
	len = game->win.width / SIZE;
	last_line = (game->win.height / SIZE) - 1;
	while (game->map[line])
	{
		if (line == last_line && ft_strlen(game->map[line]) != len)
			exit_or_error("Error\nThe map has to be rectangular!", game);
		if (line != last_line && ft_strlen(game->map[line]) - 1 != len)
			exit_or_error("Error\nThe map has to be rectangular!", game);
		line++;
	}
}
