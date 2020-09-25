# include "cub3d.h"

void    ft_init(t_read *args)
{
    ft_bzero(args, sizeof(*args));
    args->f[0] = -1;
    args->f[1] = -1;
    args->f[2] = -1;
    args->c[0] = -1;
    args->c[1] = -1;
    args->c[2] = -1;
}
