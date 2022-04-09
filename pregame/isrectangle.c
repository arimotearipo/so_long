/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isrectangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:11:16 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/09 13:50:36 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	isempty(t_map *map)
{
	if (map->size.x == 0 || map->size.y == 0)
	{
		ft_printf("Error\nEmpty map!\n");
		return (0);
	}
	return (1);
}

static	int	lastline(char *file, t_map *map)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i++ < (map->size.y - 1))
	{
		line = get_next_line(fd);
		free(line);
	}
	line = get_next_line(fd);
	if (ft_strchr(line, '\n'))
	{
		free(line);
		ft_printf("Error\nRemove the fucking newline at the end\n");
		close(fd);
		return (0);
	}
	free(line);
	close(fd);
	return (1);
}

int	isrectangle(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	getcolandrow(file, map);
	if (!isempty(map))
		return (0);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i++ < map->size.y)
	{
		line = get_next_line(fd);
		if (ft_strlennonl(line) != map->size.x)
		{
			free(line);
			ft_printf("Error\nNot rectangular\n");
			close(fd);
			return (0);
		}
		free(line);
	}
	if (!lastline(file, map))
		return (0);
	close(fd);
	return (1);
}
