/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:27:51 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/22 10:22:14 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_esc(t_read *args)
{
	args = 0;
} 

int		ft_key_press(int key, t_read *args)
{
	if (key == W || key == FWD)
		args->fwd = 1;
	if (key == S || key == BWD)
		args->bwd = 1;
	if (key == A)
		args->left = 1;
	if (key == D)
		args->right = 1;
	if (key == ROTLEFT)
		args->rotleft = 1;
	if (key == ROTRIGHT)
		args->rotright = 1;
	if (key == ESC)
		ft_deal_exit(args);
	return (0);
}

int		ft_key_release(int key, t_read *args)
{
	if (key == W || key == FWD)
		args->fwd = 0;
	if (key == S || key == BWD)
		args->bwd = 0;
	if (key == A)
		args->left = 0;
	if (key == D)
		args->right = 0;
	if (key == ROTLEFT)
		args->rotleft = 0;
	if (key == ROTRIGHT)
		args->rotright = 0;
	return (0);
}

void	ft_get_resol(t_read *args, char *str)
{
	int		ret;

	args->split = ft_split(str, ' ');
	if ((!(args->split[2])) || args->split[3])
		ft_exit8(args, str);
	args->resol[0] = ft_atoi(args->split[1]);
	args->resol[1] = ft_atoi(args->split[2]);
	ft_check_resolution(args->resol[0], args->resol[1], args);
	ret = ft_check_nb(args->split[1], args->split[2]);
	if (ret == -1)
		ft_exit8(args, str);
	if (args->resol[0] <= 0 || args->resol[1] <= 0)
		ft_exit8(args, str);
	args->tab[0] = 1;
	ft_free_split(args->split);
}
