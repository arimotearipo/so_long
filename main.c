/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:30 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/08 19:32:30 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*file;
	t_prog	prog;

	if (ac == 2)
	{
		file = av[1];
		initprog(&prog);
		if (!checkerror(file, &prog.map))
			return (0);
		buildscreen(&prog);
		freeall(prog.map.arr, prog.map.size.y);
	}
	ft_putstr_fd("To play:\n./so_long [map file]\n", 2);
	return (0);
}
