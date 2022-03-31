#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_map
{
	int		col_num;
	int 	row_num;
	int		coin_num;
	int 	player_num;
	int 	enemy_num;
	char	*arr;
} t_map;

int		checkerror(char *file, t_map *map);
char	*loadbuffer(int fd, char *initbuf, char *buffer);
char	*splittext(char	*text);
char	*get_next_line(int fd);

#endif