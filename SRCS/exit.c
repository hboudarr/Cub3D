/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:17:21 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/27 10:42:16 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit1(t_read *args)
{
	write(1, "Error\nImpossible to read cub file or to set up the game", 55);
	write(1, ", program stopped\n", 18);
	ft_free_args(args);
	exit(1);
}

void	ft_exit2(void)
{
	write(1, "Error\nInvalid arguments\n", 24);
	exit(1);
}

void	ft_error(int nb)
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
		write(1, "Error\nInvalid Map\n", 18);
	if (nb == 9)
		write(1, "Error\nImpossible to read cub file", 33);
	if (nb == 10)
		write(1, "Error\nWrong allocation for Malloc\n", 34);
}

void	ft_exit3(t_read *args, char *str, int nb)
{
	ft_error(nb);
	write(1, "program stopped\n", 16);
	free(str);
	get_next_line(args->fd, &str, 1);
	close(args->fd);
	ft_free_map(args, args->mapdup);
	ft_free_args(args);
	exit(1);
}

void	ft_exit4(t_read *args, int nb)
{
	if (nb == 1)
	{
		ft_error(10);
		free(args->tab_sprite);
		ft_free_args(args);
		exit(1);
	}
	if (nb == 2)
	{
		ft_error(10);
		free(args->tab_sprite);
		free(args->sp_order);
		ft_free_args(args);
		exit(1);
	}
	if (nb == 3)
	{
		ft_error(10);
		free(args->tab_sprite);
		free(args->sp_order);
		free(args->sp_dist);
		ft_free_args(args);
		exit(1);
	}
}
