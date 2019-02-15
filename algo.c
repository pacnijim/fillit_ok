#include "fillit.h"
#include <stdio.h>

static void	ft_rm_tetri(char **map, int size, char c)
{
	int 	i;
	int 	j;
	int 	check;

	i = -1;
	check = 0;
	while (++i < size && check < 4)
	{
		j = -1;
		while (++j < size && check < 4)
			if (map[i][j] == c)
			{
				map[i][j] = '.';
				++check;
			}
	}
}

static int	ft_tetris_left(char **map, int size, int nb_total)
{
	int 	nb_tetri;
	int 	i;
	int 	j;

	i = -1;
	nb_tetri = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (map[i][j] >= 'A' && map[i][j] <= 'Z')
				++nb_tetri;
	}
	return (nb_total * 4 - nb_tetri);
}

int			ft_finished(char **map, int nb_tetri, char tab[26][4][4], int tetris)
{
	int 	start;
	int 	size;
	int 	max;

	size = ft_strlen(map[0]);
	start = -1;
	if (!ft_tetris_left(map, size, nb_tetri))
		return (1);
	max = size * size - 1;
	while (++start < max)
		if (ft_tetrifit(tab[tetris], map, start / size, start % size))
		{

			ft_addtomap(map, tab[tetris], start / size, start % size);
			if (ft_finished(map, nb_tetri, tab, tetris + 1) == 1)
				return (1);
			ft_rm_tetri(map, size, tetris + 'A');

		}
	return (0);
}
