#include "cub3d.h"

void	ft_check_value(char *str, t_read *args)
{
	int	R;

	R = ft_atoi(str);
	if ((R < 0 || R > 255))
		ft_exit3(args, 6);
}

void		ft_get_floor_rgb(t_read *args)
{
	args->rgb.r = args->f[0];
	args->rgb.g = args->f[1];
	args->rgb.b = args->f[2];
	args->floor = args->rgb.b + args->rgb.g * 256 + args->rgb.r * 65536;
}

int		ft_check_alphanum(char *str, char *letter)
{
	int i;
	int	j;
	int	index;

	i = 0;
	while (str[i])
	{
		j = 0;
		index = 0;
		while (letter[j])
		{
			if (str[i] == letter[j])
				index++;
			j++;
		}
		if (index == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_orient2(t_read *args, char c)
{
	if (c == 'W')
	{
		args->dirx = -1;
		args->diry = 0;
		args->planex = 0;
		args->planey = -0.66;
	}
	if (c == 'E')
	{
		args->dirx = 1;
		args->diry = 0;
		args->planex = 0;
		args->planey = 0.66;
	}
}

void		ft_orient(t_read *args, char c)
{
	if (c == 'N')
	{
		args->dirx = 0;
		args->diry = -1;
		args->planex = 0.66;
		args->planey = 0;
	}
	if (c == 'S')
	{
		args->dirx = 0;
		args->diry = 1;
		args->planex = -0.66;
		args->planey = 0;
	}
	ft_orient2(args, c);

}