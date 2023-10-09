#include "so_long.h"

void	put_floor(t_game *game)
{
	game->img.image = mlx_xpm_file_to_image(game->mlx, "./floor.xpm", &game->img.img_width, &game->img.img_height);
	while (game->x < game->win.width)
	{
		game->y = 0;
		while (game->y < game->win.height)
		{
			mlx_put_image_to_window(game->mlx, game->win.win, game->img.image, game->x, game->y);
			game->y += SIZE;
		}
		game->x += SIZE;
	}
	game->x = 0;
	game->y = 0;
}

void	put_wall(t_game game)
{
	game.img.image = mlx_xpm_file_to_image(game.mlx, "./wall.xpm", &game.img.img_width, &game.img.img_height);
	mlx_put_image_to_window(game.mlx, game.win.win, game.img.image, game.x, game.y);
}

void	put_player(t_game game)
{
	game.img.image = mlx_xpm_file_to_image(game.mlx, "./player_right.xpm", &game.img.img_width, &game.img.img_height);
	mlx_put_image_to_window(game.mlx, game.win.win, game.img.image, game.x, game.y);
}

void	put_exit(t_game game)
{
	game.img.image = mlx_xpm_file_to_image(game.mlx, "./AA.xpm", &game.img.img_width, &game.img.img_height);
	mlx_put_image_to_window(game.mlx, game.win.win, game.img.image, game.x, game.y);
}

void	put_collectible(t_game game)
{
	game.img.image = mlx_xpm_file_to_image(game.mlx, "./collectible.xpm", &game.img.img_width, &game.img.img_height);
	mlx_put_image_to_window(game.mlx, game.win.win, game.img.image, game.x, game.y);
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

void    render_map(t_game *game, char *argv)
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