/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halimbdr <halimbdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:55:14 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/31 13:04:39 by halimbdr         ###   ########.fr       */
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
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = 0;
	j = 0;
	while (i < args->y)
	{
		while (args->map[i][j] && nb < args->nbsp)
		{
			if (args->map[i][j] == '2')
			{
				args->tab_sprite[nb].x = j + 0.5;
				args->tab_sprite[nb].y = i + 0.5;
				nb++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_order_sprite(t_read *args)
{
	int		i;

	i = 0;
	while (i < args->nbsp)
	{
		args->sp_order[i] = i;
		args->sp_dist[i] = sqrt((args->posx - args->tab_sprite[i].x) *
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
	ft_place_sprites(args);
	ft_order_sprite(args);
	ft_sort(args->sp_order, args->sp_dist, args->nbsp);
}
