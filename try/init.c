# include "cub3d.h"

void    ft_init(t_read *args)
{
    ft_bzero(args, sizeof(*args));
    args->tex1 = malloc(sizeof(t_textures));
    ft_bzero(args->tex1, sizeof(t_textures));
    args->tex2 = malloc(sizeof(t_textures));
    ft_bzero(args->tex2, sizeof(t_textures));
    args->tex3 = malloc(sizeof(t_textures));
    ft_bzero(args->tex3, sizeof(t_textures));
    args->tex4 = malloc(sizeof(t_textures));
    ft_bzero(args->tex4, sizeof(t_textures));
    args->f[0] = -1;
    args->f[1] = -1;
    args->f[2] = -1;
    args->c[0] = -1;
    args->c[1] = -1;
    args->c[2] = -1;
    args->rgb.r = 0;
    args->rgb.g = 0;
    args->rgb.b = 0;
}
