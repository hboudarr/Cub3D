/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:36:07 by hboudarr          #+#    #+#             */
/*   Updated: 2020/09/23 10:52:00 by hboudarr         ###   ########.fr       */
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
	int			a;
	int			b;
	int			c;
	int			d;
	int			e;
	int			f;
	int			g;
	int			h;
	int			i;
	int			j;
	int			flag;
	int			flag1;
	int			flag2;
	int			car;
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
		/*	if (param->x >= 250 && param->y == 250)
			{
				draw_to_image(param, param->x, param->y, 0x00FF0000);
				param->x++;
				param->y++;
			}*/
	}
	if (param->flag1 == 1)
	{
		write(1, "TA GUEULE", 9);
		draw_to_image(param, param->x, param->y, 0x00FF0000);
			param->x--;
			param->y--;
	}
	if (param->flag2 == 1)
	{
		write(1, "coucou", 6);
		draw_to_image(param, param->a, param->b, 0x00FF0000);
		param->a++;
		draw_to_image(param, param->c, param->d, 0x00FF0000);
		param->d++;
		draw_to_image(param, param->e, param->f, 0x00FF0000);
		param->f++;
		draw_to_image(param, param->g, param->h, 0x00FF0000);
		param->g++;
	}
	if (param->car == 1)
	{	
		while (param->i != 200)
		{
			param->j = 250;
			while (param->j != 450)
			{
				draw_to_image(param, param->i, param->j, 0x00FF0000);
				param->j++;
			}
			param->i++;
		}
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img, 0, 0);
	return (0);
}

int		ft_key_press(int key, t_data *param)
{
	printf("%d\n", key);
	if (key == 9)
		param->car = 1;
	if (key == 13)
		param->flag = 1;
	if (key == 35)
		param->flag1 = 1;
	if (key == 17)
		param->flag2 = 1;
	return (0);

}

int		ft_key_release(int key, t_data *param)
{
	if (key == 13)
		param->flag = 0;
	if (key == 35)
		param->flag1 = 0;
	if (key == 17)
		param->flag2 = 0;

	return (0);
}

int	main()
{
	t_data	img;

	img.x = 0;
	img.y = 0;
	img.a = 100;
	img.b = 250;
	img.c = 300;
	img.d = 250;
	img.e = 100;
	img.f = 250;
	img.g = 100;
	img.h = 350;
	img.i = 100;
	img.j = 250;
	img.flag = 0;
	img.flag1 = 0;
	img.flag2 = 0;
	img.car = 0;
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, 500, 500, "CUB3D");
	img.img = mlx_new_image(img.mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_hook(img.win_ptr, 2, 1L<<0, ft_key_press, &img);
	mlx_hook(img.win_ptr, 3, 1L<<1, ft_key_release, &img);
	mlx_loop_hook(img.mlx_ptr, ft_go, &img);
	mlx_loop(img.mlx_ptr);
}
