/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:17:18 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/19 15:54:27 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_check_element(int tab[8])
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (tab[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_nb(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] < 48 || str1[i] > 57)
			return (-1);
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		if (str2[i] < 48 || str2[i] > 57)
			return (-1);
		i++;
	}
	return (1);
}

void	ft_check_resolution(int i, int j, t_read *args)
{
	if (i < 0 || i > 2000)
		ft_exit3(args, 0);
	if (j < 0 || j > 2570)
		ft_exit3(args, 0);
}

void	ft_get_resol(t_read *args, char *str)
{
	int		ret;
	// int	screenx_max;
	// int	screeny_max;

	args->split = ft_split(str, ' ');
	if ((!(args->split[2])) || args->split[3])
		ft_exit3(args, 0);
	args->resol[0] = ft_atoi(args->split[1]);
	args->resol[1] = ft_atoi(args->split[2]);
	ft_check_resolution(args->resol[0], args->resol[1], args);
	ret = ft_check_nb(args->split[1], args->split[2]);
	if (ret == -1)
		ft_exit3(args, 0);
//	mlx_get_screen_size(args->mlx_ptr, &screenx_max, &screeny_max);
	if (args->resol[0] <= 0 || args->resol[1] <= 0)
		ft_exit3(args, 0);
//	if (args->resol[0] > screenx_max)
//		args->resol[0] = screenx_max;
//	if (args->resol[1] > screeny_max)
//		args->resol[1] = screeny_max;
	args->tab[0] = 1;
	ft_free_split(args->split);
}
