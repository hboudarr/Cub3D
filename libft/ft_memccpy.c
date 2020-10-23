/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:38:17 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/20 16:18:22 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*destination;
	unsigned char		*source;
	size_t				i;

	destination = (unsigned char*)dest;
	source = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		if (destination[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		i++;
	}
	return (NULL);
}
