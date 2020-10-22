/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myspriteray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:56:44 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/22 10:20:38 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sp1(t_read *args, t_spcast *spcast)
{
	spcast->spritex = args->tab_sprite
	[args->sp_order[spcast->i]].x - args->posx;
	spcast->spritey = args->tab_sprite
	[args->sp_order[spcast->i]].y - args->posy;
	spcast->invdet = 1 / (args->planex * args->diry -
	args->dirx * args->planey);
	spcast->transformx = spcast->invdet * (args->diry * spcast->spritex
	- args->dirx * spcast->spritey);
	spcast->transformy = spcast->invdet * (-args->planey *
	spcast->spritex + args->planex * spcast->spritey);
	spcast->sp_screenx = ((args->resol[0] / 2) * (1 +
	spcast->transformx / spcast->transformy));
	spcast->sp_height = (fabs(args->resol[1] / spcast->transformy));
	spcast->draw_starty = -spcast->sp_height / 2 + args->resol[1] / 2;
}

void	ft_sp2(t_read *args, t_spcast *spcast)
{
	if (spcast->draw_starty < 0)
		spcast->draw_starty = 0;
	spcast->draw_endy = spcast->sp_height / 2 + args->resol[1] / 2;
	if (spcast->draw_endy >= args->resol[1])
		spcast->draw_endy = args->resol[1];
	spcast->sp_width = (fabs(args->resol[1] / spcast->transformy));
	spcast->draw_startx = -spcast->sp_width / 2 + spcast->sp_screenx;
	if (spcast->draw_startx < 0)
		spcast->draw_startx = 0;
	spcast->draw_endx = spcast->sp_width / 2 + spcast->sp_screenx;
	if (spcast->draw_endx >= args->resol[0])
		spcast->draw_endx = args->resol[0];
	spcast->x = spcast->draw_startx;
}

void	ft_sp3(t_read *args, t_spcast *spcast)
{
	while (spcast->y < spcast->draw_endy)
	{
		spcast->d = spcast->y - args->resol[1] / 2 + spcast->sp_height / 2;
		spcast->texy = ((spcast->d * args->sprite->height) / spcast->sp_height);
		args->color = (unsigned int)args->sprite->tex_data[args->sprite->width *
		(int)spcast->texy + (int)spcast->texx];
		if ((args->color & 0x00FFFFFF) != 0x00FFFFFF)
			ft_draw_to_image(args, spcast->x, spcast->y, args->color);
		spcast->y++;
	}
}

void	ft_sp4(t_read *args, t_spcast *spcast)
{
	while (spcast->x < spcast->draw_endx)
	{
		spcast->texx = ((spcast->x - (-spcast->sp_width / 2 +
		spcast->sp_screenx)) * args->sprite->width / spcast->sp_width);
		if (spcast->transformy > 0 && spcast->x >= 0
		&& spcast->x < args->resol[0]
		&& spcast->transformy < args->zbuffer[spcast->x])
		{
			spcast->y = spcast->draw_starty;
			ft_sp3(args, spcast);
		}
		spcast->x++;
	}
}

void	ft_raysprite(t_read *args)
{
	t_spcast	*spcast;
	t_spcast	struct_spcast;

	spcast = &struct_spcast;
	spcast->i = 0;
	while (spcast->i < args->nbsp)
	{
		ft_sp1(args, spcast);
		ft_sp2(args, spcast);
		ft_sp4(args, spcast);
		spcast->i++;
	}
	free(args->tab_sprite);
	free(args->sp_order);
	free(args->sp_dist);
}
