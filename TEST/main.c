/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:40:29 by hboudarr          #+#    #+#             */
/*   Updated: 2020/05/28 16:54:34 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int		fd;
	int		ret;
	t_read	args;

//	if (ac == 1)
//		return (-1);
	if ((fd = open("first.cub", O_RDONLY)) < 0)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &args.get_line);	
		printf("str : %s\n", args.get_line);
		ft_parse_map(fd, args.get_line);
	//	printf("count ; %d\n", args.count);
	//	printf("recount; %d\n", args.recount);
		free(args.get_line);
	}
	close(fd);
	return (0);
} 


// recuperer la ligne, l'emvoyer a la fonction qui va parser pour recuperer les donnees. 
