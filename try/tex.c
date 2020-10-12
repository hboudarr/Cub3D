#include "cub3d.h"

void	pixel_tex(t_textures *tex, t_read *args)
{
	 args->color = (unsigned int)tex->tex_data[(args->wthtext * args->tex.y + args->tex.x)];
	//args->color = (unsigned int)tex->tex_data[args->tex.y * tex->size_line + args->tex.x * tex->bpp] * 8;
	//args->color = (int)tex->tex_data;g

//	env->ray.color = 0;
//	if (env->t_map.map[(int)env->ray.map.y][(int)env->ray.map.x]
//		&& env->t_map.map[(int)env->ray.map.y][(int)env->ray.map.x] == '1')
/*		args->color = 0;
		if (args->side == 0)
		{
			if (args->tex.x < 0)
				args->color = tex->tex_data[(tex->height * args->tex.y + args->tex.x)];
			else
				args->color = tex->tex_data[(tex->height * args->tex.y + args->tex.x)];
		}
		else
		{
			if (args->tex.y > 0)
				args->color = tex->tex_data[(tex->height * args->tex.y + args->tex.x)];
			else
				args->color = tex->tex_data[(tex->height * args->tex.y + args->tex.x)];
			args->color = (args->color >> 1) & 8355711;
		} */
}

void	ft_size_text(t_read *args)
{
		if (args->side == 0 && args->raydirx < 0)
		{
			args->hthtext = args->tex4->height;
			args->wthtext = args->tex4->width;
		}
		else if (args->side == 0 && args->raydirx > 0)
		{
			args->hthtext = args->tex3->height;
			args->wthtext = args->tex3->width;
		}
		else if (args->side == 1 && args->raydiry < 0)
		{
			args->hthtext = args->tex1->height;
			args->wthtext = args->tex1->width;
		}
		else
		{
			args->hthtext = args->tex2->height;
			args->wthtext = args->tex2->width;
		}	
}

void	pix_color(t_read *args)
{

	
		if (args->side == 0 && args->raydirx < 0)
			pixel_tex(args->tex4, args);
		else if (args->side == 0 && args->raydirx > 0)
			pixel_tex(args->tex3, args);
		else if (args->side == 1 && args->raydiry < 0)
			pixel_tex(args->tex1, args);
		else
			pixel_tex(args->tex2, args);
}

void	ft_textures_data(t_read *args)
{
	if (args->tab[1] == 1)
	{
		args->tex1->tex_ptr = mlx_xpm_file_to_image(args->mlx_ptr, args->no, &args->tex1->width, &args->tex1->height);
		args->tex1->tex_data = (int *)mlx_get_data_addr(args->tex1->tex_ptr, &args->tex1->bpp, &args->tex1->size_line, &args->tex1->endian);
	}
	if (args->tab[2] == 1)
	{
		args->tex2->tex_ptr = mlx_xpm_file_to_image(args->mlx_ptr, args->so, &args->tex2->width, &args->tex2->height);
		args->tex2->tex_data = (int *)mlx_get_data_addr(args->tex2->tex_ptr, &args->tex2->bpp, &args->tex2->size_line, &args->tex2->endian);
	}
	if (args->tab[3] == 1)
	{
		args->tex3->tex_ptr = mlx_xpm_file_to_image(args->mlx_ptr, args->we, &args->tex3->width, &args->tex3->height);
		args->tex3->tex_data = (int *)mlx_get_data_addr(args->tex3->tex_ptr, &args->tex3->bpp, &args->tex3->size_line, &args->tex3->endian);
	}
	if (args->tab[4] == 1)
	{
		args->tex4->tex_ptr = mlx_xpm_file_to_image(args->mlx_ptr, args->ea, &args->tex4->width, &args->tex4->height);
		args->tex4->tex_data = (int *)mlx_get_data_addr(args->tex4->tex_ptr, &args->tex4->bpp, &args->tex4->size_line, &args->tex4->endian);
	}
}

// compter le nombre de sprites dans mon parsing
// les referencer dans un tableau d'init initiallement malloc
// calculer la distance entre chaque 
// gcc -Wall -Wextra -Werror  -g3 minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit ft_error.c get_next_line_utils.c parsing.c get_next_line.c utile.c ../../Libft/ft_strdup.c ../../Libft/ft_split.c parsing1.c myray.c init.c ../Libft/ft_bzero.c main.c hook.c tex.c