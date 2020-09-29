/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:25:11 by hboudarr          #+#    #+#             */
/*   Updated: 2020/09/29 15:41:17 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"
# include <limits.h>

# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define MOVESPEED 0.15
# define ROTSPEED 0.025

# ifndef BUFER_SIZE
# define BUFFER_SIZE 7
#endif 

// STRUCTURE DE PARSING

void ft_bzero(void *s, int size);

typedef	struct		s_read{
		char	*s;
		char	**map;
		char 	**mapdup;
		int		i;
		int		count;
		int		x;
		int		y;
		double		posx;
		double		posy;
		int		tab[8];
		int		resol[2];
		char	*no;
		char	*so;
		char	*we;
		char	*ea;
		char	*sp;
		int		f[3];
		int		c[3];
		char	**split;
		double	dirx;
		double 	diry;
		double 	planex;
		double	planey;
		void	*win_ptr;
		void	*mlx_ptr;
		int		wth;
		int		hth;
		double	raydirx;
		double	raydiry;
		double	camerax;
		double	cameray;
		int		mapx;
		int		mapy;
		double 	sidedistx;
      	double 	sidedisty;
		double 	deltadistx;
		double 	deltadisty;
		double	perpwalldist;
		int		stepx;
		int		stepy;
		int		hit;
		int		side;
		int		linehth;
		int		drawstart;
		int		drawend;
		unsigned int	color;
		char        *addr;
   		int         bits_per_pixel;
    	int         line_length;
    	int         endian;
		void		*img;
		int			padding;
		int			xcoor;
		int			ycoor;
		double		olddirx;
		int			padding2;
		double		oldplanex;
		int			padding3;
		int			up;
		int			down;
		int			left;
		int			right;





}					t_read;


void	draw_to_image(t_read *data, int x, int y, int color);


// ERROR FONCTION

void		ft_error(int nb); 
//int			ft_error(int nb);

// 1st PART OF PARSING FUNCTIONS

void  	    ft_init(t_read *args);
void		ft_read(t_read *args, int fd);
int			ft_check_element(int tab[8]);
void		ft_analyse_line(t_read *args, char *str);
void		ft_get_resol(t_read *args, char *str, int i);
void		ft_get_north(t_read *north, char *str, int i);
void		ft_get_south(t_read *args, char *str, int i);
void		ft_get_south(t_read *args, char *str, int i);
void		ft_get_west(t_read *args, char *str, int i);
void		ft_get_east(t_read *args, char *str, int i);
void		ft_get_sprite(t_read *args, char *str, int i);
void		ft_get_floor(t_read *args, char *str, int i);
void		ft_get_celling(t_read *args, char *str, int i);
void		ft_free_split(char **tab);
int			ft_check_nb(char *str1, char *str2);
void		ft_check_value(char *str);
void		ft_check_resolution(int i, int j);

// 2nd PART OF PARSING FUNCTIONS

void		ft_make_range(t_read *args);
void		ft_make_map(t_read *args);
int			ft_flood_fill(char **map, int x, int y, int max);
void		ft_read_second_part(t_read *args, int fd);
void		ft_analyse_str(t_read *args);
int			ft_check_alphanum(char *str, char *letter);
void		ft_orient(t_read *args, char c);
void		ft_orient2(t_read *args, char c);

// STRDUP + SPLIT

char		*ft_strdup(const char *src);
char		**ft_split(char const *s, char c);

// UTILE FONCTION

int		ft_isalpha(int c);
int		is_whitespace(int c);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void    ft_init(t_read *args);

// RAY

int		ft_raycasting(t_read *args);
int		ft_key_press(int key, t_read *args);
int		ft_key_release(int key, t_read 	*args);

// MOVE

int 	ft_hook(t_read  *args);
void  	ft_move_fwd(t_read *args);


#endif
