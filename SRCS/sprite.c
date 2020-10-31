/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halimbdr <halimbdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:55:14 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/29 22:36:45 by halimbdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sort(int *order, double *dist, int num)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (num && i < num)
	{
		while (num && j < num)
		{
			if (dist[j] < dist[i])
			{
				ft_swap(&order[i], &order[j]);
				ft_dblswap(&dist[i], &dist[j]);
			}
			j++;
		}
		i++;
		j = i;
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
			(args->posx - args->tab_sprite[i].x) +
			(args->posy - args->tab_sprite[i].y) *
			(args->posy - args->tab_sprite[i].y));
		i++;
	}
}

void	ft_sprite(t_read *args)
{
	if (!(args->tab_sprite = malloc(sizeof(t_sprite) * args->nbsp)))
		ft_exit4(args, 1);
	if (!(args->sp_order = malloc(sizeof(int) * args->nbsp)))
		ft_exit4(args, 2);
	if (!(args->sp_dist = malloc(sizeof(double) * args->nbsp)))
		ft_exit4(args, 3);
	ft_order_sprite(args);
	ft_sort(args->sp_order, args->sp_dist, args->nbsp);
	ft_place_sprites(args);
}
