/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:13:49 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/20 12:03:17 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long int	i;
	long int	y;
	int			nb;

	nb = 0;
	i = 0;
	y = 1;
	while ((nptr[i] == ' ') || (nptr[i] == '\t') || (nptr[i] == '\v') ||
			(nptr[i] == '\n') || (nptr[i] == '\r') || (nptr[i] == '\f'))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			y = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * y);
}
