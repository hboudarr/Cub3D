#include "cub3d.h"

void	ft_draw_to_image(t_read *data, int x, int y, int color)
{
	// *((int *)data->addr + y * data->line_length + x) = color;
   	*(unsigned int *)(data->addr + y * data->line_length + x * data->bits_per_pixel / 8) = color;
   //  data->addr[(y * data->resol[0] + x)] = color;

     //img->img_data[p_y * img->width + p_x] = color;
}

 /* while (args->ycoor < args->drawend)
    {
      draw_to_image(args, x, args->ycoor, args->color);
      args->ycoor++;
    }*/
/*
int   ft_display_color(t_read *args, int x)
{
    int y;

    y = 0;
    while (y < args->drawstart)
    {
      draw_to_image(args->img, x, y, args->ceiling);
      y++;
    }
    while (args->ycoor < args->drawend)
    {
      // env->rc.tex.y = (int)env->rc.tex_pos & (64 - 1);
      draw_to_image(args->img, x, y, args->color);
      y++;
    }
    while (y < args->resol[1])
    {
      draw_to_image(args->img, x, y, args->floor);
      y++;
    }
    return (1);
}*/

void    ft_wall_tex(t_read *args)
{
	double wallx;

	if (args->side == 0)
		wallx = args->posy + args->perpwalldist * args->diry;
	else
		wallx = args->posx + args->perpwalldist * args->dirx;
	wallx -= (int)wallx;
	args->tex.x = (int)(wallx * args->tex1->width);
	if (args->perpwalldist == 0 && args->dirx > 0)
		args->tex.x = args->tex1->width - args->tex.x;
	else if (args->perpwalldist == 1 && args->dirx < 0)
		args->tex.x = args->tex1->width - args->tex.x;
  if (args->side == 0 && args->raydirx > 0)
    args->tex.x = args->tex1->width - args->tex.x - 1;
  if (args->side == 1 && args->raydiry < 0)
    args->tex.x = args->tex1->width - args->tex.x - 1;
	args->tex.step_tex = 1.0 * args->tex1->width / args->tex.rh;
	args->tex.tex_pos = (args->drawstart - args->resol[1] / 2 + args->tex.rh / 2) * args->tex.step_tex;
}

