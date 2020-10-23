/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:40:41 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/20 13:42:37 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*dest;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_len(n);
	if (!(dest = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		dest[0] = '-';
	}
	dest[i] = '\0';
	i--;
	while (n > 0)
	{
		dest[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dest);
}
