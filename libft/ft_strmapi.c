/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:50:25 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/20 13:55:51 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(dest = ft_strdup(s)))
		return (NULL);
	while (s[i])
	{
		dest[i] = (*f)(i, dest[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
