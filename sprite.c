/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:55:14 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/19 15:58:54 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sort(int *order, double *dist, int num)
{
	int		i;
	int		temp;
	double	temp2;

	i = 0;
	while (i < num - 1)
	{
		if (dist[i] < dist[i + 1])
		{
			temp2 = dist[i + 1];
			dist[i + 1] = dist[i];
			dist[i] = temp2;
			temp = order[i];
			order[i] = order[i + 1];
			order[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_place_sprites(t_read *args)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < args->y)
	{
		x = 0;
		while (args->map[y][x] != '\0')
		{
			if (args->map[y][x] == '2')
			{
				args->tab_sprite[i].x = x + 0.5;
				args->tab_sprite[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_order_sprite(t_read *args)
{
	int		i;

	i = 0;
	while (i < args->nbsp)
	{
		args->sp_order[i] = i;
		args->sp_dist[i] = ((args->posx - args->tab_sprite[i].x) *
			(args->x - args->tab_sprite[i].x) +
			(args->y - args->tab_sprite[i].y) *
			(args->y - args->tab_sprite[i].y));
		i++;
	}
	ft_sort(args->sp_order, args->sp_dist, args->nbsp);
	ft_raysprite(args);
}

void	ft_sprite(t_read *args)
{
	if (!(args->tab_sprite = malloc(sizeof(t_sprite) * args->nbsp)))
		ft_exit1(args);
	ft_place_sprites(args);
	if (!(args->sp_order = malloc(sizeof(int) * args->nbsp)))
		ft_exit1(args);
	if (!(args->sp_dist = malloc(sizeof(double) * args->nbsp)))
		ft_exit1(args);
	ft_order_sprite(args);
}
