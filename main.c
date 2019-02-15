#include "fillit.h"

static int		ft_map_error(void)
{
	write(1, "error map\n", 10);
	return (1);
}

static int		ft_get_tetri(char *av, char tab[26][4][4])
{
	int			fd;
	int			i;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	i = ft_check_file(fd, tab);
	close(fd);
	return (i);
}

int		main(int ac, char **av)
{
	char	tab[26][4][4];
	char	**map;
	int		nb_tetri;
	int		size_side;

	if (ac != 2)
		return (ft_map_error());						/*error no map*/
	nb_tetri = ft_get_tetri(av[1], tab);
	if (nb_tetri == 0)
		return (ft_map_error());						/*error map*/
	size_side = ft_sqrt(nb_tetri * 4);				/*size side of square*/
	map = ft_map_alloc(size_side);				/*create map empty*/
	while (!ft_finished(map, nb_tetri, tab, 0))		/*resolution*/
	{
		ft_free_map(map, size_side);				/*free map*/
		++size_side;
		map = ft_map_alloc(size_side);			/*realloc square*/
	}
	ft_print_map(map, size_side);					/*print map*/
	ft_free_map(map, size_side);					/*free map*/
	return (0);
}
