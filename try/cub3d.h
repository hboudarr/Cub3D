/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:25:11 by hboudarr          #+#    #+#             */
/*   Updated: 2020/06/15 18:27:50 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "get_next_line.h"


# ifndef BUFER_SIZE
# define BUFFER_SIZE 7
#endif 

// STRUCTURE DE PARSING

typedef	struct		s_read{
		char	*s;
		char	**map;
		char 	**mapdup;
		int		i;
		int		count;
		int		x;
		int		y;
		int		posX;
		int		posY;
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
		void	*mlx_ptr;
}					t_read;



// ERROR FONCTION

void		ft_error(int nb); 
//int			ft_error(int nb);

// 1st PART OF PARSING FUNCTIONS

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

// STRDUP + SPLIT
char		*ft_strdup(const char *src);
char		**ft_split(char const *s, char c);

// UTILE FONCTION

int		ft_isalpha(int c);
int		is_whitespace(int c);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

#endif
