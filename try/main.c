/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:07:45 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/07 17:15:35 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int		ft_key_press(int key, t_read *args)
{
	if (key == W || key == FWD)
		args->fwd = 1;
	if (key == S || key == BWD)
		args->bwd = 1;
	if (key == A)
		args->left = 1;
	if (key == D)
		args->right = 1;
	if (key == ROTLEFT)
		args->rotleft = 1;
	if (key == ROTRIGHT)
		args->rotright = 1;
	
	return (0);
}

int		ft_key_release(int key, t_read 	*args)
{
	if (key == W || key == FWD)
		args->fwd = 0;
	if (key == S || key == BWD)
		args->bwd = 0;
	if (key == A)
		args->left = 0;
	if (key == D)
		args->right = 0;
	if (key == ROTLEFT)
		args->rotleft = 0;
	if (key == ROTRIGHT)
		args->rotright = 0;
	return (0);
}

int	main (int ac, char **av)
{
	t_read      *args;
    int         fd;

    (void)ac;
	if (!(args = malloc(sizeof(t_read))))
    	ft_error(4);
  	ft_init(args);
  	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error(1);
	args->mlx_ptr = mlx_init();
//	ft_textures_data(args,args->tex1);
  	ft_read(args, fd);
  	ft_read_second_part(args, fd);
	  printf("[%d]\n", args->nbsp);
//	 	args->mlx_ptr = mlx_init();
 	args->win_ptr = mlx_new_window(args->mlx_ptr, args->resol[0], args->resol[1], "CUB3D");
 	//args->img = mlx_new_image(args->mlx_ptr, args->resol[0], args->resol[1]);
 //	args->addr = mlx_get_data_addr(args->img, &args->bits_per_pixel, &args->line_length, &args->endian);
 //	ft_raycasting(args);
 //	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, args->img, 0, 0);
  	args->img = mlx_new_image(args->mlx_ptr, args->resol[0], args->resol[1]);
  	args->addr = mlx_get_data_addr(args->img, &args->bits_per_pixel, &args->line_length, &args->endian);
	ft_textures_data(args);
	mlx_hook(args->win_ptr, 2, 1L<<0, ft_key_press, args);
	mlx_hook(args->win_ptr, 3, 1L<<1, ft_key_release, args);
	mlx_loop_hook(args->mlx_ptr, ft_raycasting, args);
//	ft_textures_data(args,args->tex1);
	//ft_raycasting(args);
 	mlx_loop(args->mlx_ptr);
}

// gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit ft_error.c get_next_line_utils.c parsing.c get_next_line.c main.c utile.c ../../Libft/ft_strdup.c ../../Libft/ft_split.c parsing1.c
