/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:25:11 by hboudarr          #+#    #+#             */
/*   Updated: 2020/06/11 21:16:24 by hboudarr         ###   ########.fr       */
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

int		ft_error(int nb);

// PARSING FONCTION

void		ft_read(t_read *args, int fd);
int			ft_check_element(int tab[8]);
void		ft_analyse_line(t_read *args, char *str, int tab[8]);
void		ft_get_resol(t_read *args, char *str, int i, int tab[8]);
void		ft_get_north(t_read *north, char *str, int i, int tab[8]);
void		ft_get_south(t_read *args, char *str, int i, int tab[8]);
void		ft_get_south(t_read *args, char *str, int i, int tab[8]);
void		ft_get_west(t_read *args, char *str, int i, int tab[8]);
void		ft_get_east(t_read *args, char *str, int i, int tab[8]);
void		ft_get_sprite(t_read *args, char *str, int i, int tab[8]);
void		ft_get_floor(t_read *args, char *str, int i,int tab[8]);
void		ft_get_celling(t_read *args, char *str, int i, int tab[8]);
void		ft_free_split(char **tab);

// STRDUP + SPLIT
char		*ft_strdup(const char *src);
char		**ft_split(char const *s, char c);

// UTILE FONCTION

int		ft_isalpha(int c);
int		is_whitespace(int c);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

#endif
