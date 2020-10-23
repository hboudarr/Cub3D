/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:59:27 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/20 16:34:16 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < len)
	{
		if (ft_strncmp((char *)&s1[i], s2, ft_strlen(s2)) == 0)
		{
			if (i + ft_strlen(s2) > len)
				return (NULL);
			return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
