/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:17:18 by hboudarr          #+#    #+#             */
/*   Updated: 2020/06/12 16:32:05 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

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


void	ft_get_resol(t_read *args, char *str, int i)
{
	
		i++;
		printf("str[i] : %c\n", str[i]);
		args->resol[0] = ft_atoi(&str[i]);
		printf("str[i] : %c\n", str[i]);
		while (str[i] == ' ')
			i++;
		args->resol[1] = ft_atoi(str + i);

		printf("Resol 1 : %d\n", args->resol[0]);
		printf("Resol 2 : %d\n", args->resol[1]);
		args->tab[0] = 1;
}

void	ft_get_north(t_read *args, char *str, int i)
{
		int		a;
		int		b;

		i++;
		while (str[i] == ' ')
			i++;
		args->no = ft_strdup(str + i);
		args->tab[1] = 1;
		if (!(mlx_xpm_file_to_image(args->mlx_ptr, args->no, &a, &b)))
			ft_error(5);
}

void	ft_get_south(t_read *args, char *str, int i)
{
		int		a;
		int		b;

		i++;
		while (str[i] == ' ')
			i++;
		args->so = ft_strdup(str + i);
		args->tab[2] = 1;
		if (!(mlx_xpm_file_to_image(args->mlx_ptr, args->so, &a, &b)))
			ft_error(6);
}

void	ft_get_west(t_read *args, char *str, int i)
{
		int		a;
		int		b;

		i++;
			while (str[i] == ' ')
				i++;
			args->we = ft_strdup(str + i);
			args->tab[3] = 1;
		if (!(mlx_xpm_file_to_image(args->mlx_ptr, args->we, &a, &b)))
			ft_error(7);
}

void	ft_get_east(t_read *args, char *str, int i)
{
		int		a;
		int		b;

		i++;
			while (str[i] == ' ')
				i++;
			args->ea = ft_strdup(str + i);
			args->tab[4] = 1;
		if (!(mlx_xpm_file_to_image(args->mlx_ptr, args->ea, &a, &b)))
			ft_error(8);
}

void	ft_get_sprite(t_read *args, char *str, int i)
{
		int		a;
		int		b;

		i++;
			while (str[i] == ' ')
				i++;
			args->sp = ft_strdup(str + i);
			args->tab[5] = 1;
		if (!(mlx_xpm_file_to_image(args->mlx_ptr, args->sp, &a, &b)))
			ft_error(9);
}

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

void	ft_get_floor(t_read *args, char *str, int i)
{
	i++;
	args->split = ft_split(str + i, ',');
	if ((!(args->split[2])) || args->split[3])
		ft_error(10);
	args->f[0] = ft_atoi(args->split[0]);
	args->f[1] = ft_atoi(args->split[1]);
	args->f[2] = ft_atoi(args->split[2]);
	args->tab[6] = 1;
	printf("Floor 1 : %d\n", args->f[0]);
	printf("Floor 2 : %d\n", args->f[1]);
	printf("Floor 3 : %d\n", args->f[2]);
	ft_free_split(args->split);
}

void	ft_get_celling(t_read *args, char *str, int i)
{
	i++;
	args->split = ft_split(str + i, ',');
	if ((!(args->split[2])) || args->split[3])
		ft_error(11);
	args->c[0] = ft_atoi(args->split[0]);
	args->c[1] = ft_atoi(args->split[1]);
	args->c[2] = ft_atoi(args->split[2]);
	args->tab[7] = 1;
	printf("Celling 1 : %d\n", args->c[0]);
	printf("Celling 2 : %d\n", args->c[1]);
	printf("Celling 3 : %d\n", args->c[2]);
	ft_free_split(args->split);
}
void	ft_analyse_line(t_read *args, char *str)
{
	int i;

	i = 0;
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
