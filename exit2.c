/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:17:30 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/22 10:24:18 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit1(t_read *args)
{
	write(1, "Error\nImpossible to read cub file or to set up the game", 55);
	write(1, ", program stopped\n", 18);
	ft_free_args(args);
	ft_init(args);
	exit(1);
}

void	ft_exit2(void)
{
	write(1, "Error\nInvalid arguments\n", 24);
	exit(1);
}

void	ft_exit7(t_read *args)
{
	write(1, "Error\nImpossible to read cub file or to set up the game", 55);
	write(1, ", program stopped\n", 18);
	ft_free_args(args);
	ft_init(args);
	exit(1);
}

void	ft_exit8(t_read *args, char *str)
{
	write(1, "Error\nImpossible to read cub file or to set up the game", 55);
	write(1, ", program stopped\n", 18);
	free(str);
	ft_free_args(args);
	ft_init(args);
	exit(1);
}

void	ft_exit9(t_read *args)
{
	write(1, "Error\nImpossible to read cub file or to set up the game", 55);
	write(1, ", program stopped\n", 18);
	ft_free_args(args);
	ft_init(args);
	exit(1);
}
