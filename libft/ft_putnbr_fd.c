/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:54:55 by hboudarr          #+#    #+#             */
/*   Updated: 2019/11/20 15:34:04 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int u;

	u = nb < 0 ? -nb : nb;
	if (nb < 0)
		ft_putchar_fd('-', fd);
	if (u > 9)
		ft_putnbr_fd(u / 10, fd);
	ft_putchar_fd(u % 10 + '0', fd);
}
