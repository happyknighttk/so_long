/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:51:49 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/09 16:57:56 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_game *game)
{
	game->img.image = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm",
			&game->img.img_width, &game->img.img_height);
	while (game->x < game->win.width)
	{
		game->y = 0;
		while (game->y < game->win.height)
		{
			mlx_put_image_to_window(game->mlx, game->win.win,
				game->img.image, game->x, game->y);
			game->y += SIZE;
		}
		game->x += SIZE;
	}
	game->x = 0;
	game->y = 0;
}

void	put_line(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			put_wall(*game);
		else if (line[i] == 'P')
			put_player(*game);
		else if (line[i] == 'C')
			put_collectible(*game);
		else if (line[i] == 'E')
			put_exit(*game);
		game->x += SIZE;
		i++;
	}
	game->x = 0;
}

void	render_map(t_game *game, char *argv)
{
	char	*line;
	int		fd;
	int		i;

	game->x = 0;
	game->y = 0;
	i = 0;
	fd = open(argv, O_RDONLY);
	map_check(game, argv);
	close(fd);
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	put_floor(game);
	while (game->y < game->win.height)
	{
		put_line(game, line);
		free(line);
		line = get_next_line(fd);
		i++;
		game->y += 64;
	}
	close(fd);
}
