/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:11:03 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/09 13:50:18 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkerror(char *file, t_map *map)
{	
	if (!checkfilename(file) || !isrectangle(file, map))
		return (0);
	parsemap(file, map);
	if (!iswallenclosed(map))
	{
		ft_printf("Error\nMap is not wall enclosed\n");
		freeall(map->arr, map->size.y);
		return (0);
	}
	getinfo(map);
	if (!checkelements(map))
	{
		freeall(map->arr, map->size.y);
		return (0);
	}
	return (1);
}
