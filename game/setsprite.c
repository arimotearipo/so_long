/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:47 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/09 13:49:54 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	createsprite(t_prog *prog, t_sprite *sp, char *path)
{
	sp->r = mlx_xpm_file_to_image(prog->mlx, path, &sp->size.x, &sp->size.y);
	sp->pix = mlx_get_data_addr(&sp->r, &sp->bpp, &sp->ls, &sp->e);
}

static	void	createplayeranimationsprite(t_prog *prog, t_map *map)
{
	createsprite(prog, &map->ply0, "./sprites/plyani/ply0.xpm");
	createsprite(prog, &map->ply1, "./sprites/plyani/ply1.xpm");
	createsprite(prog, &map->ply2, "./sprites/plyani/ply2.xpm");
	createsprite(prog, &map->ply3, "./sprites/plyani/ply3.xpm");
	createsprite(prog, &map->ply4, "./sprites/plyani/ply4.xpm");
	createsprite(prog, &map->ply5, "./sprites/plyani/ply5.xpm");
}

static	void	createexitanimationsprite(t_prog *prog, t_map *map)
{
	createsprite(prog, &map->exi0, "./sprites/exiani/exi0.xpm");
	createsprite(prog, &map->exi1, "./sprites/exiani/exi1.xpm");
	createsprite(prog, &map->exi2, "./sprites/exiani/exi2.xpm");
	createsprite(prog, &map->exi3, "./sprites/exiani/exi3.xpm");
	createsprite(prog, &map->exi4, "./sprites/exiani/exi4.xpm");
	createsprite(prog, &map->exi5, "./sprites/exiani/exi5.xpm");
	createsprite(prog, &map->exi6, "./sprites/exiani/exi6.xpm");
	createsprite(prog, &map->exi7, "./sprites/exiani/exi7.xpm");
	createsprite(prog, &map->exi8, "./sprites/exiani/exi8.xpm");
}

static	void	createcoinanimationsprite(t_prog *prog, t_map *map)
{
	createsprite(prog, &map->coi0, "./sprites/coiani/coi0.xpm");
	createsprite(prog, &map->coi1, "./sprites/coiani/coi1.xpm");
	createsprite(prog, &map->coi2, "./sprites/coiani/coi2.xpm");
	createsprite(prog, &map->coi3, "./sprites/coiani/coi3.xpm");
}

void	setsprite(t_prog *prog, t_map *map)
{
	createsprite(prog, &map->ply, "./sprites/player2.xpm");
	createsprite(prog, &map->exi, "./sprites/exit.xpm");
	createsprite(prog, &map->coi, "./sprites/coiani/coi0.xpm");
	createsprite(prog, &map->flr, "./sprites/floor0.xpm");
	createsprite(prog, &map->wal, "./sprites/wall.xpm");
	createplayeranimationsprite(prog, map);
	createexitanimationsprite(prog, map);
	createcoinanimationsprite(prog, map);
}
