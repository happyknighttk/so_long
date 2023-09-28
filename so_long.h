#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53
# define SIZE	64

typedef struct s_player
{
	int	x;
	int	y;

}	t_player;

typedef struct s_image
{
	char	*relative_path;
	char	*name;
	void	*img;
	int		img_width;
	int		img_height;

} t_image;


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

}	t_game;

void	create_window(t_game *data, char **argv);
void    render_map(t_game *game, char **argv);
# endif