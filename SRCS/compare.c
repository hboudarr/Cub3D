/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halimbdr <halimbdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:50:00 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/29 14:21:46 by halimbdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	if ((size_t)i == ft_strlen(s1) || (size_t)i == ft_strlen(s2))
		return (1);
	return (0);
}

void	ft_compare(t_read *args)
{
	if (ft_strcmp(args->no, args->so))
		return (ft_exit3(args, args->s, 2));
	if (ft_strcmp(args->no, args->we))
		return (ft_exit3(args, args->s, 3));
	if (ft_strcmp(args->no, args->ea))
		return (ft_exit3(args, args->s, 4));
	if (ft_strcmp(args->no, args->sp))
		return (ft_exit3(args, args->s, 5));
	if (ft_strcmp(args->so, args->we))
		return (ft_exit3(args, args->s, 3));
	if (ft_strcmp(args->so, args->ea))
		return (ft_exit3(args, args->s, 4));
	if (ft_strcmp(args->so, args->sp))
		return (ft_exit3(args, args->s, 5));
	if (ft_strcmp(args->we, args->ea))
		return (ft_exit3(args, args->s, 4));
	if (ft_strcmp(args->we, args->sp))
		return (ft_exit3(args, args->s, 5));
	if (ft_strcmp(args->ea, args->sp))
		return (ft_exit3(args, args->s, 5));
}

void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_dblswap(double *a, double *b)
{
	double	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_exit5(t_read *args, char *str, int nb)
{
	ft_error(nb);
	write(1, "program stopped\n", 16);
	free(str);
	get_next_line(args->fd, &str, 1);
	close(args->fd);
	ft_free_split(args->split);
	ft_free_map(args, args->mapdup);
	ft_free_args(args);
	exit(1);
}
