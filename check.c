#include "fillit.h"

static int		ft_test_char(char c)
{
	return (c == '.' || c == '#' || c == '\n' ? 1 : 0);
}

static int		ft_count_sgn(char buf[BUF_SIZE])
{
	int 		i;
	int 		n;

	n = 0;
	i = -1;
	while (++i < 20)
		if (buf[i] == '#')
			++n;
	return (n == 4 ? 1 : 0);
}

static int		ft_test_bloc(char buf[BUF_SIZE])
{
	int 		i;
	int 		check;
	int 		prev;

	i = -1;
	check = 0;
	while (++i < 20 && check < 3)
	{
		prev = check;
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#')
				++check;
			if (buf[i + 5] == '#')
				++check;
			if (prev == 2 && check == 2)
				continue ;
			else if (prev == check)
				return (0);
		}
	}
	return (check != 3 ? 0 : 1);
}

static int		ft_check(char buf[BUF_SIZE], int n_read, int i)
{
	while (i < n_read)
		if (ft_test_char(buf[i++]) == 0)
			return (0);
	if (n_read == 21 && buf[i - 1] != '\n')
		return (0);
	n_read == 21 ? --i : i;
	while (i > 0)
	{
		if (buf[i - 1] != '\n')
			return (0);
		i -= 5;
	}
	if (ft_count_sgn(buf) == 0)
		return (0);
	return (ft_test_bloc(buf) == 0 ? 0 : 1);
}

int				ft_check_file(int fd, char tab[26][4][4])
{
	char		buf[BUF_SIZE];
	int			n_read;
	int			prev;
	int			pos;

	pos = 0;
	while ((n_read = read(fd, buf, BUF_SIZE)) == 21 || n_read == 20)
	{
		if ((ft_check(buf, n_read, 0)) == 0)
			return (0);
		ft_stock(buf, tab[pos], pos);
		++pos;
		if (pos > 26)
			return (0);
		prev = n_read;
	}
	return (n_read != 0 || prev != 20 ? 0 : pos);
}
