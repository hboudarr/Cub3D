/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_linux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halimbdr <halimbdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:27:58 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/19 22:14:00 by halimbdr         ###   ########.fr       */
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
	if (key == 122)
		args->ktab[0] = 1;
	if (key == 115)
		args->ktab[1] = 1;
	if (key == 113)
		args->ktab[2] = 1;
	if (key == 100)
		args->ktab[3] = 1;
	if (key == 65363)
		args->ktab[4] = 1;
	if (key == 65361)
		args->ktab[5] = 1;
	if (key == 65505)
		args->ktab[6] = 1;
	if (key == 65307)
		ft_deal_exit(args);
	return (0);
}

int		ft_key_release(int key, t_read *args)
{
	if (key == 122)
		args->ktab[0] = 0;
	if (key == 115)
		args->ktab[1] = 0;
	if (key == 113)
		args->ktab[2] = 0;
	if (key == 100)
		args->ktab[3] = 0;
	if (key == 65363)
		args->ktab[4] = 0;
	if (key == 65361)
		args->ktab[5] = 0;
	if (key == 65505)
		args->ktab[6] = 0;
	return (0);
}

void	ft_get_resol(t_read *args, char *str)
{
	int		ret;
	int		screenx_max;
	int		screeny_max;

	args->split = ft_split(str, ' ');
	if ((!(args->split[2])) || args->split[3])
		ft_exit3(args, 0);
	args->resol[0] = ft_atoi(args->split[1]);
	args->resol[1] = ft_atoi(args->split[2]);
	ft_check_resolution(args->resol[0], args->resol[1], args);
	ret = ft_check_nb(args->split[1], args->split[2]);
	if (ret == -1)
		ft_exit3(args, 0);
	mlx_get_screen_size(args->mlx_ptr, &screenx_max, &screeny_max);
	if (args->resol[0] <= 0 || args->resol[1] <= 0)
		ft_exit3(args, 0);
	if (args->resol[0] > screenx_max)
		args->resol[0] = screenx_max;
	if (args->resol[1] > screeny_max)
		args->resol[1] = screeny_max;
	args->tab[0] = 1;
	ft_free_split(args->split);
}
