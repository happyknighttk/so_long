#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

 								 #include <stdio.h>  //UNUTMA ORTAKK

# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53
# define SIZE	64

typedef struct s_player
{
	int	player_collect;
	int player_move;
	int	x;
	int	y;

}	t_player;

typedef struct s_image
{
	char	*path;
	void	*image;
	int		img_width;
	int		img_height;

}	t_image;


typedef struct s_window
{
	int		width;
	int		height;
	void	*win;

}	t_window;

typedef struct s_game
{
	void		*mlx;
	t_window	win;
	t_player	player;
	t_image 	img;
	char		**map;
	int			x;
	int			y;
	int			collectible_flag;
	int			player_flag;
	int			exit_flag;

}	t_game;

void	create_window(t_game *data, char *argv);
void    render_map(t_game *game, char *argv);
void    exit_or_error(char *str, t_game *game);
void	map_check(t_game *game, char *argv);
void	player_move_up(t_game *game);
void	player_move_down(t_game *game);
void	player_move_left(t_game *game);
void	player_move_right(t_game *game);



# endif