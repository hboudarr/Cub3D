#include "cub3d.h"
/*
int ft_hook(t_read  *args)
{

   // args->img = mlx_new_image(args->mlx_ptr, args->resol[0], args->resol[1]);
    // args->addr = mlx_get_data_addr(args->img, &args->bits_per_pixel, &args->line_length, &args->endian);
   //move forward if no wall in front of you
    if (args->up == 1)
    {
      if((int)((args->posy + args->diry * MOVESPEED)) != 0 && (int)((args->posy + args->diry) * MOVESPEED) != args->resol[1] - 1
      && (int)((args->posx + args->dirx) * MOVESPEED) != 0 && (int)((args->posx + args->dirx) * MOVESPEED) != args->resol[0])
        args->posx += args->dirx * MOVESPEED;
     // (args->map[(int)(args->posx + args->dirx * MOVESPEED)][(int)(args->posy)] != 0) 
     //   args->posx += args->dirx * MOVESPEED;
      if(args->map[(int)(args->posx)][(int)((args->posy + args->diry) * MOVESPEED)] != 0) 
        args->posy += args->diry * MOVESPEED; */
  //  }
   /move backwards if no wall behind you
    if (args->down == 1)
    {
      if(args->map[(int)(args->posx - args->dirx * MOVESPEED)][(int)(args->posy)] != 0) 
        args->posx -= args->dirx * MOVESPEED;
      if(args->map[(int)(args->posx)][(int)(args->posy - args->diry * MOVESPEED)] != 0) 
        args->posy -= args->diry * MOVESPEED;
    }
    //rotate to the right
    if (args->right == 1)
    {
      //both camera direction angd camera plane must be rotated
      args->olddirx = args->dirx;
      args->dirx = args->dirx * cos(-ROTSPEED) - args->diry * sin(-ROTSPEED);
      args->diry = args->olddirx * sin(-ROTSPEED) + args->diry * cos(-ROTSPEED);
      args->oldplanex = args->planex;
      args->planex =  args->planex * cos(-ROTSPEED) - args->planey * sin(-ROTSPEED);
      args->planey = args->oldplanex * sin(-ROTSPEED) + args->planey * cos(-ROTSPEED);
    } 
    //rotate to the left
    if (args->left == 1)
    {
      //both camera direction and camera plane must be rotated
      args->olddirx = args->dirx;
      args->dirx = args->dirx * cos(ROTSPEED) - args->diry * sin(ROTSPEED);
      args->diry = args->olddirx * sin(ROTSPEED) + args->diry * cos(ROTSPEED);
      args->oldplanex = args->planex;
      args->planex = args->planex * cos(ROTSPEED) - args->planey * sin(ROTSPEED);
      args->planey = args->oldplanex * sin(ROTSPEED) + args->planey * cos(ROTSPEED);
    }

    //ft_raycasting(args);
    // mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, args->img, 0, 0);
    return (1);
}


void  ft_move_fwd(t_read *args)
{
  int 	tmp_x;
	int		tmp_y;

	tmp_x = floor(args->posx + args->dirx * MOVESPEED);
	tmp_y = floor(args->posy + args->diry * MOVESPEED);
  if (args->up)
  {
    if (args->map[(int)(args->posy)][tmp_x] == '0')
	    args->posx += args->dirx * MOVESPEED;
  }
    

	if (args->up == 1)
	{
		if (args->map[(int)(args->posy)][(int)(args->posx + args->dirx
			* 0.15)] == '0')
			args->posx += args->dirx * 0.15;
		if (args->map[(int)(args->posy + args->diry * 0.15)][(int)(args->posx)] == '0')
			args->posy += args->diry * 0.15;
	}
	if (args->down == 1)
	{
		if (arg->map.tab_map[(int)(env->pos.y)][(int)(env->pos.x - env->rc.dir.x
			* env->rc.speed)] == '0')
			env->pos.x -= env->rc.dir.x * env->rc.speed;
		if (env->map.tab_map[(int)(env->pos.y - env->rc.dir.y *
			env->rc.speed)][(int)(env->pos.x)] == '0')
			env->pos.y -= env->rc.dir.y * env->rc.speed;
	}
//}
 // else if (tmp_x > 0 && tmp_x < args->y - 1)
  	//args->posy += args->diry * MOVESPEED;
	//else if (tmp_y > 0 && tmp_y < args->y - 1)
	//	args->posy += args->diry * MOVESPEED;

int ft_hook(t_read  *args)
{
  ft_move_fwd(args);
  return (1);
}*/