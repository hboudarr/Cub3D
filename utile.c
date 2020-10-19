/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:29:59 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/19 16:06:52 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *nptr)
{
	long int	i;
	long int	y;
	int			nb;

	nb = 0;
	i = 0;
	y = 1;
	while ((nptr[i] == ' ') || (nptr[i] == '\t') || (nptr[i] == '\v') ||
			(nptr[i] == '\n') || (nptr[i] == '\r') || (nptr[i] == '\f'))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			y = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * y);
}

int		is_whitespace(int c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int		ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

int		ft_checking(char **map, int x, int y, int max)
{
	if (y == max - 1 || y == 0 || x == 0 ||
	(size_t)x == ft_strlen(map[y]) - 1 || map[y][x - 1] == ' '
	|| map[y][x + 1] == ' ' || (size_t)x >= ft_strlen(map[y - 1]) ||
			(size_t)x >= ft_strlen(map[y + 1]) || map[y - 1][x] == ' ' ||
			map[y + 1][x] == ' ')
		return (-1);
	map[y][x] = 'V';
	return (ft_flood_fill(map, x, y, max));
}
