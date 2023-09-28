#include "so_long.h"

int	is_only_one(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (0);
		i++; 
	}
	return (1);
}

void	put_block(t_game *game, char *line, )
{
	
}

void    render_map(t_game *game, char **argv)
{
	char	*area;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i <= game->win.width / SIZE)
	{
		area = get_next_line(fd);
		if (!is_only_one(area, '1'))
			ft_printf("TAVAN TUTMADI KNK");
		
	}
}