/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:55:20 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/07 17:20:14 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int		ft_check_alphanum(char *str, char *letter)
{
	int i;
	int	j;
	int	index;

	i = 0;
	while (str[i])
	{
		j = 0;
		index = 0;
		while (letter[j])
		{
			if (str[i] == letter[j])
				index++;
			j++;
		}
		if (index == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_orient2(t_read *args, char c)
{
	if (c == 'W')
	{
		args->dirx = -1;
		args->diry = 0;
		args->planex = 0;
		args->planey = -0.66;
	}
	if (c == 'E')
	{
		args->dirx = 1;
		args->diry = 0;
		args->planex = 0;
		args->planey = 0.66;
	}
}

void		ft_orient(t_read *args, char c)
{
	if (c == 'N')
	{
		args->dirx = 0;
		args->diry = -1;
		args->planex = 0.66;
		args->planey = 0;
	}
	if (c == 'S')
	{
		args->dirx = 0;
		args->diry = 1;
		args->planex = -0.66;
		args->planey = 0;
	}
	ft_orient2(args, c);

}

void	ft_analyse_str(t_read *args)
{
	int i;

	i = 0;
	if (ft_check_alphanum(args->s, "NSEW102 ") == 0)
			ft_error(12);
	while (args->s[i])
	{
		if (args->s[i] == 'N' || args->s[i] == 'S' || args->s[i] == 'E' || args->s[i] == 'W')
		{
			args->posy = (args->y - 1) + 0.5;
			args->posx = i + 0.5;
			args->count += 1;
			ft_orient(args, args->s[i]);
			args->s[i] = '0';
		}
		if (args->s[i] == '2')
			args->nbsp += 1;
		i++;
	}
	if (args->count > 1)
		ft_error(12);
}

void	ft_make_range(t_read *args)
{
	int 	i;
	char 	**tmp;

	i = 0;
	if (args->y == 1)
	{
		if (!(args->map = malloc(sizeof(char*) * (args->y))))
			ft_error(4);
		args->map[0] = args->s;
	}
	else
	{
		tmp = args->map;
		if (!(args->map = malloc(sizeof(char*) * (args->y))))
			ft_error(4);
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
			ft_error(4);
		args->mapdup[0] = ft_strdup(args->s);
	}
	else
	{
		tmp = args->mapdup;
		
		if (!(args->mapdup = malloc(sizeof(char *) * (args->y))))
			ft_error(4);
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
	if (y == max - 1 || y == 0 || x == 0 || (size_t)x == ft_strlen(map[y]) - 1 || map[y][x - 1] == ' '
			|| map[y][x + 1] == ' ' || (size_t)x >= ft_strlen(map[y - 1]) || 
			(size_t)x >= ft_strlen(map[y + 1]) || map[y - 1][x] == ' ' || 
			map[y + 1][x] == ' ')
		return (-1);
	map[y][x] = 'V';
	if (map[y - 1][x] == '0' || map[y - 1][x] == '2')
		ret1 = ft_flood_fill(map, x , y - 1, max);
	if (map[y + 1][x] == '0' || map[y + 1][x] == '2')
		ret2 = ft_flood_fill(map, x, y + 1, max);
	if (map[y][x - 1] == '0' || map[y][x - 1] == '2')
		ret3 = ft_flood_fill(map, x - 1, y, max);
	if (map[y][x + 1] == '0' || map[y][x + 1] == '2')
		ret4 = ft_flood_fill(map, x + 1, y, max);
	if (ret1 == 1 && ret2 == 1 && ret3 == 1 && ret4 == 1)
		return (1);
	return (0);
}
/*
void	ft_free_map(char **tab, t_read *args)
{
	int i;

	i = 0;
	while (i < args->y)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	// tab = NULL;
}
*/
void	ft_free_map(t_read *args)
{
	int i;

	i = 0;
	while (i < args->y)
	{
		free(args->mapdup[i]);
		args->mapdup[i] = NULL;
		i++;
	}
	free(args->mapdup);
	args->mapdup = NULL;
}

void	ft_read_second_part(t_read *args, int fd)
{
	int	ret;
	int 	i;

	ret = 1;
	args->y = 0;
	args->count = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &args->s);
		if (ret == -1)
			ft_error(2);
		if (ret == 1 || ret == 0)
		{
			args->y += 1;
			ft_analyse_str(args);
			ft_make_range(args);
			ft_make_map(args);
			//printf("map[%ld]\tmapdup[]\n", args->map - args->mapdup);
		}
	}
	i = ft_flood_fill(args->mapdup, args->posx, args->posy, args->y);
	if (i == -1)
		ft_error(12);
	
	if (i == -1)
		ft_error(12);
//printf("%p\n", args->map);	
//printf("%p\n", args->mapdup);	
ft_free_map(args);
	close (fd);	
}
