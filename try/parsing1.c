/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:55:20 by hboudarr          #+#    #+#             */
/*   Updated: 2020/06/12 17:56:48 by hboudarr         ###   ########.fr       */
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

void	ft_analyse_str(t_read *args)
{
	int i;

	i = 0;
	if (ft_check_alphanum(args->s, "NSEW102 ") == 0)
			ft_error(12);
	while (args->s[i])
	{
		if (args->s[i] == 'N' || args->s[i] == 'S' || args->s[i] == 'E' || args->s[i] == 'W')
			args->count += 1;
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

void	ft_read_second_part(t_read *args, int fd)
{
	int	ret;
//	int 	i;

	ret = 1;
//	args->x = 0;
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
//			args->x = (ft_strlen((char*)args->s) > (unsigned long)args->x) ? 
//				ft_strlen((char*)args->s) : args->x;
			ft_analyse_str(args);
			ft_make_range(args);
		}
	}
//	i = 0;
//	while (i < args->y)
//	{
//		printf("map = %s\n", args->map[i]);
//	i++;	
//	}
	close (fd);	
//	ft_make_range(args, fd, av);
		printf("y = %d\n", args->y);
//		printf("x = %d\n", args->x);
}
