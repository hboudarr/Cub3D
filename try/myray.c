#include "cub3d.h"

void	draw_to_image(t_read *data, int x, int y, int color)
{
	*(unsigned int *)(data->addr + y * data->line_length + x * data->bits_per_pixel / 8) = color;
}

/*
int worldMap[s_read->resol[0]][s_read->resol[1]]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
*/

int main(int ac, char **av)
{
    t_read      *args;
    int         fd;

    (void)ac;
  if (!(args = malloc(sizeof(t_read))))
    ft_error(4);
  ft_init(args);
  if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error(1);
  ft_read(args, fd);
	ft_read_second_part(args, fd);

 // printf("[%f]\t[%f]\n", args->posx, args->posy);
  

 // args->posx = 22, args->posy = 12;  //x and y start position
 // args->dirx = -1, args->diry = 0; //initial direction vector
 // args->planex = 0, args->planey = 0.66; //the 2d raycaster version of camera plane

 // double time = 0; //time of current frame
 // double oldTime = 0; //time of previous frame

 // screen(screenWidth, screenHeight, 0, "Raycaster"); // mlx init et new window
 // screen(args->resol[0], args->resol[1], 0, "CUB3D");
 args->mlx_ptr = mlx_init();
 args->win_ptr = mlx_new_window(args->mlx_ptr, args->resol[0], args->resol[1], "CUB3D");
 args->img = mlx_new_image(args->mlx_ptr, args->resol[0], args->resol[1]);
 args->addr = mlx_get_data_addr(args->img, &args->bits_per_pixel, &args->line_length, &args->endian);
 args->xcoor = 0;
  // while (mlx_loop(args->mlx_ptr))
 // {

printf("dirx = %f\n", args->dirx);
printf("diry = %f\n", args->diry);

//  printf("[%d]\t[%d]\n", args->mapx, args->mapy);
while (args->xcoor < args->resol[0])
{
   		   //calculate ray position and direction
  args->camerax = 2 * args->xcoor / args->resol[0] - 1; //x-coordinate in camera space
 	args->raydirx = args->dirx + args->planex * args->camerax;
  args->raydiry = args->diry + args->planey * args->camerax;
            //which box of the map we're in
  args->mapx = (int)args->posx;
  args->mapy = (int)args->posy;

      //length of ray from current position to next x or y-side
      //args->sidedistx;
      //args->sidedisty;

       //length of ray from one x or y-side to next x or y-side
      //args->deltadistx = fabs(1 / args->raydirx);
      //args->deltadisty = fabs(1 / args->raydiry);
      //if (args->xcoor == 0)
       // printf("%f\n%f\n", args->deltadistx, args->deltadisty);

      //args->perpwalldist;

      //what direction to step in x or y-direction (either +1 or -1)
      //args->stepx;
      //args->stepy;

  args->hit = 0; //was there a wall hit?
      //args->side; was a NS or a EW wall hit?

      // Alternative code for deltaDist in case division through zero is not supported
       // args->deltadistx = (args->raydiry == 0) ? 0 : ((args->raydirx == 0) ? 1 : fabs(1 / args->raydirx));
       // 
  args->deltadistx = fabs(1 / args->raydirx);
  args->deltadisty = fabs(1 / args->raydiry);

 //calculate step and initial sideDist
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
        //perform DDA
  while (args->hit == 0)
  {
        //jump to next map square, OR in x-direction, OR in y-direction
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
        //Check if ray has hit a wall
     //  printf("COUCOU [%d][%d]\n", args->mapy, args->mapx);
      // printf("COUCOU [%s\n", args->map[args->mapy]);
    if (args->map[args->mapy][args->mapx] == '1')
      args->hit = 1;
       // if (args->xcoor == 0)
         // printf("mapy = %d   mapx = %d\n", args->mapy, args->mapx);          
  }

         //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
  if (args->side == 0) 
    args->perpwalldist = (args->mapx - args->posx + (1 - args->stepx) / 2) / args->raydirx;
  else           
    args->perpwalldist = (args->mapy - args->posy + (1 - args->stepy) / 2) / args->raydiry;
      /*if (args->side == 0)  
        args->perpwalldist = (args->raydiry == 0) ? 0 : ((args->raydirx == 0) ? 1 : (args->mapx - args->posx + (1 - args->stepx) / 2) / args->raydirx);
      else
        args->deltadisty = (args->raydirx == 0) ? 0 : ((args->raydiry == 0) ? 1 : (args->mapy - args->posy + (1 - args->stepy) / 2) / args->raydiry);
        */
        
         //Calculate height of line to draw on screen
      // args->deltadistx = (args->raydiry == 0) ? 0 : ((args->raydirx == 0) ? 1 : fabs(1 / args->raydirx));
  args->linehth = args->resol[1] / args->perpwalldist;
  args->linehth = (args->linehth < 0) ? INT_MAX : args->linehth;
  //if (args->linehth < 0)
    //    args->linehth = INT_MAX;
      //calculate lowest and highest pixel to fill in current stripe
  args->drawstart = -args->linehth / 2 + args->resol[1] / 2;
  if(args->drawstart < 0)
    args->drawstart = 0;
  args->drawend = args->linehth / 2 + args->resol[1] / 2;
  if(args->drawend > args->resol[1])
    args->drawend = args->resol[1];

            //choose wall color

      args->color = 0x00FF0000;
      /* ColorRGB color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = RGB_Red;  break; //red
        case 2:  color = RGB_Green;  break; //green
        case 3:  color = RGB_Blue;   break; //blue
        case 4:  color = RGB_White;  break; //white
        default: color = RGB_Yellow; break; //yellow
      } */

      //give x and y sides different brightness
      if (args->side == 1) 
        args->color = args->color / 2;
        //draw the pixels of the stripe as a vertical line


      // verLine(x, drawStart, drawEnd, color);
      args->ycoor = args->drawstart;
      while (args->ycoor < args->drawend)
      {
        draw_to_image(args, args->xcoor, args->ycoor, args->color);
        args->ycoor++;
      }
      args->xcoor++;
      }
      mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, args->img, 0, 0);
      mlx_loop(args->mlx_ptr);

  return(0);
}
