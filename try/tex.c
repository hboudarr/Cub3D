#include "cub3d.h"

void	pixel_tex(t_tex *tex, t_read *args)
{
	args->color = tex->tex_data[tex->width * args->tex.y + args->tex.x];
}

void	pix_color(t_read *args)g
{
	if (args->perpwalldist == 0)
	{
		if (args->stepx < 0)
			pixel_tex(args->tex4, args);
		else
			pixel_tex(args->tex3, args);
	}
	else
	{
		if (args->stepy > 0)
			pixel_tex(args->tex2, args);
		else
			pixel_tex(args->tex1, args);
	}
}