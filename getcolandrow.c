/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcolandrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:25:46 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/06 18:27:08 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	getcolnum(char *file, t_map *map)
{
	int		fd;
	char	buf[1];
	int		numbytes;

	fd = open(file, O_RDONLY);
	numbytes = 1;
	while (numbytes != 0)
	{
		numbytes = read(fd, buf, 1);
		if (buf[0] == '\n')
			break ;
		map->size.x++;
	}
	close(fd);
}

static	void	getrownum(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		free(line);
		map->size.y = 0;
		close(fd);
		return ;
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		map->size.y++;
	}
	free(line);
	close(fd);
}

void	getcolandrow(char *file, t_map *map)
{
	getcolnum(file, map);
	getrownum(file, map);
}
