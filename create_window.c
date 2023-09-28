#include "so_long.h"

int find_window_width(int fd)
{
	int		width;
	int		read_byte;
	char	buffer;

	width = 0;
	read_byte = read(fd, &buffer, 1);
	while (read_byte > 0)
	{
		if (buffer != '\n' && buffer != '\0')
			width++;
		else if (buffer == '\n')
			break ;
		read_byte = read(fd, &buffer, 1);
	}
	return (width);
}

int find_window_height(int fd)
{
	int		height;
	int		read_byte;
	char	buffer;
	
	height = 1;
	read_byte = read(fd, &buffer, 1);
	if (read_byte <= 0)
		return (0);
	while (read_byte > 0)
	{
		if (buffer == '\n')
			height++;
		if (buffer == '\0')
			break;
		read_byte = read(fd, &buffer, 1);
	}
	return (height);
}

void    create_window(t_game *data, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	data->win.width = find_window_width(fd) * SIZE;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	data->win.height = find_window_height(fd) * SIZE;
	close(fd);
	ft_printf("width:%d\theight:%d\n", data->win.width, data->win.height);
	data->win.win = mlx_new_window(data->mlx, data->win.width, data->win.height, "MA GAME");
}
