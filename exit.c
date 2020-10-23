/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:17:21 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/22 10:38:45 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	ft_exit3(t_read *args, int nb)
{
	if (nb == 0)
		write(1, "Error\nResolution information incorrect\n", 39);
	if (nb == 1)
		write(1, "Error\nNorth texture information incorrect\n", 42);
	if (nb == 2)
		write(1, "Error\nSouth texture information incorrect\n", 42);
	if (nb == 3)
		write(1, "Error\nWest texture information incorrect\n", 41);
	if (nb == 4)
		write(1, "Error\nEast texture information incorrect\n", 41);
	if (nb == 5)
		write(1, "Error\nSprite texture information incorrect\n", 43);
	if (nb == 6)
		write(1, "Error\nFloor color information incorrect\n", 40);
	if (nb == 7)
		write(1, "Error\nCell color information incorrect\n", 39);
	if (nb == 8)
		write(1, "Error\nResolution <= 0\n", 22);
	ft_free_args(args);
	ft_init(args);
	exit(1);
}

void	ft_exit4(t_read *args)
{
	write(1, "Error\nInvalid map\n", 18);
	ft_free_args(args);
	ft_init(args);
	exit(1);
}

void	ft_exit5(t_read *args)
{
	write(1, "Error\nFailed to create an image\n", 32);
	ft_free_args(args);
	ft_init(args);
	exit(1);
}

void	ft_exit6(t_read *args)
{
	ft_free_args(args);
	ft_init(args);
	exit(1);
}*/

int		ft_deal_exit(t_read *args)
{
	ft_free_args(args);
//	ft_init(args);
	exit(1);
}
