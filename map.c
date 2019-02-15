#include "fillit.h"

void	ft_free_map(char **map, int size)
{
	int i;

	i = -1;
	while (++i < size)
		free(map[i]);
	free(map);
}

void	ft_addtomap(char **map, char tab[4][4], int k, int l)
{
	int	i;
	int j;
	int	check;

	i = 0;
	check = 0;
	while (map[k] && check < 4)
	{
		j = -1;
		while (++j < 4)
			if (map[k][l + j] == '.' && (tab[i][j] >= 'A' && tab[i][j] <= 'Z'))
			{
				map[k][l + j] = tab[i][j];
				++check;
			}
		++i;
		++k;
	}
}

char	**ft_map_alloc(int len)
{
	char	**map;
	int		i;
	int		j;
	int		set_o;

	i = -1;
	j = len + 1;
	if (!len)
		return (NULL);
	if (!(map = (char **)malloc(sizeof(char *) * (j))))
		return (NULL);
	while (++i < len)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (j))))
			return (NULL);
		set_o = -1;
		while (++set_o < len)
			map[i][set_o] = '.';
		map[i][set_o] = 0;
	}
	map[len] = 0;
	return (map);
}

void	ft_print_map(char **grid, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, grid[i], len);
		write(1, "\n", 1);
		i++;
	}
}
