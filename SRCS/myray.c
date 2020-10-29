/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halimbdr <halimbdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:56:29 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/29 03:49:01 by halimbdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray4(t_read *args)
{
	if (args->side == 0)
		args->perpwalldist = fabs((args->mapx - args->posx +
		(1 - args->stepx) / 2) / args->raydirx);
	else
		args->perpwalldist = fabs((args->mapy - args->posy +
		(1 - args->stepy) / 2) / args->raydiry);
	args->linehth = (int)(args->resol[1] / args->perpwalldist);
	args->linehth = (args->linehth < 0) ? INT_MAX : args->linehth;
	args->drawstart = (-1 * (args->linehth)) / 2 + (args->resol[1] / 2);
	if (args->drawstart < 0)
		args->drawstart = 0;
	args->drawend = args->linehth / 2 + args->resol[1] / 2;
	if (args->drawend >= args->resol[1])
		args->drawend = args->resol[1] - 1;
}

void	ft_ray5(t_read *args, int x)
{
	args->ycoor = 0;
	while (args->ycoor < args->drawstart)
	{
		ft_draw_to_image(args, x, args->ycoor, args->ceiling);
		args->ycoor++;
	}
	while (args->ycoor <= args->drawend)
	{
		args->tex.y = (int)args->tex.tex_pos;
		args->tex.tex_pos += args->tex.step_tex;
		if (args->tex.y < 0 || args->tex.y >= args->hthtext)
			args->tex.y = (args->tex.y < 0) ? 0 : args->hthtext - 1;
		pix_color(args);
		ft_draw_to_image(args, x, args->ycoor, args->color);
		args->ycoor++;
	}
	while (args->ycoor < args->resol[1])
	{
		ft_draw_to_image(args, x, args->ycoor, args->floor);
		args->ycoor++;
	}
}

int		ft_raycasting(t_read *args)
{
	int x;

	x = 0;
	ft_sprite(args);
	while (x < args->resol[0])
	{
		ft_ray1(args, x);
		ft_ray2(args);
		ft_ray3(args);
		ft_ray4(args);
		ft_size_text(args);
		ft_wall_tex(args);
		ft_ray5(args, x);
		args->zbuffer[x] = args->perpwalldist;
		x++;
	}
	ft_raysprite(args);
	return (1);
}
