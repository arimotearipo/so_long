/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfilename.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:56 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/09 13:50:21 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkfilename(char *file)
{
	int		start;
	int		fd;
	char	*ext;
	char	*fileext;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile does not exist\n");
		return (0);
	}
	start = ft_strlen(file) - 4;
	ext = ".ber";
	fileext = ft_substr(file, start, ft_strlen(file));
	if (ft_strncmp(fileext, ext, 4) || ft_strlen(file) < 5)
	{
		ft_printf("Error\nWrong filetype\n");
		return (0);
	}
	free(fileext);
	return (1);
}
