/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myray2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:56:36 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/20 15:41:21 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_to_image(t_read *data, int x, int y, int color)
{
	*(unsigned int *)(data->addr + y * data->line_length +
			x * data->bits_per_pixel / 8) = color;
}

void	ft_wall_tex(t_read *args)
{
	double wallx;

	if (args->side == 0)
		wallx = args->posy + args->perpwalldist * args->raydiry;
	else
		wallx = args->posx + args->perpwalldist * args->raydirx;
	wallx -= (int)wallx;
	args->tex.x = (int)(wallx * args->wthtext);
	if (args->perpwalldist == 0 && args->dirx > 0)
		args->tex.x = args->wthtext - args->tex.x - 1;
	else if (args->perpwalldist == 1 && args->dirx < 0)
		args->tex.x = args->wthtext - args->tex.x - 1;
	if (args->side == 0 && args->raydirx > 0)
		args->tex.x = args->wthtext - args->tex.x - 1;
	if (args->side == 1 && args->raydiry < 0)
		args->tex.x = args->wthtext - args->tex.x - 1;
	args->tex.step_tex = 1.0 * args->hthtext / args->linehth;
	args->tex.tex_pos = (args->drawstart - args->resol[1] / 2 +
	args->linehth / 2) * args->tex.step_tex;
}

void	ft_ray1(t_read *args, int x)
{
	args->camerax = 2 * x / (double)args->resol[0] - 1;
	args->raydirx = args->dirx + args->planex * args->camerax;
	args->raydiry = args->diry + args->planey * args->camerax;
	args->mapx = (int)args->posx;
	args->mapy = (int)args->posy;
	args->hit = 0;
	args->deltadistx = sqrt(1 + (args->raydiry * args->raydiry) /
			(args->raydirx * args->raydirx));
	args->deltadisty = sqrt(1 + (args->raydirx * args->raydirx) /
			(args->raydiry * args->raydiry));
}

void	ft_ray2(t_read *args)
{
	if (args->raydirx < 0)
	{
		args->stepx = -1;
		args->sidedistx = (args->posx - args->mapx) * args->deltadistx;
	}
	else
	{
		args->stepx = 1;
		args->sidedistx = (args->mapx + 1.0 - args->posx) * args->deltadistx;
	}
	if (args->raydiry < 0)
	{
		args->stepy = -1;
		args->sidedisty = (args->posy - args->mapy) * args->deltadisty;
	}
	else
	{
		args->stepy = 1;
		args->sidedisty = (args->mapy + 1.0 - args->posy) * args->deltadisty;
	}
}

void	ft_ray3(t_read *args)
{
	while (args->hit == 0)
	{
		if (args->sidedistx < args->sidedisty)
		{
			args->sidedistx += args->deltadistx;
			args->mapx += args->stepx;
			args->side = 0;
		}
		else
		{
			args->sidedisty += args->deltadisty;
			args->mapy += args->stepy;
			args->side = 1;
		}
		if (args->map[args->mapy][args->mapx] != '0' &&
				args->map[args->mapy][args->mapx] != '2' &&
				args->map[args->mapy][args->mapx] != 'E' &&
				args->map[args->mapy][args->mapx] != 'N' &&
				args->map[args->mapy][args->mapx] != 'S' &&
				args->map[args->mapy][args->mapx] != 'W')
			args->hit = 1;
	}
}
