/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:41:14 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/26 16:03:53 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_north(t_read *args, char *str, int i)
{
	void *tex;

	args->split = ft_split(str, ' ');
	if ((!(args->split[1]) || args->split[2]))
		ft_exit3(args, str, 1);
	ft_free_split(args->split);
	i++;
	while (str[i] == ' ')
		i++;
	args->no = ft_strdup(str + i);
	args->tab[1] = 1;
	if (!(tex = mlx_xpm_file_to_image(args->mlx_ptr, args->no,
	&args->tex1->width, &args->tex1->height)))
		ft_exit3(args, str, 1);
	mlx_destroy_image(args->mlx_ptr, tex);
}

void	ft_get_south(t_read *args, char *str, int i)
{
	void	*tex;

	args->split = ft_split(str, ' ');
	if ((!(args->split[1]) || args->split[2]))
		ft_exit3(args, str, 2);
	ft_free_split(args->split);
	i++;
	while (str[i] == ' ')
		i++;
	args->so = ft_strdup(str + i);
	args->tab[2] = 1;
	if (!(tex = mlx_xpm_file_to_image(args->mlx_ptr, args->so,
	&args->tex2->width, &args->tex2->height)))
		ft_exit3(args, str, 2);
	mlx_destroy_image(args->mlx_ptr, tex);
}

void	ft_get_west(t_read *args, char *str, int i)
{
	void *tex;

	args->split = ft_split(str, ' ');
	if ((!(args->split[1]) || args->split[2]))
		ft_exit3(args, str, 3);
	ft_free_split(args->split);
	i++;
	while (str[i] == ' ')
		i++;
	args->we = ft_strdup(str + i);
	args->tab[3] = 1;
	if (!(tex = mlx_xpm_file_to_image(args->mlx_ptr, args->we,
	&args->tex3->width, &args->tex3->height)))
		ft_exit3(args, str, 3);
	mlx_destroy_image(args->mlx_ptr, tex);
}

void	ft_get_east(t_read *args, char *str, int i)
{
	void	*tex;

	args->split = ft_split(str, ' ');
	if ((!(args->split[1]) || args->split[2]))
		ft_exit3(args, str, 4);
	ft_free_split(args->split);
	i++;
	while (str[i] == ' ')
		i++;
	args->ea = ft_strdup(str + i);
	args->tab[4] = 1;
	if (!(tex = mlx_xpm_file_to_image(args->mlx_ptr, args->ea,
	&args->tex4->width, &args->tex4->height)))
		ft_exit3(args, str, 4);
	mlx_destroy_image(args->mlx_ptr, tex);
}

void	ft_get_sprite(t_read *args, char *str, int i)
{
	void	*tex;

	args->split = ft_split(str, ' ');
	if ((!(args->split[1]) || args->split[2]))
		ft_exit3(args, str, 5);
	ft_free_split(args->split);
	i++;
	while (str[i] == ' ')
		i++;
	args->sp = ft_strdup(str + i);
	args->tab[5] = 1;
	if (!(tex = mlx_xpm_file_to_image(args->mlx_ptr, args->sp,
	&args->sprite->width, &args->sprite->height)))
		ft_exit3(args, str, 5);
	mlx_destroy_image(args->mlx_ptr, tex);
}
