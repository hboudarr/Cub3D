/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:58 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/23 16:51:14 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_floor(t_read *args, char *str, int i)
{
	args->split = ft_split(str, ' ');
	if ((!(args->split[1])) || args->split[2])
		ft_exit5(args, str, 6);
	ft_free_split(args->split);
	i++;
	args->split = ft_split(str + i, ',');
	if ((!(args->split[2])) || args->split[3])
		ft_exit5(args, str, 6);
	ft_check_value(args->split[0], args);
	ft_check_value(args->split[1], args);
	ft_check_value(args->split[2], args);
	args->f[0] = ft_atoi(args->split[0]);
	args->f[1] = ft_atoi(args->split[1]);
	args->f[2] = ft_atoi(args->split[2]);
	args->tab[6] = 1;
	ft_get_floor_rgb(args);
	ft_free_split(args->split);
}

void	ft_get_ceiling_rgb(t_read *args)
{
	args->rgb.r = args->c[0];
	args->rgb.g = args->c[1];
	args->rgb.b = args->c[2];
	args->ceiling = args->rgb.b + args->rgb.g * 256 + args->rgb.r * 65536;
}

void	ft_get_celling(t_read *args, char *str, int i)
{
	args->split = ft_split(str, ' ');
	if ((!(args->split[1])) || args->split[2])
		ft_exit5(args, str, 7);
	ft_free_split(args->split);
	i++;
	args->split = ft_split(str + i, ',');
	if ((!(args->split[2])) || args->split[3])
		ft_exit5(args, str, 7);
	ft_check_value(args->split[0], args);
	ft_check_value(args->split[1], args);
	ft_check_value(args->split[2], args);
	args->c[0] = ft_atoi(args->split[0]);
	args->c[1] = ft_atoi(args->split[1]);
	args->c[2] = ft_atoi(args->split[2]);
	ft_get_ceiling_rgb(args);
	args->tab[7] = 1;
	ft_free_split(args->split);
}

void	ft_analyse_line(t_read *args, char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 'R')
		ft_get_resol(args, str);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_get_north(args, str, ++i);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		ft_get_south(args, str, ++i);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_get_west(args, str, ++i);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_get_east(args, str, ++i);
	else if (str[i] == 'S' && str[i + 1] == ' ')
		ft_get_sprite(args, str, i);
	else if (str[i] == 'F' && str[i + 1] == ' ')
		ft_get_floor(args, str, i);
	else if (str[i] == 'C' && str[i + 1] == ' ')
		ft_get_celling(args, str, i);
	else
		ft_exit3(args, str, 8);
}

void	ft_read(t_read *args)
{
	int		ret;
	int		i;
	char	*line;

	ret = 0;
	i = 0;
	while (i < 8)
	{
		args->tab[i] = 0;
		i++;
	}
	while (ft_check_element(args->tab) == 0)
	{
		ret = get_next_line(args->fd, &line, 0);
		if (ret == -1)
			ft_exit3(args, line, 9);
		if (ret == 0)
			ft_exit3(args, line, 9);
		if (line[0] != '\0')
			ft_analyse_line(args, line);
		free(line);
	}
}
