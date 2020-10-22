/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:17:21 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/22 08:50:54 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	exit(1);
}

void	ft_exit4(t_read *args)
{
	write(1, "Error\nInvalid map\n", 18);
	ft_free_args(args);
	exit(1);
}

void	ft_exit5(t_read *args)
{
	write(1, "Error\nFailed to create an image\n", 32);
	ft_free_args(args);
	exit(1);
}

void	ft_exit6(t_read *args)
{
	ft_free_args(args);
	exit(1);
}

void	ft_destroy_images(t_read *args)
{
//	if (args->no)
		mlx_destroy_image(args->mlx_ptr, args->tex1->tex_ptr);
//	if (args->so)
		mlx_destroy_image(args->mlx_ptr, args->tex2->tex_ptr);
//	if (args->ea)
		mlx_destroy_image(args->mlx_ptr, args->tex3->tex_ptr);
//	if (args->we)
		mlx_destroy_image(args->mlx_ptr, args->tex4->tex_ptr);
//	if (args->sprite)
		mlx_destroy_image(args->mlx_ptr, args->sprite->tex_ptr);
}

int		ft_deal_exit(t_read *args)
{
	ft_destroy_images(args);
	if (args->img)
		mlx_destroy_image(args->mlx_ptr, args->img);
	if (args->win_ptr)
		mlx_destroy_window(args->mlx_ptr, args->win_ptr);
	if (args->mlx_ptr)
		free(args->mlx_ptr);
	//ft_free_args(args);
	exit(0);
}
