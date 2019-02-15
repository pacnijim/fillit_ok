#include "fillit.h"

static int		ft_next_alpha(int j, char tab[4])
{
	while (j < 4)
	{
		if (tab[j] != '.')
			return (j);
		++j;
	}
	return (j);
}

int		ft_tetrifit(char tab[4][4], char **map, int x, int y)
{
	int i;
	int j;
	int check;

	i = 0;
	j = 0;
	check = 0;
	while (check < 4 && i < 4)
	{
		j = ft_next_alpha(j, tab[i]);
		if (j < 4)
		{
			if (++check < 4 && tab[i][j + 1] == '.')
			{
				if (!(map[x + i] && map[x + i][y + j] == '.'))
					return (0);
				j = 0 * (++i);
			}
			else if (!(map[x + i] && map[x + i][y + j++] == '.'))
				return (0);
		}
	}
	return (1);
}