int ft_raycasting(t_read *args)
{
  int x;
 //  args->img = mlx_new_image(args->mlx_ptr, args->resol[0], args->resol[1]);
   // args->addr = mlx_get_data_addr(args->img, &args->bits_per_pixel, &args->line_length, &args->endian);

  x = 0;
  while ( x < args->resol[0])
  {
    args->camerax = 2 * x / (double)args->resol[0] - 1;
  	args->raydirx = args->dirx + args->planex * args->camerax;
    args->raydiry = args->diry + args->planey * args->camerax;

    args->mapx = (int)args->posx;
    args->mapy = (int)args->posy;

    args->hit = 0; 
    //args->deltadistx = fabs(1 / args->raydirx);
    args->deltadistx = sqrt(1 + (args->raydiry * args->raydiry) / 
      (args->raydirx * args->raydirx));
    //args->deltadisty = fabs(1 / args->raydiry);
    args->deltadisty = sqrt(1 + (args->raydirx * args->raydirx) / 
      (args->raydiry * args->raydiry));

 
    if (args->raydirx < 0)
    {
      args->stepx = -1;
      args->sidedistx = (args->posx - args->mapx) * args->deltadistx;
    }
    else
    {
      args->stepx = 1;
      args->sidedistx = (args->mapx + 1.0 - args->posx) * args->deltadistx;
    }
    if (args->raydiry < 0)
    {
      args->stepy = -1;
      args->sidedisty = (args->posy - args->mapy) * args->deltadisty;
    }
    else
    {
      args->stepy = 1;
      args->sidedisty = (args->mapy + 1.0 - args->posy) * args->deltadisty;
    }
    while (args->hit == 0)
    {
      if (args->sidedistx < args->sidedisty)
      {
        args->sidedistx += args->deltadistx;
        args->mapx += args->stepx;
        args->side = 0;
      }
      else
      {
        args->sidedisty += args->deltadisty;
        args->mapy += args->stepy;
        args->side = 1;
      }
      if (args->map[args->mapy][args->mapx] != '0'&& 
      args->map[args->mapy][args->mapx] != '2'&& 
      args->map[args->mapy][args->mapx] != 'E'&& 
      args->map[args->mapy][args->mapx] != 'N'&&
      args->map[args->mapy][args->mapx] != 'S'&&
      args->map[args->mapy][args->mapx] != 'W')
        args->hit = 1;     
    }
    if (args->side == 0) 
      args->perpwalldist = fabs((args->mapx - args->posx + (1 - args->stepx) / 2) / args->raydirx);
   //  args->perpwalldist = fabs((args->mapx - args->posx + (( 1 - args->stepx) / 2)) / args->dirx);
    else 
      args->perpwalldist = fabs((args->mapy - args->posy + (1 - args->stepy) / 2) / args->raydiry);         
     // args->perpwalldist = fabs((args->mapy - args->posy + ((1 - args->stepy) / 2)) / args->raydiry);
   //  env->rc.dist = fabs((env->rc.rmap.x - env->rc.rpos.x + (1 - env->rc.step.x) / 2) / env->rc.rdir.x);
    args->linehth = (int)(args->resol[1] / args->perpwalldist);
   //  args->linehth = fabs(args->resol[1] / args->perpwalldist);
    args->linehth = (args->linehth < 0) ? INT_MAX : args->linehth;
 
   //  args->drawstart = (-args->linehth / 2) + (args->resol[1] / 2);
   args->drawstart = (-1 * (args->linehth)) / 2 + (args->resol[1] / 2);
    if(args->drawstart < 0)
      args->drawstart = 0; 

    args->drawend = args->linehth / 2 + args->resol[1] / 2;
    if(args->drawend >= args->resol[1])
      args->drawend = args->resol[1] - 1;
  
   ft_wall_tex(args);
   // args->color = 0x00FF0000;
   // if (args->side == 1) 
    //  args->color = args->color / 2;
    // args->ycoor = args->drawstart;

  
    args->ycoor = 0;
    while (args->ycoor < args->drawstart)
    {
      ft_draw_to_image(args, x, args->ycoor, args->ceiling);
      args->ycoor++;
    }
    while (args->ycoor < args->drawend)
    {
      args->tex.y = (int)args->tex.tex_pos & args->tex1->height - 1;;
      args->tex.tex_pos += args->tex.step_tex;
     if (args->tex.y < 0 || args->tex.y >= args->tex1->height)
        args->tex.y = (args->tex.y < 0) ? 0 : args->tex1->height - 1;
      pix_color(args);
      ft_draw_to_image(args, x, args->ycoor, args->color);
      args->ycoor++;
    }
    
    while (args->ycoor < args->resol[1])
    {
      ft_draw_to_image(args, x, args->ycoor, args->floor);
      args->ycoor++;
    }
    /*
    int i, j;

    i = -1;
    while (++i < args->tex1->width)
    {
      j = -1;
      while (++j < args->tex1->height)
      ft_draw_to_image(args, i, j, *((int *)args->tex1->tex_data + i * args->tex1->width + j));
    }*/
   /*  while (args->ycoor < args->drawend)
    {
      draw_to_image(args, x, args->ycoor, args->color);
      args->ycoor++;
    }*/
    x++;
  }

  //mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, args->img, 0, 0);
      
  /*
  args->olddirx = args->dirx;
  args->dirx = args->dirx * cos(-0.0001) - args->diry * sin(-0.0001);
  args->diry = args->olddirx * sin(-0.0001) + args->diry * cos(-0.0001);
  args->oldplanex = args->planex;
  args->planex = args->planex * cos(-0.0001) g- args->planey * sin(-0.0001);
  args->planey = args->oldplanex * sin(-0.0001) + args->planey * cos(-0.0001);
  */
  //ßmlx_loop(args->mlx_ptr);
  mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, args->img, 0, 0);
  ft_hook(args);
/*
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
		if (args->map[(int)(args->posy)][(int)(args->posx - args->dirx * MOVESPEED)] == '0')
			args->posx -= args->dirx * MOVESPEED;
		if (args->map[(int)(args->posy - args->diry * MOVESPEED)][(int)(args->posx)] == '0')
			args->posy -= args->diry * MOVESPEED;
  }

  if (args->left == 1)
	{
		if (args->map[(int)(args->posy - args->dirx * MOVESPEED)][(int)(args->posx)] == '0')
			args->posy += -args->dirx * MOVESPEED;
		if (args->map[(int)(args->posy)][(int)(args->posx + args->diry * MOVESPEED)] == '0')
			args->posx += args->diry * MOVESPEED;
	}
	if (args->right == 1)
	{
		if (args->map[(int)(args->posy + args->dirx * MOVESPEED)][(int)(args->posx)] == '0')
			args->posy -= -args->dirx * MOVESPEED;
		if (args->map[(int)(args->posy)][(int)(args->posx - args->diry * MOVESPEED)] == '0')
			args->posx -= args->diry * MOVESPEED;
	} */
  return(1);
}
