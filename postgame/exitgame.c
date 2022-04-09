/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:32:37 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/09 13:50:09 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	ft_destroy_ply_img(t_prog *prog)
{
	mlx_destroy_image(prog->mlx, prog->map.ply.r);
	mlx_destroy_image(prog->mlx, prog->map.ply0.r);
	mlx_destroy_image(prog->mlx, prog->map.ply1.r);
	mlx_destroy_image(prog->mlx, prog->map.ply2.r);
	mlx_destroy_image(prog->mlx, prog->map.ply3.r);
	mlx_destroy_image(prog->mlx, prog->map.ply4.r);
	mlx_destroy_image(prog->mlx, prog->map.ply5.r);
}

static	void	ft_destroy_exi_img(t_prog *prog)
{
	mlx_destroy_image(prog->mlx, prog->map.exi.r);
	mlx_destroy_image(prog->mlx, prog->map.exi0.r);
	mlx_destroy_image(prog->mlx, prog->map.exi1.r);
	mlx_destroy_image(prog->mlx, prog->map.exi2.r);
	mlx_destroy_image(prog->mlx, prog->map.exi3.r);
	mlx_destroy_image(prog->mlx, prog->map.exi4.r);
	mlx_destroy_image(prog->mlx, prog->map.exi5.r);
	mlx_destroy_image(prog->mlx, prog->map.exi6.r);
	mlx_destroy_image(prog->mlx, prog->map.exi7.r);
}

static	void	ft_destroy_others(t_prog *prog)
{
	mlx_destroy_image(prog->mlx, prog->map.coi.r);
	mlx_destroy_image(prog->mlx, prog->map.flr.r);
	mlx_destroy_image(prog->mlx, prog->map.wal.r);
}

void	ft_win(t_prog *prog)
{
	ft_printf("You win in %d steps :D\n", prog->stepcount);
	ft_close(prog);
}

int	ft_close(t_prog *prog)
{
	mlx_destroy_window(prog->mlx, prog->win);
	ft_destroy_others(prog);
	ft_destroy_ply_img(prog);
	ft_destroy_exi_img(prog);
	freeall(prog->map.arr, prog->map.size.y);
	exit(0);
}
