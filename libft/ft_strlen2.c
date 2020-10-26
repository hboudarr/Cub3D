/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:45:48 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/26 10:37:54 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2(char *str)
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
