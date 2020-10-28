/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:55:14 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/28 14:58:37 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_dblswap(double *a, double *b)
{
	double	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_sort(int *order, double *dist, int num)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < num)
	{
		while (j < num)
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
		args->sp_dist[i] = sqrt((args->posx - args->tab_sprite[i].x) *
			(args->x - args->tab_sprite[i].x) +
			(args->y - args->tab_sprite[i].y) *
			(args->y - args->tab_sprite[i].y));
		i++;
	}
//	ft_sort(args->sp_order, args->sp_dist, args->nbsp);
	//ft_raysprite(args);
}

void	ft_sprite(t_read *args)
{
/*	if (!(args->tab_sprite = malloc(sizeof(t_sprite) * args->nbsp)))
		ft_exit4(args, 1);
	ft_place_sprites(args);*/
	if (!(args->tab_sprite = malloc(sizeof(t_sprite) * args->nbsp)))
		ft_exit4(args, 1);
	if (!(args->sp_order = malloc(sizeof(int) * args->nbsp)))
		ft_exit4(args, 2);
	if (!(args->sp_dist = malloc(sizeof(double) * args->nbsp)))
		ft_exit4(args, 3);
	ft_order_sprite(args);
	ft_sort(args->sp_order, args->sp_dist, args->nbsp);
	ft_place_sprites(args);
	ft_raysprite(args);
}
