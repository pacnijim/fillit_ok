#include "fillit.h"

void	ft_stock(char buf[BUF_SIZE], char tab[4][4], int pos)
{
	int i;
	int j;
	int k;

	k = 0;
	i = -1;
	while (++i < 4 && k < 20)
	{
		j = -1;
		while (++j < 4)
		{
			if (buf[k] == '.')
				tab[i][j] = '.';
			else if (buf[k] == '#')
				tab[i][j] = 'A' + pos;
			if (k + 1 == 4 || k + 1 == 9 || k + 1 == 14)
				++k;
			++k;
		}
	}
	ft_up_left(tab);
}
