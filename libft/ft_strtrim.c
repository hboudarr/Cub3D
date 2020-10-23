/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:49:01 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/20 15:07:33 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_same(char *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_same((char*)set, (char)s1[i]))
		i++;
	j = i;
	while (s1[i])
		i++;
	while (i > j && ft_same((char*)set, (char)s1[i - 1]))
		i--;
	k = i - j;
	if (!(dest = (char *)malloc(sizeof(*s1) * (k + 1))))
		return (NULL);
	k = 0;
	while (j < i)
		dest[k++] = s1[j++];
	dest[k] = '\0';
	return (dest);
}
