/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:07:37 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/26 10:37:22 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int i;
	int	y;

	i = 0;
	y = 0;
	if (s == NULL)
		y = 0;
	else
	{
		while (s[i] != '\0')
		{
			y++;
			i++;
		}
	}
	return (y);
}
