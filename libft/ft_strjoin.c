/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:28:44 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/19 18:25:14 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(char) *
			(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}*/

char	*ft_strjoin(char *s1, char *s2)
{
	char		*dest;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = (char *)malloc((k + 1) * (sizeof(char)))))
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	if (s1 != NULL)
		free(s1);
	s2 = NULL;
	s1 = NULL;
	return (dest);
}

