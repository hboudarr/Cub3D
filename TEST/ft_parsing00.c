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

void		ft_parse_map(int fd, t_read *args)
{
	char *str;
	int		i;

	str = args->get_line;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'R')
			args->count = 1;
		if (str[i] != 'R')
			args->count = 2;
		i++;
	}
}
