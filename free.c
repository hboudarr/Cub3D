/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:19:20 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/23 17:12:37 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_args2(t_read *args)
{
	if (args->tex1 != NULL)
		free(args->tex1);
	if (args->tex2 != NULL)
		free(args->tex2);
	if (args->tex4 != NULL)
		free(args->tex4);
	if (args->sprite != NULL)
		free(args->sprite);
	if (args->zbuffer != NULL)
		free(args->zbuffer);
	if (args->map != NULL)
		ft_free_map(args, args->map);
	if (args->img)
		mlx_destroy_image(args->mlx_ptr, args->img);
	if (args->win_ptr != NULL)
		mlx_destroy_window(args->mlx_ptr, args->win_ptr);
	if (args->mlx_ptr != NULL)
		free(args->mlx_ptr);
	free(args);
}

void	ft_free_args(t_read *args)
{
	if (args->no != NULL)
		free(args->no);
	if (args->so != NULL)
		free(args->so);
	if (args->we != NULL)
		free(args->we);
	if (args->ea != NULL)
		free(args->ea);
	if (args->sp != NULL)
		free(args->sp);
	if (args->tex1->tex_ptr != NULL)
		mlx_destroy_image(args->mlx_ptr, args->tex1->tex_ptr);
	if (args->tex2->tex_ptr != NULL)
		mlx_destroy_image(args->mlx_ptr, args->tex2->tex_ptr);
	if (args->tex3->tex_ptr != NULL)
		mlx_destroy_image(args->mlx_ptr, args->tex3->tex_ptr);
	if (args->tex4->tex_ptr != NULL)
		mlx_destroy_image(args->mlx_ptr, args->tex4->tex_ptr);
	if (args->sprite->tex_ptr != NULL)
		mlx_destroy_image(args->mlx_ptr, args->sprite->tex_ptr);
	if (args->tex3 != NULL)
		free(args->tex3);
	ft_free_args2(args);
}

int		ft_check_arg(char *str)
{
	char	cmp[7];
	int		i;

	cmp[0] = '-';
	cmp[1] = '-';
	cmp[2] = 's';
	cmp[3] = 'a';
	cmp[4] = 'v';
	cmp[5] = 'e';
	cmp[6] = '\0';
	i = 0;
	if (ft_strlen(str) != 6)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != cmp[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_init2(t_read *args)
{
	args->f[0] = -1;
	args->f[1] = -1;
	args->f[2] = -1;
	args->c[0] = -1;
	args->c[1] = -1;
	args->c[2] = -1;
	args->rgb.r = 0;
	args->rgb.g = 0;
	args->rgb.b = 0;
}
