#include "cub3d.h"

void	pixel_tex(t_textures *tex, t_read *args)
{
	 args->color = (unsigned int)tex->tex_data[(tex->height * args->tex.y + args->tex.x)];
	//args->color = (unsigned int)tex->tex_data[args->tex.y * tex->size_line + args->tex.x * tex->bpp] * 8;
	//args->color = (int)tex->tex_data;

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

void	pix_color(t_read *args)
{
	if (args->perpwalldist == 0)
	{
		if (args->tex.y < 0)
			pixel_tex(args->tex1, args);
		else
			pixel_tex(args->tex1, args);
	}
	else
	{
		if (args->tex.x > 0)
			pixel_tex(args->tex1, args);
		else
			pixel_tex(args->tex1, args);
	}
}

void	ft_textures_data(t_read *args, t_textures *textures)
{
	textures->tex_ptr = mlx_xpm_file_to_image(args->mlx_ptr, args->no, &textures->width, &textures->height);
	textures->tex_data = (int *)mlx_get_data_addr(textures->tex_ptr, &textures->bpp, &textures->size_line, &textures->endian);
}