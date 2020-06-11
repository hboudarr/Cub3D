/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:07:45 by hboudarr          #+#    #+#             */
/*   Updated: 2020/06/11 19:52:16 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	main (int ac, char **av)
{
	int 	fd;
	t_read	args;
	
	(void)ac;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error(1);
	args.mlx_ptr = mlx_init();
	ft_read(&args, fd);
	return (0);
}
