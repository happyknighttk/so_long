/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:30:26 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/09 16:43:00 by tkayis           ###   ########.fr       */
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

void	map_check(t_game *game, char *argv)
{
	char	**tmp_map;
	int		fd;

	game->map = (char **)malloc(sizeof(char *) * (99999));
	tmp_map = (char **)malloc(sizeof(char *) * (99999));
	if (!(game->map) || !(tmp_map))
	{
		ft_printf("Error\nMalloc error\n!");
		exit(1);
	}
	fd = open(argv, O_RDONLY);
	read_map(game->map, fd, game);
	close(fd);
	game_check(game);
	fd = open(argv, O_RDONLY);
	read_map(tmp_map, fd, game);
	close(fd);
	is_game_winnable(tmp_map, 1, 1);
	is_game_really_winnable(tmp_map);
	destroy_map(tmp_map);
	free(tmp_map);
}
