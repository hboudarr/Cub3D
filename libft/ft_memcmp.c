/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:43:51 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/13 18:29:58 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *ss1;
	unsigned const char *ss2;
	size_t				i;

	i = 0;
	ss1 = s1;
	ss2 = s2;
	if (n == 0)
		return (0);
	while (n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
		n--;
	}
	return (0);
}
