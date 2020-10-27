/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:15:28 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/27 10:30:48 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(t_read *args)
{
	ft_bzero(args, sizeof(*args));
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
	args->tex4->tex_data = NULL;
	args->sprite = malloc(sizeof(t_textures));
	ft_bzero(args->sprite, sizeof(t_textures));
	args->sprite->tex_ptr = NULL;
	args->sprite->tex_data = NULL;
	ft_init2(args);
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
	if (args->fwd == 1)
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
	if (str[i] != '1')
		ft_exit3(args, str, 8);
	if (str[j - 1] != '1')
		ft_exit3(args, str, 8);
}

void	ft_analyse_str(t_read *args)
{
	int i;

	i = 0;
	if (ft_check_alphanum(args->s, "NSEW102 ") == 0)
		ft_exit3(args, args->s, 8);
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
		ft_exit3(args, args->s, 1);
}
