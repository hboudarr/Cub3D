/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:58:21 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/20 15:55:16 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t x;
	size_t y;
	size_t z;

	x = ft_strlen(dest);
	y = ft_strlen(src);
	z = 0;
	if (size <= x)
		return (y + size);
	y = y + x;
	while (src[z] && x + 1 < size)
	{
		dest[x] = src[z];
		x++;
		z++;
	}
	dest[x] = '\0';
	return (y);
}
