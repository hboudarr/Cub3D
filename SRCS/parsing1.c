/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:55:20 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/27 13:36:07 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_make_range(t_read *args)
{
	int		i;
	char	**tmp;

	i = 0;
	if (args->y == 1)
	{
		if (!(args->map = malloc(sizeof(char*) * (args->y + 1))))
			ft_exit3(args, args->s, 8);
		args->map[0] = args->s;
	}
	else
	{
		tmp = args->map;
		if (!(args->map = malloc(sizeof(char*) * (args->y))))
			ft_exit3(args, args->s, 8);
		while (i < args->y - 1)
		{
			args->map[i] = tmp[i];
			i++;
		}
		args->map[i] = args->s;
		free(tmp);
	}
}

void	ft_make_map(t_read *args)
{
	int		i;
	char	**tmp;

	i = 0;
	if (args->y == 1)
	{
		if (!(args->mapdup = malloc(sizeof(char *) * (args->y))))
			ft_exit3(args, args->s, 8);
		args->mapdup[0] = ft_strdup(args->s);
	}
	else
	{
		tmp = args->mapdup;
		if (!(args->mapdup = malloc(sizeof(char *) * (args->y))))
			ft_exit3(args, args->s, 8);
		while (i < args->y - 1)
		{
			args->mapdup[i] = tmp[i];
			i++;
		}
		args->mapdup[i] = ft_strdup(args->s);
		free(tmp);
	}
}

int		ft_flood_fill(char **map, int x, int y, int max)
{
	int		ret1;
	int		ret2;
	int		ret3;
	int		ret4;

	ret1 = 1;
	ret2 = 1;
	ret3 = 1;
	ret4 = 1;
	if (map[y - 1][x] == '0' || map[y - 1][x] == '2')
		ret1 = ft_checking(map, x, y - 1, max);
	if (map[y + 1][x] == '0' || map[y + 1][x] == '2')
		ret2 = ft_checking(map, x, y + 1, max);
	if (map[y][x - 1] == '0' || map[y][x - 1] == '2')
		ret3 = ft_checking(map, x - 1, y, max);
	if (map[y][x + 1] == '0' || map[y][x + 1] == '2')
		ret4 = ft_checking(map, x + 1, y, max);
	if (ret1 == 1 && ret2 == 1 && ret3 == 1 && ret4 == 1)
		return (1);
	return (0);
}

void	ft_free_map(t_read *args, char **map)
{
	int i;

	i = 0;
	while (i < args->y)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	if (map != NULL)
		free(map);
}

void	ft_read_second_part(t_read *args)
{
	int	ret;
	int i;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(args->fd, &args->s, 0);
		if (ret == -1 || (ret && args->s[0] == '\0'))
			ft_exit3(args, args->s, 8);
		if (ret == 1 || ret == 0)
		{
			args->y += 1;
			ft_analyse_str(args);
			ft_make_range(args);
			ft_make_map(args);
		}
	}
	i = ft_flood_fill(args->mapdup, args->posx, args->posy, args->y);
	if (i == 0)
		ft_exit3(args, args->s, 8);
	ft_free_map(args, args->mapdup);
	close(args->fd);
}
