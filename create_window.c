/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:15:02 by tkayis            #+#    #+#             */
/*   Updated: 2023/10/18 14:25:08 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_window_width(int fd)
{
	char	*line;
	int		width;

	width = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\nInvalid map!\n");
		exit(1);
	}
	while (line[width])
	{
		if (line[width] != '\n')
			width++;
		else
			break ;
	}
	free(line);
	return (width);
}

int	find_window_height(int fd)
{
	char	*line;
	int		height;

	height = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && line[0] != '\n')
			height++;
	}
	return (height);
}

void	create_window(t_game *data, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap file not found!\n");
		exit(1);
	}
	data->win.width = find_window_width(fd) * SIZE;
	close(fd);
	fd = open(argv, O_RDONLY);
	data->win.height = find_window_height(fd) * SIZE;
	close(fd);
	if (data->win.width / SIZE > 40 || data->win.height / SIZE > 21)
	{
		ft_printf("Error\nThe map is too big for the monitor!");
		exit(1);
	}
	data->win.win = mlx_new_window(data->mlx, data->win.width,
			data->win.height, "so_long");
}
