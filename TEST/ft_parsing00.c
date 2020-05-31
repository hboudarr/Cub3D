/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:49:01 by hboudarr          #+#    #+#             */
/*   Updated: 2020/05/28 16:54:39 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				is_whitespace(int c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int		ft_parse_resolution(char *str, int fd, t_read args)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'R')
			return(1);;
		i++;
	}
}

int		ft_parse_resol(char *str, int fd, t_read args)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'S')
			return(2);;
		i++;
	}
}


void		ft_parse_map(int fd, char *str)
{
	t_read	args;

	args.count = ft_parse_resolution(str, fd, args);
	args.recount = ft_parse_resol(str, fd, args);
		printf("count : %d\n", args.count);
		printf("recount : %d\n", args.recount);
}
