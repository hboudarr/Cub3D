#include "cub3d.h"

void	pixel_tex(t_textures *tex, t_read *args)
{
	args->color = (unsigned int)tex->tex_data[tex->width * args->tex.y + args->tex.x];
	//args->color = (int)tex->tex_data;
}

void	pix_color(t_read *args)
{
	if (args->perpwalldist == 0)
	{
		if (args->stepx < 0)
			pixel_tex(args->tex1, args);
		else
			pixel_tex(args->tex1, args);
	}
	else
	{
		if (args->stepy > 0)
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