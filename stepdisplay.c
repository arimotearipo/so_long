/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepdisplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:49:43 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/08 13:16:53 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	replacestepbackground(t_prog *prog)
{
	t_vector	pos;

	pos.y = prog->map.size.y * 32;
	while (pos.y < prog->ws.y)
	{
		pos.x = 0;
		while (pos.x < prog->ws.x)
		{
			mlx_pixel_put(prog->mlx, prog->win, pos.x, pos.y, 0);
			pos.x++;
		}
		pos.y++;
	}
}

void	writesteps(t_prog *prog)
{
	t_vector	pos;
	char		*str;
	char		*count;

	count = ft_itoa(prog->stepcount);
	str = ft_strjoin("Step count: ", count);
	pos.y = prog->map.size.y * 32;
	pos.x = 16;
	replacestepbackground(prog);
	mlx_string_put(prog->mlx, prog->win, pos.x, pos.y, 0xFFFFFF, str);
	free(str);
	free(count);
}
