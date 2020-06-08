/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:25:11 by hboudarr          #+#    #+#             */
/*   Updated: 2020/06/08 14:56:48 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
// include "math.h"
# include "get_next_line.h"

// STRUCTURE DE PARSING

# ifndef BUFER_SIZE
# define BUFFER_SIZE 7
#endif 

typedef	struct		s_read{
		char 	*get_line;
		int		resol[2];
		int		x;
		int		y;
		char 	**map;
}					t_read;

// PARSING FONCTION

void			ft_parse_map(int fd, char *str);
int				ft_parse_resolution(char *str, int fd, t_read args);
int				ft_parse_resolution1(char *str, int fd, t_read args);
int				ft_parse_north(char *str, int fd, t_read args);
void			ft_parse_tabx(int fd, t_read *args);
void			make_scene(t_read *args, int fd);
void			print_tab(t_read *args);

// UTILE FONCTIONS

int		ft_atoi(const char *nptr);
int		is_whitespace(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);

// SPLIT FUNCTION

static int		chaines(char *str, char c);
static char		**free_tab(char **tab, int size);
char			**ft_split(char const *s, char c);

#endif
