/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:49:01 by hboudarr          #+#    #+#             */
/*   Updated: 2020/06/08 15:57:43 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_resolution(char *str, int fd, t_read args)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'R')
		{
			i++;
			args.resol[0] = ft_atoi(&str[i]);
			printf("resol 0 : %d\n", args.resol[0]);
		}
		i++;
	}
	return (1);
}

int			ft_parse_resolution1(char *str, int fd, t_read args)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'R')
		{
			i++;
			while (is_whitespace(str[i]))
				i++;
			while (ft_isdigit(str[i]))
				i++;
			args.resol[1] = ft_atoi(&str[i]);
			printf("resol1 : %d\n", args.resol[1]);
		}
		i++;
	}
	return (1);
}

int		ft_err(int i)
{
	write(1, "Error\n", 6);
	write(1, "try again\n", 10);
	return (0);
}

void		ft_parse_tabx(int fd, t_read *args)
{
	int	ret;
	char *line;
	int		i;

	args->x = 0;
	args->y = 0;
	ret = 1;
	i = 0;
	line = args->get_line;
// ajouter la condition du flag 1 si et seulement si les donnees anterieurs sont valides.
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
			if (*line == ' ')
				line++;
			if (ft_isalpha(*line) || )
				{	
					args->y += 1;	
					args->x = (ft_strlen((char*)line) > args->x) ? ft_strlen((char*)line) : args->x;	
				}
	}
	free (line);
	close(fd);
}

void	make_scene(t_read *args, int fd)
{
	int		i;
	int		ret;

	ret = 1;
	fd = open("first.cub", O_RDONLY);
	args->map = malloc(sizeof(char*) * args->y);
	i = 0;
	while (i < args->y && ret > 0)
	{
// ajuter la conditions des flags si et seulement si tte les donnees antiereurs sont valide (resol, textures etc)		
		args->map[i] = malloc(sizeof(char*) * (args->x + 1));
		ret = get_next_line(fd, &args->get_line);
			args->map[i] = args->get_line;
	//	printf("tab = %s\n", args->map[i]);
		printf("line = %s\n", args->get_line);
//		flood_fill(args->map, "102NSWE", '9')
		free(args->get_line);
	}
	close (fd);
}

/*
void  flood_fill(char **tab, char *str, char c)
{
    char c;
    t_read p;

    c = tab[begin.y][begin.x];
    tab[begin.y][begin.x] = 'N';
    if (begin.y > 0 && tab[begin.y - 1][begin.x] == c)
    {
        p.x = begin.x;
        p.y = begin.y - 1;
        flood_fill(tab, size, p);
    }
    if ((begin.y < (size.y - 1)) && tab[begin.y + 1][begin.x] == c)
    {
        p.x = begin.x;
        p.y = begin.y + 1;
        flood_fill(tab, size, p);
    }
    if ((begin.x < (size.x - 1)) && tab[begin.y][begin.x + 1] == c)
    {
        p.x = begin.x + 1;
        p.y = begin.y;
        flood_fill(tab, size, p);
    }
    if (begin.x > 0 && tab[begin.y][begin.x - 1] == c)
    {
        p.x = begin.x - 1;
        p.y = begin.y;
        flood_fill(tab, size, p);
    }
}
*/

void		ft_parse_map(int fd, char *str)
{
	t_read	args;

	args.resol[0] = ft_parse_resolution(str, fd, args);
	args.resol[1] = ft_parse_resolution1(str, fd, args);
//	if (ft_isalpha(str[i]))
//		return (0);
//		args.x = ft_parse_tabx(str, fd, args);
//		y++;

//	args.north = ft_parse_north(str, fd, args);
}
