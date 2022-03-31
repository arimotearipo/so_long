#include "so_long.h"

t_map	*initmap(void)
{
	t_map *map;
	map->col_num = 0;
	map->row_num = 0;
	map->coin_num = 0;
	map->player_num = 0;
	map->enemy_num = 0;
	map->arr = NULL;
	return (map);
}

int	main(int ac, char **av)
{
	char 	*file;
	t_map	*map;

	if (ac != 2)
		return (0);
	file = av[1];
	map = initmap();
	if (!checkerror(file, map))
	{
		printf("JHAGDSJKASKDHAKJSDH\n");
		// system("leaks so_long");
		return (0);
	}
	// system("leaks so_long");
	return (0);
}