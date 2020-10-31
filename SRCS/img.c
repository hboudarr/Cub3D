/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halimbdr <halimbdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:09:16 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/31 10:39:32 by halimbdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_define_ptr(t_read *args, t_img *ptr)
{
	ptr->file_size = args->resol[0] * args->resol[1] * 4 + 54;
	ptr->reserved1 = 0;
	ptr->reserved2 = 0;
	ptr->offset_bits = 54;
	ptr->size_header = 40;
	ptr->width = args->resol[0];
	ptr->height = args->resol[1];
	ptr->planes = 1;
	ptr->bbp = 32;
	ptr->compression = 0;
	ptr->image_size = 0;
	ptr->ppm_x = 0;
	ptr->ppm_y = 0;
	ptr->clr_total = 0;
	ptr->clr_important = 0;
}

void	ft_tab_in_img(t_read *args, int fd)
{
	int				i;
	int				x;
	int				y;
	unsigned int	*tab;

	tab = malloc(sizeof(int) * (args->resol[1] * args->resol[0]));
	if (tab == NULL)
		ft_exit1(args);
	y = args->resol[1] - 1;
	i = 0;
	while (i < (args->resol[0] * args->resol[1]))
	{
		x = -1;
		while (++x < args->resol[0])
			tab[i++] = *(unsigned int *)(args->addr + y * args->line_length +
			x * args->bits_per_pixel / 8);
		y--;
	}
	if (!(write(fd, tab, args->resol[0] * args->resol[1] * 4)))
	{
		free(tab);
		ft_exit1(args);
	}
	free(tab);
}

void	ft_create_img(t_read *args)
{
	int		fd;
	t_img	ptr;

	ft_define_ptr(args, &ptr);
	fd = open("cub3d_img.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (fd == -1)
		ft_exit1(args);
	if (write(fd, "BM", 2) == -1 || write(fd, &ptr, 52) == -1)
		ft_exit1(args);
	ft_tab_in_img(args, fd);
	close(fd);
	ft_deal_exit(args);
}

int		ft_loop(t_read *args)
{
	ft_hook(args);
	ft_raycasting(args);
	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, args->img, 0, 0);
	return (1);
}

void	ft_exit6(t_read *args, char *str, int nb)
{
	args->y = args->y - 1;
	ft_error(nb);
	write(1, "program stopped\n", 16);
	free(str);
	get_next_line(args->fd, &str, 1);
	close(args->fd);
	ft_free_map(args, args->mapdup);
	ft_free_args(args);
	exit(1);
}
