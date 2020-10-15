#include "cub3d.h"

void	ft_draw_to_image(t_read *data, int x, int y, int color)
{
  *(unsigned int *)(data->addr + y * data->line_length + x * data->bits_per_pixel / 8) = color;
}

void    ft_wall_tex(t_read *args)
{
	double wallx;

	if (args->side == 0)
		wallx = args->posy + args->perpwalldist * args->raydiry;
	else
		wallx = args->posx + args->perpwalldist * args->raydirx;
	wallx -= (int)wallx;
	args->tex.x = (int)(wallx * args->wthtext);
	if (args->perpwalldist == 0 && args->dirx > 0)
		args->tex.x = args->wthtext - args->tex.x - 1;
	else if (args->perpwalldist == 1 && args->dirx < 0)
		args->tex.x = args->wthtext - args->tex.x - 1;
  if (args->side == 0 && args->raydirx > 0)
    args->tex.x = args->wthtext - args->tex.x - 1;
  if (args->side == 1 && args->raydiry < 0)
    args->tex.x = args->wthtext - args->tex.x - 1;
	args->tex.step_tex = 1.0 * args->hthtext / args->linehth;
	args->tex.tex_pos = (args->drawstart - args->resol[1] / 2 + args->linehth / 2) * args->tex.step_tex;
}

int ft_raycasting(t_read *args)
{
  int x;

  x = 0;
  while ( x < args->resol[0])
  {
    args->camerax = 2 * x / (double)args->resol[0] - 1;
  	args->raydirx = args->dirx + args->planex * args->camerax;
    args->raydiry = args->diry + args->planey * args->camerax;

    args->mapx = (int)args->posx;
    args->mapy = (int)args->posy;

    args->hit = 0; 
    args->deltadistx = sqrt(1 + (args->raydiry * args->raydiry) / 
      (args->raydirx * args->raydirx));
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
    else 
      args->perpwalldist = fabs((args->mapy - args->posy + (1 - args->stepy) / 2) / args->raydiry);         
    args->linehth = (int)(args->resol[1] / args->perpwalldist);
  
    args->linehth = (args->linehth < 0) ? INT_MAX : args->linehth;
   args->drawstart = (-1 * (args->linehth)) / 2 + (args->resol[1] / 2);
    if(args->drawstart < 0)
      args->drawstart = 0; 

    args->drawend = args->linehth / 2 + args->resol[1] / 2;
    if(args->drawend >= args->resol[1])
      args->drawend = args->resol[1] - 1;
   ft_size_text(args);
   ft_wall_tex(args);
    args->ycoor = 0;
    while (args->ycoor < args->drawstart)
    {
      ft_draw_to_image(args, x, args->ycoor, args->ceiling);
      args->ycoor++;
    }
    while (args->ycoor < args->drawend)
    {
      args->tex.y = (int)args->tex.tex_pos;
      args->tex.tex_pos += args->tex.step_tex;
     if (args->tex.y < 0 || args->tex.y >= args->hthtext)
        args->tex.y = (args->tex.y < 0) ? 0 : args->hthtext - 1;
      pix_color(args);
      ft_draw_to_image(args, x, args->ycoor, args->color);
      args->ycoor++;
    }
    while (args->ycoor < args->resol[1])
    {
      ft_draw_to_image(args, x, args->ycoor, args->floor);
      args->ycoor++;
    }
    args->zbuffer[x] = args->perpwalldist;
    x++;
  }
  ft_sprite(args);
  mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, args->img, 0, 0);
  ft_hook(args);
  return(1);
}
