/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:15:28 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/20 16:21:27 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(t_read *args)
{
	ft_bzero(args, sizeof(*args));
	args->s = NULL;
	args->map = NULL;
	args->mapdup = NULL;
	args->split = NULL;
	args->no = NULL;
	args->ea = NULL;
	args->so = NULL;
	args->we = NULL;
	args->sp = NULL;
	args->win_ptr = NULL;
	args->mlx_ptr = NULL;
	args->addr = NULL;
	args->img = NULL;
	args->sp_order = NULL;
	args->sp_dist = NULL;
	args->zbuffer = NULL;
	args->tex1 = malloc(sizeof(t_textures));
	ft_bzero(args->tex1, sizeof(t_textures));
	args->tex1->tex_ptr = NULL;
	args->tex1->tex_data = NULL;
	args->tex2 = malloc(sizeof(t_textures));
	ft_bzero(args->tex2, sizeof(t_textures));
	args->tex2->tex_ptr = NULL;
	args->tex2->tex_data = NULL;
	args->tex3 = malloc(sizeof(t_textures));
	ft_bzero(args->tex3, sizeof(t_textures));
	args->tex3->tex_ptr = NULL;
	args->tex3->tex_data = NULL;
	args->tex4 = malloc(sizeof(t_textures));
	ft_bzero(args->tex4, sizeof(t_textures));
	args->tex4->tex_ptr = NULL;
	args->tex1->tex_data = NULL;
	args->sprite = malloc(sizeof(t_textures));
	ft_bzero(args->sprite, sizeof(t_textures));
	args->sprite->tex_ptr = NULL;
	args->sprite->tex_data = NULL;
	args->tab_sprite = malloc(sizeof(t_sprite));
	ft_bzero(args->tab_sprite, sizeof(t_sprite));
	args->f[0] = -1;
	args->f[1] = -1;
	args->f[2] = -1;
	args->c[0] = -1;
	args->c[1] = -1;
	args->c[2] = -1;
	args->rgb.r = 0;
	args->rgb.g = 0;
	args->rgb.b = 0;
}

void	ft_bzero(void *s, int n)
{
	unsigned char	*dest;

	dest = s;
	while (n)
	{
		*dest = 0;
		n--;
		dest++;
	}
}

void	ft_move_fwd(t_read *args)
{
	if (args->fwd == 1 || args->ktab[0] == 1 || args->ktab[7])
	{
		if (args->map[(int)(args->posy)][(int)(args->posx + args->dirx
			* 0.15)] == '0')
			args->posx += args->dirx * 0.15;
		if (args->map[(int)(args->posy + args->diry * 0.15)]
		[(int)(args->posx)] == '0')
			args->posy += args->diry * 0.15;
	}
}

void	ft_check_line(char *str, t_read *args)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(str);
	//printf("%c\n", args->s[i]);
	//printf("%c\n", args->s[j]);
	if (str[i] != '1')
		ft_exit1(args);
	if (str[j - 1] != '1')
		ft_exit1(args);
}

void	ft_analyse_str(t_read *args)
{
	int i;

	i = 0;
	//if (args->s == '\0')
	//	ft_exit1(args);
	if (ft_check_alphanum(args->s, "NSEW102 ") == 0)
		ft_exit4(args);
	//ft_check_line(args->s, args);
//	if (args->s[i] == '0')
//		ft_exit1(args);
//	while (args->s[i] != '\0')
//		args->s[i++];
//	if (args->s[i] == '0')
//		ft_exit1(args);
	while (args->s[i])
	{
		
		if (args->s[i] == 'N' || args->s[i] == 'S' ||
		args->s[i] == 'E' || args->s[i] == 'W')
		{
			args->posy = (args->y - 1) + 0.5;
			args->posx = i + 0.5;
			args->count += 1;
			ft_orient(args, args->s[i]);
			args->s[i] = '0';
		}
		if (args->s[i] == '2')
			args->nbsp += 1;
		i++;
	}
	if (args->count > 1)
		ft_exit4(args);
}
