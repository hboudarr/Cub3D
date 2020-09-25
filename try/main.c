/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:07:45 by hboudarr          #+#    #+#             */
/*   Updated: 2020/09/08 11:35:16 by hboudarr         ###   ########.fr       */
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
//	args.mlx_ptr = mlx_init();
	ft_read(&args, fd);
	ft_read_second_part(&args, fd);
	return (0);
}
/*
void	ft_get_celling(t_read *args, char *str, int i)
{
	i++;
	args->split = ft_split(str + i, ',');
	if ((!(args->split[2])) || args->split[3])
		ft_error(11);
	args->c[0] = ft_atoi(args->split[0]);
	args->c[1] = ft_atoi(args->split[1]);
	args->c[2] = ft_atoi(args->split[2]);
	args->tab[7] = 1;
	printf("Celling 1 : %d\n", args->c[0]);
	printf("Celling 2 : %d\n", args->c[1]);g
	printf("Celling 3 : %d\n", args->c[2]);
	ft_free_split(args->split);
}*/


// gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit ft_error.c get_next_line_utils.c parsing.c get_next_line.c main.c utile.c ../../Libft/ft_strdup.c ../../Libft/ft_split.c parsing1.c
