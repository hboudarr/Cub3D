/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:27:51 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/19 17:29:13 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_esc(t_read *args)
{
	args = 0;
	//exit(1);
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
