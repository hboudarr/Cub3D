/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:36:07 by hboudarr          #+#    #+#             */
/*   Updated: 2020/09/10 17:07:38 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>

typedef struct  s_data {
    void        *img;
	void 		*win_ptr;
	void 		*mlx_ptr;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int			x;
	int			y;
	int			flag;
	int			flag1;
}						t_data;

void	draw_to_image(t_data *data, int x, int y, int color)
{
	*(unsigned int *)(data->addr + y * data->line_length + x * data->bits_per_pixel / 8) = color;
}

int	ft_go(t_data *param)
{
	if (param->flag == 1)
	{
		write(1,"SALUT CA VA", 11);
			draw_to_image(param, param->x, param->y, 0x00ADFF2F);
			param->x++;
			param->y++;
			if (param->x >= 250 && param->y == 250)
			{
				draw_to_image(param, param->x, param->y, 0x00FF0000);
				param->x++;
				param->y++;
			}
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
	return (0);
}

int		ft_key_press(int key, t_data *param)
{
	printf("%d\n", key);
	if (key == 13)
		param->flag = 1;
	return (0);

}

int		ft_key_release(int key, t_data *param)
{
	if (key == 13)
		param->flag = 0;
	return (0);
}

int	main()
{
	t_data	img;

	img.x = 0;
	img.y = 0;
	img.flag = 0;
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, 500, 500, "CUB3D");
	img.img = mlx_new_image(img.mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_hook(img.win_ptr, 2, 1L<<0, ft_key_press, &img);
	mlx_hook(img.win_ptr, 3, 1L<<1, ft_key_release, &img);
	mlx_loop_hook(img.mlx_ptr, ft_go, &img);
	mlx_loop(img.mlx_ptr);
}
