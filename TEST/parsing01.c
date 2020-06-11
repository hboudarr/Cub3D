/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:50:03 by hboudarr          #+#    #+#             */
/*   Updated: 2020/06/11 14:23:21 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int			check_tab(t_read *args)
{
	int x;
	int y;
	char **tab;

	x = args->x - 1;
	y = args->y;
	tab = args->map;

		printf("x = %d\ny = %d\n", x, y );
		printf("tab[x][y] : %s\n", args->map[x]);
	while (y >= 1)
	{
		while (x >= 1)
		{
			if (args->map[x][y] == ' ')
				if (!(tab[x][y - 1] == ' ' || tab[x][y - 1] == '1'))
					ft_err(-1); // map non valide
			x--;
		}
	y--;
	}
	printf("succes");
	return (1);
}
