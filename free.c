/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:19:20 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/20 12:14:12 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_args2(t_read *args)
{
	if (args->tex4 != NULL)
		free(args->tex4);
	if (args->sprite != NULL)
		free(args->sprite);
	free(args->tab_sprite);
	free(args->zbuffer);
	free(args->sp_order);
	free(args->sp_dist);
	if (args->map != NULL)
		ft_free_map(args, args->map);
	if (args->img != NULL)
		mlx_destroy_image(args->mlx_ptr, args->img);
	if (args->win_ptr != NULL)
		mlx_destroy_window(args->mlx_ptr, args->win_ptr);
	if (args->mlx_ptr != NULL)
		free(args->mlx_ptr);
	free(args);
}

void	ft_free_args(t_read *args)
{
	free(args->no);
	free(args->so);
	free(args->we);
	free(args->ea);
	free(args->sp);
	if (args->tex3 != NULL)
		free(args->tex3);
	if (args->tex1 != NULL)
		free(args->tex1);
	if (args->tex2 != NULL)
		free(args->tex2);
	ft_free_args2(args);
}
