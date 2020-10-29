/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halimbdr <halimbdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:07:45 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/29 14:17:38 by halimbdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cub3d(t_read *args, int ac)
{
	if (ac == 2)
	{
		if (!(args->win_ptr = mlx_new_window(args->mlx_ptr, args->resol[0],
		args->resol[1], "CUB3D")))
			ft_exit1(args);
		mlx_hook(args->win_ptr, 2, 1L << 0, ft_key_press, args);
		mlx_hook(args->win_ptr, 3, 1L << 1, ft_key_release, args);
		mlx_hook(args->win_ptr, 17, 1L << 17, ft_deal_exit, args);
		mlx_loop_hook(args->mlx_ptr, ft_loop, args);
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

void	ft_main2(t_read *args)
{
	if (!(args->zbuffer = malloc(sizeof(double) * args->resol[0])))
		ft_exit1(args);
	if (!(args->img = mlx_new_image(args->mlx_ptr,
	args->resol[0], args->resol[1])))
		ft_exit1(args);
	if (!(args->addr = mlx_get_data_addr(args->img, &args->bits_per_pixel,
	&args->line_length, &args->endian)))
		ft_exit1(args);
	ft_textures_data(args);
}

void	ft_parse_empty_line(t_read *args)
{
	int		ret;

	ret = get_next_line(args->fd, &args->s, 0);
	while (ret == 1 && args->s[0] == '\0')
	{
		free(args->s);
		ret = get_next_line(args->fd, &args->s, 0);
	}
	if (ret == -1 || ret == 0)
		ft_exit3(args, args->s, 8);
	args->count = 0;
	ft_analyse_str(args);
	args->y = 1;
	ft_make_range(args);
	ft_make_map(args);
}

int		main(int ac, char **av)
{
	t_read		*args;
	int			i;

	i = 0;
	if ((ac == 2 && ft_check_filename(av[1]) == 1) || (ac == 3 &&
	ft_check_arg(av[2]) == 1 && ft_check_filename(av[1]) == 1))
	{
		if (!(args = malloc(sizeof(t_read))))
			ft_exit1(args);
		ft_init(args);
		if ((args->fd = open(av[1], O_RDONLY)) < 0)
			ft_exit1(args);
		if (!(args->mlx_ptr = mlx_init()))
			ft_exit1(args);
		ft_read(args);
		ft_compare(args);
		ft_parse_empty_line(args);
		ft_read_second_part(args);
		ft_main2(args);
		ft_cub3d(args, ac);
	}
	else
		ft_exit2();
}
