/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:37 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/09 13:49:50 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	putsprite(char c, t_prog *prog, t_map *map, t_vector *p)
{
	mlx_put_image_to_window(prog->mlx, prog->win, map->flr.r, p->x, p->y);
	if (c == '1')
		mlx_put_image_to_window(prog->mlx, prog->win, map->wal.r, p->x, p->y);
	else if (c == 'P')
		putanimatedplayer(prog, map, p);
	else if (c == 'E')
		putanimatedexit(prog, map, p);
	else if (c == 'C')
		putanimatedcoin(prog, map, p);
}

static	void	saveposition(char c, t_map *map, int y, int x)
{
	static int	i;

	i = 0;
	if (c == 'P')
	{
		map->ply.pos.x = x;
		map->ply.pos.y = y;
	}
	else if (c == 'E')
	{
		map->exi.pos.x = x;
		map->exi.pos.y = y;
	}
}

static	void	putimages(t_prog *prog)
{
	t_vector	ind;
	t_vector	pixel;

	ind.x = 0;
	pixel.x = 0;
	pixel.y = 0;
	while (ind.x < prog->map.size.y)
	{
		if (prog->movetimer > 0)
			prog->movetimer--;
		ind.y = 0;
		while (ind.y < prog->map.size.x)
		{
			putsprite(prog->map.arr[ind.x][ind.y], prog, &prog->map, &pixel);
			saveposition(prog->map.arr[ind.x][ind.y], &prog->map, ind.x, ind.y);
			ind.y++;
			pixel.x += 32;
		}
		ind.x++;
		pixel.x = 0;
		pixel.y += 32;
	}
}

static	int	renderscreen(t_prog *prog)
{
	prog->frames++;
	putimages(prog);
	if (prog->frames >= 59)
		prog->frames = 0;
	return (0);
}

void	buildscreen(t_prog *prog)
{
	char	*n;

	n = "So Long";
	prog->ws.x = prog->map.size.x * 32;
	prog->ws.y = prog->map.size.y * 32 + 32;
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, prog->ws.x, prog->ws.y, n);
	setsprite(prog, &prog->map);
	mlx_hook(prog->win, 17, 0, &ft_close, prog);
	mlx_loop_hook(prog->mlx, &renderscreen, prog);
	mlx_key_hook(prog->win, move, prog);
	mlx_loop(prog->mlx);
}
