/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_linux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:27:58 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/19 17:29:43 by hboudarr         ###   ########.fr       */
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
