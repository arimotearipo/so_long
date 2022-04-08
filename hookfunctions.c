/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:45 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/08 16:50:02 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	updatepos(int keycode, t_prog *prog)
{
	t_vector	newpos;

	if (keycode == ESC)
		ft_close(prog);
	newpos = prog->map.ply.pos;
	if (keycode == W)
		newpos.y--;
	else if (keycode == S)
		newpos.y++;
	else if (keycode == A)
		newpos.x--;
	else if (keycode == D)
		newpos.x++;
	return (newpos);
}

int	validmove(t_prog *prog, t_vector newpos)
{
	int	cn;

	cn = prog->map.coi.num;
	if (prog->map.arr[newpos.y][newpos.x] == '1')
		return (0);
	else if (prog->map.arr[newpos.y][newpos.x] == 'E' && cn != 0)
		return (0);
	return (1);
}

void	changepos(t_prog *prog, t_vector newpos, t_vector curpos)
{
	if (prog->map.arr[newpos.y][newpos.x] == 'E' && prog->map.coi.num == 0)
		ft_win(prog);
	prog->map.arr[newpos.y][newpos.x] = 'P';
	prog->map.arr[curpos.y][curpos.x] = '0';
}

int	move(int key, t_prog *prog)
{
	t_vector	newpos;
	t_vector	curpos;

	if (key != W && key != A && key != S && key != D && key != ESC)
		return (0);
	if (prog->movetimer == 0)
	{
		curpos = prog->map.ply.pos;
		newpos = updatepos(key, prog);
		if (!validmove(prog, newpos))
			return (0);
		prog->stepcount++;
		writesteps(prog);
		if (prog->map.arr[newpos.y][newpos.x] == 'C')
			prog->map.coi.num--;
		changepos(prog, newpos, curpos);
	}
	prog->movetimer = 4;
	return (0);
}
