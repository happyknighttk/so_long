/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:30:26 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/11 21:43:14 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char **map, int fd, t_game *game)
{
	int	i;

	i = 0;
	while (i < (game->win.height / SIZE))
	{
		map[i] = get_next_line(fd);
		i++;
	}
}

void	malloc_error_exit(char **map, t_game game)
{
	ft_printf("Error\nMalloc error\n!");
	destroy_map(map, game);
	exit(1);
}

void	map_check(t_game *game, char *argv)
{
	char	**tmp_map;
	int		fd;

	game->map = (char **)malloc(sizeof(char *) * (game->win.height / SIZE));
	if (!(game->map))
		malloc_error_exit(game->map, *game);
	fd = open(argv, O_RDONLY);
	read_map(game->map, fd, game);
	close(fd);
	game_check(game);
	tmp_map = (char **)malloc(sizeof(char *) * (game->win.height / SIZE));
	if (!(tmp_map))
		malloc_error_exit(tmp_map, *game);
	fd = open(argv, O_RDONLY);
	read_map(tmp_map, fd, game);
	close(fd);
	is_game_winnable(tmp_map, game->player.x / SIZE, game->player.y / SIZE);
	is_game_really_winnable(tmp_map, *game);
	destroy_map(tmp_map, *game);
	free(tmp_map);
}
