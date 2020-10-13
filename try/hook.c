#include "cub3d.h"

void  ft_move_bwd(t_read *args)
{
  if (args->bwd == 1)
	{
		if (args->map[(int)(args->posy)][(int)(args->posx - args->dirx * MOVESPEED)] == '0')
			args->posx -= args->dirx * MOVESPEED;
		if (args->map[(int)(args->posy - args->diry * MOVESPEED)][(int)(args->posx)] == '0')
			args->posy -= args->diry * MOVESPEED;
  }
}

void  ft_move_left(t_read *args)
{
  if (args->left == 1)
	{
		if (args->map[(int)(args->posy - args->dirx * MOVESPEED)][(int)(args->posx)] == '0')
			args->posy += -args->dirx * MOVESPEED;
		if (args->map[(int)(args->posy)][(int)(args->posx + args->diry * MOVESPEED)] == '0')
			args->posx += args->diry * MOVESPEED;
	}
}

void  ft_move_right(t_read *args)
{
  if (args->right == 1)
	{
		if (args->map[(int)(args->posy + args->dirx * MOVESPEED)][(int)(args->posx)] == '0')
			args->posy -= -args->dirx * MOVESPEED;
		if (args->map[(int)(args->posy)][(int)(args->posx - args->diry * MOVESPEED)] == '0')
			args->posx -= args->diry * MOVESPEED;
	}
}

void	ft_rotate(t_read *args, int advance)
{
	double	dir;
	double	plane;

	dir = args->dirx;
	plane = args->planex;
	args->dirx = args->dirx * cos(advance * 0.1) - args->diry * sin(advance * 0.1);
	args->diry = dir * sin(advance * 0.1) + args->diry * cos(advance * 0.1);
	args->planex = args->planex * cos(advance * 0.1) - args->planey * sin(advance * 0.1);
	args->planey = plane * sin(advance * 0.1) + args->planey * cos(advance * 0.1);
}

int ft_hook(t_read  *args)
{
  ft_move_fwd(args);
  ft_move_bwd(args);
	ft_move_left(args);
  ft_move_right(args);
  if (args->rotleft == 1)
    ft_rotate(args, 1);
  if (args->rotright == 1)
    ft_rotate(args, -1);
  return (1);
}