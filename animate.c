/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:04:23 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/08 18:47:07 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putanimatedplayer(t_prog *prog, t_map *map, t_vector *p)
{
	if (prog->frames < 10)
		mlx_put_image_to_window(prog->mlx,
			prog->win, map->ply0.r, p->x, p->y);
	else if (prog->frames < 20)
		mlx_put_image_to_window(prog->mlx,
			prog->win, map->ply1.r, p->x, p->y);
	else if (prog->frames < 30)
		mlx_put_image_to_window(prog->mlx,
			prog->win, map->ply2.r, p->x, p->y);
	else if (prog->frames < 40)
		mlx_put_image_to_window(prog->mlx,
			prog->win, map->ply3.r, p->x, p->y);
	else if (prog->frames < 50)
		mlx_put_image_to_window(prog->mlx,
			prog->win, map->ply4.r, p->x, p->y);
	else if (prog->frames < 60)
		mlx_put_image_to_window(prog->mlx,
			prog->win, map->ply5.r, p->x, p->y);
}

void	putanimatedexit(t_prog *prog, t_map *map, t_vector *p)
{
	if (prog->frames < 6)
		mlx_put_image_to_window(prog->mlx, prog->win, map->exi0.r, p->x, p->y);
	else if (prog->frames < 12)
		mlx_put_image_to_window(prog->mlx, prog->win, map->exi1.r, p->x, p->y);
	else if (prog->frames < 18)
		mlx_put_image_to_window(prog->mlx, prog->win, map->exi2.r, p->x, p->y);
	else if (prog->frames < 24)
		mlx_put_image_to_window(prog->mlx, prog->win, map->exi3.r, p->x, p->y);
	else if (prog->frames < 30)
		mlx_put_image_to_window(prog->mlx, prog->win, map->exi4.r, p->x, p->y);
	else if (prog->frames < 36)
		mlx_put_image_to_window(prog->mlx, prog->win, map->exi5.r, p->x, p->y);
	else if (prog->frames < 42)
		mlx_put_image_to_window(prog->mlx, prog->win, map->exi6.r, p->x, p->y);
	else if (prog->frames < 48)
		mlx_put_image_to_window(prog->mlx, prog->win, map->exi7.r, p->x, p->y);
	else if (prog->frames < 60)
		mlx_put_image_to_window(prog->mlx, prog->win, map->exi8.r, p->x, p->y);
}
