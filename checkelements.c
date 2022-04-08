/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkelements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:59 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/07 21:15:53 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkelements(t_map *map)
{
	if (map->ply.num != 1)
	{
		ft_printf("Error\nNeeds one player character\n");
		return (0);
	}
	else if (map->exi.num == 0)
	{
		ft_printf("Error\nNo exit!\n");
		return (0);
	}
	else if (map->coi.num == 0)
	{
		ft_printf("Error\nNo collectibles!\n");
		return (0);
	}
	else if (map->invalid_char == 1)
	{
		ft_printf("Error\nInvalid character detected!\n");
		return (0);
	}
	return (1);
}
