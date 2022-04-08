/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:49 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/08 18:44:27 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef ESC
#  define ESC 53
# endif
# ifndef W
#  define W 13
# endif
# ifndef A
#  define A 0
# endif
# ifndef S
#  define S 1
# endif
# ifndef D
#  define D 2
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_sprite
{
	int			num;
	t_vector	size;
	t_vector	pos;
	void		*r;
	char		*pix;
	int			bpp;
	int			ls;
	int			e;
}	t_sprite;

typedef struct s_map
{
	t_sprite	ply;
	t_sprite	ply0;
	t_sprite	ply1;
	t_sprite	ply2;
	t_sprite	ply3;
	t_sprite	ply4;
	t_sprite	ply5;
	t_sprite	wal;
	t_sprite	exi;
	t_sprite	exi0;
	t_sprite	exi1;
	t_sprite	exi2;
	t_sprite	exi3;
	t_sprite	exi4;
	t_sprite	exi5;
	t_sprite	exi6;
	t_sprite	exi7;
	t_sprite	exi8;
	t_sprite	coi;
	t_sprite	flr;
	t_vector	size;
	int			invalid_char;
	char		**arr;
}	t_map;

typedef struct s_prog
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_vector	ws;
	int			stepcount;
	int			frames;
	int			movetimer;
}	t_prog;

char		*get_next_line(int fd);
void		initprog(t_prog *prog);
int			checkerror(char *file, t_map *map);
int			checkfilename(char *file);
void		getcolandrow(char *file, t_map *map);
int			iswallenclosed(t_map *map);
int			isrectangle(char *file, t_map *map);
void		getinfo(t_map *map);
int			checkelements(t_map *map);
void		setsprite(t_prog *prog, t_map *map);
void		parsemap(char *file, t_map *map);
void		buildscreen(t_prog *prog);
void		animate(t_prog *prog);
void		writesteps(t_prog *prog);
int			move(int keycode, t_prog *prog);
void		freeall(char **arr, int rownum);
int			ft_close(t_prog *prog);
void		ft_win(t_prog *prog);
void		putanimatedplayer(t_prog *prog, t_map *map, t_vector *p);
void		putanimatedexit(t_prog *prog, t_map *map, t_vector *p);

#endif