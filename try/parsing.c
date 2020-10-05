

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:17:18 by hboudarr          #+#    #+#             */
/*   Updated: 2020/06/15 18:25:07 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	ft_free_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_check_element(int tab[8])
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (tab[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_nb(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] < 48 || str1[i] > 57)
			return (-1);
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		if (str2[i] < 48 || str2[i] > 57)
			return (-1);
		i++;
	}
	return (1);
}

void	ft_check_resolution(int i, int j)
{
	if (i < 0 || i > 2000)
		ft_error(13);
	if (j < 0 || j > 2570)
		ft_error(13);
}

void	ft_get_resol(t_read *args, char *str, int i)
{
	int		ret;
	i = 0;
		args->split = ft_split(str, ' ');
		if ((!(args->split[2])) || args->split[3])
			ft_error(13);
		args->resol[0] = ft_atoi(args->split[1]);
		args->resol[1] = ft_atoi(args->split[2]);
		ft_check_resolution(args->resol[0], args->resol[1]);
		ret = ft_check_nb(args->split[1], args->split[2]);
		if (ret == -1)
			ft_error(13);
		if (args->resol[0] <= 0 || args->resol[1] <= 0)	
			ft_error(13);
	//	printf("Resol 1 : %d\n", args->resol[0]);
	//	printf("Resol 2 : %d\n", args->resol[1]);
		args->tab[0] = 1;
		ft_free_split(args->split);
}

void	ft_get_north(t_read *args, char *str, int i)
{
		args->split = ft_split(str, ' ');
		if ((!(args->split[1]) || args->split[2]))
			ft_error(5);
		ft_free_split(args->split);
		i++;
		while (str[i] == ' ')
			i++;
		args->no = ft_strdup(str + i);
		args->tab[1] = 1;
		if (!(mlx_xpm_file_to_image(args->mlx_ptr, args->no, &args->tex1->width, &args->tex1->height)))
			ft_error(5);
}

void	ft_get_south(t_read *args, char *str, int i)
{
		args->split = ft_split(str, ' ');
		if ((!(args->split[1]) || args->split[2]))
				ft_error(6);
		ft_free_split(args->split);
		i++;
		while (str[i] == ' ')
			i++;
		args->so = ft_strdup(str + i);
		args->tab[2] = 1;
		if (!(mlx_xpm_file_to_image(args->mlx_ptr, args->so, &args->tex2->width, &args->tex2->height)))
			ft_error(6);
}

void	ft_get_west(t_read *args, char *str, int i)
{
//		int		a;
//		int		b;
		args->split = ft_split(str, ' ');
		if ((!(args->split[1]) || args->split[2]))
				ft_error(7);
		ft_free_split(args->split);
		i++;
			while (str[i] == ' ')
				i++;
			args->we = ft_strdup(str + i);
			args->tab[3] = 1;
		if (!(mlx_xpm_file_to_image(args->mlx_ptr, args->we, &args->tex3->width, &args->tex3->height)))
			ft_error(7);
}

void	ft_get_east(t_read *args, char *str, int i)
{
	//	int		a;
	//	int		b;
		args->split = ft_split(str, ' ');
		if ((!(args->split[1]) || args->split[2]))
			ft_error(8);
		ft_free_split(args->split);
		i++;
			while (str[i] == ' ')
				i++;
			args->ea = ft_strdup(str + i);
			args->tab[4] = 1;
		if (!(mlx_xpm_file_to_image(args->mlx_ptr, args->ea, &args->tex4->width, &args->tex4->height)))
			ft_error(8);
}

void	ft_get_sprite(t_read *args, char *str, int i)
{
//		int		a;
//		int		b;

	args->split = ft_split(str, ' ');
	if ((!(args->split[1]) || args->split[2]))
			ft_error(9);
	ft_free_split(args->split);
		i++;
			while (str[i] == ' ')
				i++;
			args->sp = ft_strdup(str + i);
			args->tab[5] = 1;
//		if (!(mlx_xpm_file_to_image(args->mlx_ptr, args->sp, &a, &b)))
//			ft_error(9);
}

void	ft_check_value(char *str)
{
	int	R;

	R = ft_atoi(str);
	if ((R < 0 || R > 255))
		ft_error(10);
}

void		ft_get_floor_rgb(t_read *args)
{
	args->rgb.r = args->f[0];
	args->rgb.g = args->f[1];
	args->rgb.b = args->f[2];
	args->floor = args->rgb.b + args->rgb.g * 256 + args->rgb.r * 65536;
//	printf("%u\n", args->floor);
//	printf("[%d]\t[%d]\t[%d]\n", args->rgb.r,args->rgb.g,args->rgb.b);
}

void	ft_get_floor(t_read *args, char *str, int i)
{
	args->split = ft_split(str, ' ');
	if ((!(args->split[1])) || args->split[2])
		ft_error(10);	
	ft_free_split(args->split);
	i++;
	args->split = ft_split(str + i, ',');
	if ((!(args->split[2])) || args->split[3])
		ft_error(10);
	ft_check_value(args->split[0]);
	ft_check_value(args->split[1]);
	ft_check_value(args->split[2]);
	args->f[0] = ft_atoi(args->split[0]);
	args->f[1] = ft_atoi(args->split[1]);
	args->f[2] = ft_atoi(args->split[2]);
	args->tab[6] = 1;
	ft_get_floor_rgb(args);
	ft_free_split(args->split);
}

void		ft_get_ceiling_rgb(t_read *args)
{
	args->rgb.r = args->c[0];
	args->rgb.g = args->c[1];
	args->rgb.b = args->c[2];
	args->ceiling = args->rgb.b + args->rgb.g * 256 + args->rgb.r * 65536;
//	printf("%u\n", args->ceiling);
//	printf("[%d]\t[%d]\t[%d]\n", args->rgb.r,args->rgb.g,args->rgb.b);
}
void	ft_get_celling(t_read *args, char *str, int i)
{
	args->split = ft_split(str, ' ');
	if ((!(args->split[1])) || args->split[2])
		ft_error(11);
	ft_free_split(args->split);
	i++;
	args->split = ft_split(str + i, ',');
	if ((!(args->split[2])) || args->split[3])
		ft_error(11);
	ft_check_value(args->split[0]);
	ft_check_value(args->split[1]);
	ft_check_value(args->split[2]);
	args->c[0] = ft_atoi(args->split[0]);
	args->c[1] = ft_atoi(args->split[1]);
	args->c[2] = ft_atoi(args->split[2]);
	ft_get_ceiling_rgb(args);
	args->tab[7] = 1;
	ft_free_split(args->split);
}
void	ft_analyse_line(t_read *args, char *str)
{
	int i;

	i = 0;
//	if (str[i] != ' ' || str[i] != 'N' || str[i] != 'R' || str[i] != 'S' || str[i] != 'W' || str[i] != 'E' || str[i] != 'F'
//			|| str[i] != 'C')
//		ft_error(13);
//	if (str[i] == ' ')
//	{
		while (str[i] == ' ')
		i++;
	if (str[i] == 'R')
		ft_get_resol(args, str, i);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_get_north(args, str, ++i);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		ft_get_south(args, str, ++i);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_get_west(args, str, ++i);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_get_east(args, str, ++i);
	else if (str[i] == 'S' && str[i + 1] == ' ')
		ft_get_sprite(args, str, i);
	else if (str[i] == 'F' && str[i + 1] == ' ')
		ft_get_floor(args, str, i);
	else if (str[i] == 'C' && str[i + 1] == ' ')
		ft_get_celling(args, str, i);
	else
		ft_error(13);
}

void	ft_read(t_read *args, int fd)
{
	//int		tab[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int 	ret;
	char	*line;
	int		i;
	
	ret = 0;
	i = 0;
	while (i < 8)
	{
//	line = args->get_line
		args->tab[i] = 0;
		i++;
	}
	while (ft_check_element(args->tab) == 0)
	{
		ret = get_next_line(fd, &line);
			if (ret == -1)
				ft_error(2);
			if (ret == 0)
				ft_error(3);
			if (line[0] != '\0')
				ft_analyse_line(args, line);
		free(line);
	}
}
