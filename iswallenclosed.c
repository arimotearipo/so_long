/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iswallenclosed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:11:19 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/06 17:11:20 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	iswallenclosed(t_map *map)
{
	int	i;

	i = 0;
	while (map->arr[0][i] != '\0')
	{
		if (map->arr[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map->arr[map->size.y - 1][i] != '\0')
	{
		if (map->arr[map->size.y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < (map->size.y - 1))
	{
		if (map->arr[i][0] != '1' || map->arr[i][map->size.x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
