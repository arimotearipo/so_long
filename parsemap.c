/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:43 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/06 17:10:44 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsemap(char *file, t_map *map)
{
	int		fd;
	int		i;
	int		len;
	char	*line;

	fd = open(file, O_RDONLY);
	i = 0;
	map->arr = malloc(sizeof(char *) * map->size.y);
	while (i < map->size.y)
	{
		line = get_next_line(fd);
		map->arr[i] = ft_strdupnonl(line);
		free(line);
		i++;
	}
	close(fd);
}
