/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_linux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:27:58 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/23 17:06:03 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_key_press(int key, t_read *args)
{
	if (key == 119)
		args->fwd = 1;
	if (key == 97)
		args->left = 1;
	if (key == 100)
		args->right = 1;
	if (key == 115)
		args->bwd = 1;
	if (key == 65364)
		args->bwd = 1;
	if (key == 65361)
		args->rotleft = 1;
	if (key == 65363)
		args->rotright = 1;
	if (key == 65362)
		args->fwd = 1;
	if (key == 65307)
		ft_deal_exit(args);
	return (0);
}

int		ft_key_release(int key, t_read *args)
{
	if (key == 119)
		args->fwd = 0;
	if (key == 97)
		args->left = 0;
	if (key == 100)
		args->right = 0;
	if (key == 115)
		args->bwd = 0;
	if (key == 65364)
		args->bwd = 0;
	if (key == 65361)
		args->rotleft = 0;
	if (key == 65363)
		args->rotright = 0;
	if (key == 65362)
		args->fwd = 0;
	return (0);
}

void	ft_get_resol(t_read *args, char *str)
{
	int		ret;
	int		screenx_max;
	int		screeny_max;

	args->split = ft_split(str, ' ');
	if ((!(args->split[2])) || args->split[3])
		ft_exit5(args, str, 0);
	args->resol[0] = ft_atoi(args->split[1]);
	args->resol[1] = ft_atoi(args->split[2]);
	ret = ft_check_nb(args->split[1], args->split[2]);
	if (ret == -1)
		ft_exit5(args, str, 0);
	mlx_get_screen_size(args->mlx_ptr, &screenx_max, &screeny_max);
	if (args->resol[0] <= 0 || args->resol[1] <= 0)
		ft_exit5(args, str, 0);
	if (args->resol[0] > screenx_max)
		args->resol[0] = screenx_max;
	if (args->resol[1] > screeny_max)
		args->resol[1] = screeny_max;
	args->tab[0] = 1;
	ft_free_split(args->split);
}
