/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 14:20:43 by hboudarr          #+#    #+#             */
/*   Updated: 2020/01/06 16:03:15 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_get_line(char *left, char **line, int ret)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (left != NULL)
	{
		while (left[i] != '\n' && left[i] != '\0')
			i++;
		*line = ft_strndup(left, i);
		if (ret > 0)
			dest = ft_substr(left, i + 1, (ft_strlen(left) - i));
	}
	free(left);
	return (dest);
}

int		ft_free(char *left)
{
	if (left != NULL)
		free(left);
	return (-1);
}

int		get_next_line(int fd, char **line, int flag)
{
	static char *left = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (flag == 1 && left)
	{	
		free(left);
		return(0);
	}
	if (fd < 0 || fd > 10000 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	ret = 1;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		while (ret > 0 && ft_strchr(left, '\n') == NULL)
		{
			if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
				return (ft_free(left));
			buf[ret] = '\0';
			left = ft_strjoin(left, buf);
		}
		left = ft_get_line(left, line, ret);
	}
	if (ret == 0)
		free(left);
	if (ret > 1)
		ret = 1;
	return (ret);
}
