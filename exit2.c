/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:17:30 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/19 17:18:33 by hboudarr         ###   ########.fr       */
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
