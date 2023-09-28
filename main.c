#include "so_long.h"

//void	render_floor(t_game *g)
//{
//	mlx_put_image_to_window(g->mlx, g->win.win, g->floor, 0, 0);
//	mlx_string_put(g->mlx, g->win.win, 50, 50, 65280, "Your Score: ");
//}

int	keycode_check(int keycode, t_game *g)
{
	if (keycode == ESC)
	{
		mlx_clear_window(g->mlx, g->win.win);
		sleep(1);
		exit(0);
	}
	return (0);
}


int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("%s", "There has to be 2 arguments!");
		return (1);
	}
	game.mlx = mlx_init();

	//game.floor = mlx_xpm_file_to_image(game.mlx, "../burda.xpm", &(game.win.width), &(game.win.height));
 	create_window(&game, argv);
//	render_map(&game, argv);

//	render_floor(&game);


	mlx_key_hook(game.win.win, keycode_check, &game);




	mlx_loop(game.mlx);
	return (0);
}