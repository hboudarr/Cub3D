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
	args->sprite = malloc(sizeof(t_textures));
    ft_bzero(args->sprite, sizeof(t_textures));
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

void	ft_bzero(void *s, int n)
{
	unsigned char	*dest;

	dest = s;
	while (n)
	{
		*dest = 0;
		n--;
		dest++;
	}
}

void  ft_move_fwd(t_read *args)
{
   if (args->fwd == 1)
	{
		if (args->map[(int)(args->posy)][(int)(args->posx + args->dirx
			* 0.15)] == '0')
			args->posx += args->dirx * 0.15;
		if (args->map[(int)(args->posy + args->diry * 0.15)][(int)(args->posx)] == '0')
		  args->posy += args->diry * 0.15;
	}
}

void	ft_analyse_str(t_read *args)
{
	int i;

	i = 0;
	if (ft_check_alphanum(args->s, "NSEW102 ") == 0)
			ft_error(12);
	while (args->s[i])
	{
		if (args->s[i] == 'N' || args->s[i] == 'S' || args->s[i] == 'E' || args->s[i] == 'W')
		{
			args->posy = (args->y - 1) + 0.5;
			args->posx = i + 0.5;
			args->count += 1;
			ft_orient(args, args->s[i]);
			args->s[i] = '0';
		}
		if (args->s[i] == '2')
			args->nbsp += 1;
		i++;
	}
	if (args->count > 1)
		ft_error(12);
}