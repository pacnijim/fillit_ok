#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 21

int		ft_check_file(int fd, char tab[26][4][4]);
size_t	ft_strlen(const char *str);
void	ft_putstr(const char *s);
void	ft_putchar(char c);
void	ft_stock(char buf[BUF_SIZE], char tab[4][4], int pos);
char	**ft_map_alloc(int len);
int		ft_finished(char **map, int nb_tetri, char tab[26][4][4], int tetris);
int		ft_solve_print(char **map, int nb_total, char tab[26][4][4]);
void	ft_init(int *check, int *i, int *j);
void	ft_up_left(char	tab[4][4]);
int		ft_get_offset_col(char tab[4][4]);
int		ft_get_offset_line(char tab[4][4]);
void	ft_rmoffset_line(char tab[4][4], int offset);
void	ft_rmoffset_col(char tab[4][4], int offset);
int		ft_checknext(char c, int *pos_i, int *pos_j);
int		ft_tetrifit(char tab[4][4], char **map, int x, int y);
void	ft_free_map(char **map, int size);
void	ft_addtomap(char **map, char tab[4][4], int k, int l);
int		ft_sqrt(int nb);
void	ft_print_map(char **grid, int len);

#endif
