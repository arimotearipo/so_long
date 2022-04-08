/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:39 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/08 16:28:15 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initprog(t_prog *prog)
{
	prog->mlx = NULL;
	prog->win = NULL;
	prog->map.size.x = 0;
	prog->map.size.y = 0;
	prog->map.ply.num = 0;
	prog->map.coi.num = 0;
	prog->map.exi.num = 0;
	prog->map.invalid_char = 0;
	prog->stepcount = 0;
	prog->map.arr = NULL;
	prog->movetimer = 0;
	prog->frames = 0;
}
