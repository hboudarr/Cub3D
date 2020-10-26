/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:25:11 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/23 17:05:20 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include "libft.h"
# include <limits.h>
# include <sys/stat.h>

# define W 13
# define S 1
# define A 0
# define D 2
# define FWD 126
# define BWD 125
# define ESC 53
# define ROTLEFT 123
# define ROTRIGHT 124
# define MOVESPEED 0.15
# define ROTSPEED 0.025

typedef struct		s_img
{
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bbp;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_total;
	unsigned int	clr_important;
}					t_img;

typedef	struct		s_spcast
{
	int				i;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				sp_screenx;
	int				sp_height;
	int				sp_width;
	int				draw_starty;
	int				draw_endy;
	int				draw_startx;
	int				draw_endx;
	int				x;
	int				y;
	int				texx;
	int				texy;
	int				d;
}					t_spcast;

typedef	struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef	struct		s_texures{

	void			*tex_ptr;
	int				*tex_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;

}					t_textures;

typedef	struct		s_tex{
	int				x;
	int				y;
	double			step_tex;
	double			tex_pos;
	double			rh;
}					t_tex;

typedef	struct		s_rgb{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef	struct		s_read{
	char			*s;
	char			**map;
	char			**mapdup;
	int				i;
	int				count;
	int				x;
	int				y;
	double			posx;
	double			posy;
	int				tab[8];
	int				resol[2];
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sp;
	int				f[3];
	int				c[3];
	char			**split;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	void			*win_ptr;
	void			*mlx_ptr;
	int				wth;
	int				hth;
	double			raydirx;
	double			raydiry;
	double			camerax;
	double			cameray;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				linehth;
	int				drawstart;
	int				drawend;
	unsigned int	color;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*img;
	int				xcoor;
	int				ycoor;
	double			olddirx;
	int				fwd;
	int				bwd;
	int				left;
	int				right;
	int				rotleft;
	int				rotright;
	unsigned int	ceiling;
	unsigned int	floor;
	t_rgb			rgb;
	t_tex			tex;
	t_textures		*tex1;
	t_textures		*tex2;
	t_textures		*tex3;
	t_textures		*tex4;
	t_textures		*sprite;
	int				hthtext;
	int				wthtext;
	int				nbsp;
	t_sprite		*tab_sprite;
	int				*sp_order;
	double			*sp_dist;
	double			*zbuffer;
	int				mapwidth;
	int				fd;
}					t_read;

void				ft_init(t_read *args);
void				ft_read(t_read *args);
int					ft_check_element(int tab[8]);
void				ft_analyse_line(t_read *args, char *str);
void				ft_get_resol(t_read *args, char *str);
void				ft_get_north(t_read *north, char *str, int i);
void				ft_get_south(t_read *args, char *str, int i);
void				ft_get_west(t_read *args, char *str, int i);
void				ft_get_east(t_read *args, char *str, int i);
void				ft_get_sprite(t_read *args, char *str, int i);
void				ft_get_floor(t_read *args, char *str, int i);
void				ft_get_floor_rgb(t_read *args);
void				ft_get_celling(t_read *args, char *str, int i);
void				ft_get_ceiling_rgb(t_read *args);
void				ft_free_split(char **tab);
int					ft_check_nb(char *str1, char *str2);
void				ft_check_value(char *str, t_read *args);
void				ft_check_resolution(int i, int j, t_read *args);
int					ft_checking(char **map, int x, int y, int max);
void				ft_main2(t_read *args);
void				ft_make_range(t_read *args);
void				ft_make_map(t_read *args);
int					ft_flood_fill(char **map, int x, int y, int max);
void				ft_analyse_str(t_read *args);
void				ft_read_second_part(t_read *args);
int					ft_check_alphanum(char *str, char *letter);
void				ft_orient(t_read *args, char c);
void				ft_orient2(t_read *args, char c);
void				ft_free_map(t_read *args, char **map);
char				*ft_strdup(const char *src);
char				**ft_split(char const *s, char c);
int					ft_isalpha(int c);
int					is_whitespace(int c);
int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);
void				ft_init(t_read *args);
void				ft_bzero(void *s, int size);
int					ft_check_filename(char *str);
int					ft_raycasting(t_read *args);
void				ft_ray1(t_read *args, int x);
void				ft_ray2(t_read *args);
void				ft_ray3(t_read *args);
void				ft_ray4(t_read *args);
void				ft_ray5(t_read *args, int x);
void				ft_draw_to_image(t_read *data, int x, int y, int color);
int					ft_key_press(int key, t_read *args);
int					ft_key_release(int key, t_read *args);
int					ft_display_color(t_read *args, int x);
void				ft_wall_tex(t_read *args);
void				ft_textures_data(t_read *args);
void				ft_textures_data2(t_read *args);
void				pix_color(t_read *args);
void				pixel_tex(t_textures *tex, t_read *args);
void				ft_size_text(t_read *args);
void				ft_sprite(t_read *args);
void				ft_sp1(t_read *args, t_spcast *spcast);
void				ft_sp2(t_read *args, t_spcast *spcast);
void				ft_sp3(t_read *args, t_spcast *spcast);
void				ft_sp4(t_read *args, t_spcast *spcast);
void				ft_place_sprites(t_read *args);
void				ft_order_sprite(t_read *args);
void				ft_sort(int *order, double *dist, int num);
void				ft_raysprite(t_read *args);
int					ft_hook(t_read *args);
void				ft_move_fwd(t_read *args);
void				ft_move_bwd(t_read *args);
void				ft_move_left(t_read *args);
void				ft_move_right(t_read *args);
void				ft_rotate(t_read *args, int advance);
void				ft_define_ptr(t_read *args, t_img *ptr);
void				ft_tab_in_img(t_read *args, int fd);
void				ft_create_img(t_read *args);
int					ft_check_arg(char *str);
void				ft_error(int nb);
void				ft_exit1(t_read *args);
void				ft_exit2(void);
void				ft_exit3(t_read *args, char *str, int nb);
void				ft_exit4(t_read *args, int nb);
void				ft_free_args(t_read *args);
void				ft_free_args2(t_read *args);
int					ft_deal_exit(t_read *args);
void				ft_check_line(char *str, t_read *args);
void				ft_parse_empty_line(t_read *args);
void				ft_destroy_images(t_read *args);
void				ft_init2(t_read *args);

#endif
