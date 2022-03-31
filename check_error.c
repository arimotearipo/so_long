#include "so_long.h"

/*
Possible errors:
File related errors:
1. Incorrect file extension
2. File does not exist
Map related errors:
3. Map is not rectangle
4. Incorrect amount of player character, exit, etc
5. Not surrounded by walls
6. Foreign indicator
*/

int	ft_strlennonl(char *s) // Need to take this function and put it in libft
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0' && s[count] != '\n')
		count++;
	return (count);
}

int	checkfilename(char *file)
{
	int		start;
	int		fd;
	char	*ext;
	char	*fileext;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: File does not exist\n");
		return (0);
	}
	start = ft_strlen(file) - 4;
	ext = ".ber";
	fileext = ft_substr(file, start, ft_strlen(file));
	if (ft_strncmp(fileext, ext, 4) || ft_strlen(file) < 5)
	{
		ft_printf("Error: Wrong filetype\n");
		return (0);
	}
	free(fileext);
	return (1);
}

int	isrectangle(char *file, t_map *map)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map->col_num = ft_strlennonl(line);
	while (line != NULL)
	{
		map->row_num += 1;
		free(line);
		line = get_next_line(fd);
		if (ft_strlennonl(line) != map->col_num && line != NULL)
		{
			ft_printf("Not rectangular\n");
			free(line);
			return (0);
		}
	}
	free(line);
	return (1);
}

int	checkerror(char *file, t_map *map)
{	
	if (!checkfilename(file))
		return (0);
	if (!isrectangle(file, map))
		return (0);
	return (1);
}
