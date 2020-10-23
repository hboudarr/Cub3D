/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:14:58 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/21 14:11:28 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		chaines(char *str, char c)
{
	int i;
	int index;
	int j;

	i = 0;
	j = 0;
	index = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			index++;
			j = i;
			while (str[j] != c && str[j] != '\0')
				j++;
			i = j;
		}
	}
	return (index);
}

static char		**free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dest;

	i = 0;
	k = 0;
	if ((!s) || (!(dest = (char**)malloc(sizeof(char*) *
			(chaines((char*)s, c) + 1)))))
		return (NULL);
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[j] != c && s[j] != '\0')
				j++;
			if (!(dest[k++] = ft_substr((char *)s, i, (j - i))))
				return (free_tab(dest, i));
			i = j;
		}
	dest[k] = 0;
	return (dest);
}
