/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:07:45 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/15 17:33:26 by hboudarr         ###   ########.fr       */
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
	if (key == ESC)
		args->esc = 1;
	
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
	if (key == ESC)
		args->esc = 0;
	return (0);
}

void	ft_cub3d(t_read *args, int ac)
{
	if (ac == 2)
	{
		mlx_hook(args->win_ptr, 2, 1L<<0, ft_key_press, args);
		mlx_hook(args->win_ptr, 3, 1L<<1, ft_key_release, args);
		mlx_loop_hook(args->mlx_ptr, ft_raycasting, args);
 		mlx_loop(args->mlx_ptr);
	}
	else
	{
		ft_raycasting(args);
		ft_create_img(args);
	}
}

int		ft_check_filename(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	if (ft_strlen(str) >= 4 && str[i - 1] == 'b' && str[i - 2] == 'u'
	&& str[i - 3] == 'c' && str[i - 4] == '.')
		return (1);
	return (0);
}

int		ft_check_arg(char *str)
{
	char	cmp[7];
	int		i;

	cmp[0] = '-';
	cmp[1] = '-';
	cmp[2] = 's';
	cmp[3] = 'a';
	cmp[4] = 'v';
	cmp[5] = 'e';
	cmp[6] = '\0';
	i = 0;
	if (ft_strlen(str) != 6)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != cmp[i])
			return (0);
		i++;
	}
	return (1);
}

int	main (int ac, char **av)
{
	t_read      *args;
    int         fd;

	if ((ac == 2 && ft_check_filename(av[1]) == 1) || (ac == 3 &&
	ft_check_arg(av[2]) == 1 && ft_check_filename(av[1]) == 1))
	{
		if (!(args = malloc(sizeof(t_read))))
    		ft_error(4);
  		ft_init(args);
  		if ((fd = open(av[1], O_RDONLY)) < 0)
			ft_error(1);
		if (!(args->mlx_ptr = mlx_init()))
			ft_error(1);
  		ft_read(args, fd);
  		ft_read_second_part(args, fd);
		if (!(args->zbuffer = malloc(sizeof(double) * args->resol[0])))
			ft_error(4);
		if (!(args->img = mlx_new_image(args->mlx_ptr, args->resol[0], args->resol[1])))
	  		ft_error(1);
		args->addr = mlx_get_data_addr(args->img, &args->bits_per_pixel, &args->line_length, &args->endian);
		if (!(args->win_ptr = mlx_new_window(args->mlx_ptr, args->resol[0], args->resol[1], "CUB3D")))
			ft_error(1);
		ft_textures_data(args);
		ft_cub3d(args, ac);
	}
	else
		ft_error(1);
}

// Makefile
// Norminette
// FREE MES MALLOCS
// ft_error + exit - touche echap (quitter le programme proprement)
// recheck le parsing map.
