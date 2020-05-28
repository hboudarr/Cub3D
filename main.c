/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:40:29 by hboudarr          #+#    #+#             */
/*   Updated: 2020/05/27 19:17:21 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int		fd;
	char	*line;
	int		ret;

//	if (ac == 1)
//		return (-1);
	line = NULL;
	if ((fd = open("./maps/first.cub", O_RDONLY)) < 0)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("line : |%s| ret : %d\n", line, ret);
		free(line);
		//line = NULL;
	}
	close(fd);
	return (0);
} 
