/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:11:11 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/09 13:50:30 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	saveplayerinfo(t_map *map, t_vector i)
{
	map->ply.num += 1;
	map->ply.pos.x = i.x;
	map->ply.pos.y = i.y;
}

void	getinfo(t_map *map)
{
	t_vector		i;
	char			*elements;

	elements = "10CPE";
	i.x = 0;
	while (i.x < map->size.y)
	{
		i.y = 0;
		while (i.y < map->size.x)
		{
			if (map->arr[i.x][i.y] == 'C')
				map->coi.num += 1;
			else if (map->arr[i.x][i.y] == 'P')
				saveplayerinfo(map, i);
			else if (map->arr[i.x][i.y] == 'E')
				map->exi.num += 1;
			else if (!ft_strchr(elements, map->arr[i.x][i.y]))
				map->invalid_char = 1;
			i.y++;
		}
		i.x++;
	}
}
