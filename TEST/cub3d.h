/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:25:11 by hboudarr          #+#    #+#             */
/*   Updated: 2020/05/28 16:54:42 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "math.h"
# include "get_next_line.h"

typedef	struct		s_read{
		char 	*get_line;
		int		count;
}					t_read;

void			ft_parse_map(int fd, t_read *args);

#endif
