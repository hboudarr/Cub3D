/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:21:14 by hboudarr          #+#    #+#             */
/*   Updated: 2020/01/06 15:36:36 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)s;
	if (!s)
		return (NULL);
	while (s1[i])
	{
		if (s1[i] == c)
			return (&s1[i]);
		i++;
	}
	if (s1[i] == c)
		return (&s1[i]);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	if (str == NULL)
		count = 0;
	else
	{
		while (str[i] != '\0')
		{
			count++;
			i++;
		}
	}
	return (count);
}

char	*ft_strndup(char *s1, int n)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * n + 1);
	if (copy == NULL)
		return (NULL);
	while (i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	i = 0;
	dest = NULL;
	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
