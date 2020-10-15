/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <hboudarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:09:58 by hboudarr          #+#    #+#             */
/*   Updated: 2020/10/15 15:27:51 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void		ft_error(int nb)
{
	if (nb == 1)
		write(1, "Can't open your file\n", 21);
	if (nb == 2)
		write(1, "An error has occurred with gnl\n", 31);
	if (nb == 3)
		write(1, "End of file\n", 12);
	if (nb == 4)
		write(1, "Wrong allocation in malloc\n", 27);
	if (nb == 5)
		write(1, "Wrong information for north texture\n", 37);
	if (nb == 6)
		write(1, "Wrong information for south texture\n", 37);
	if (nb == 7)
		write(1, "Wrong information for west texture\n", 36);
	if (nb == 8)
		write(1, "Wrong information for east texture\n", 36);
	if (nb == 9)
		write(1, "Wrong information for sprite texture\n", 38);
	if (nb == 10)
		write(1, "Wrong information for floor\n", 28);
	if (nb == 11)
		write(1, "Wrong information for celling\n", 30);
	if (nb == 12)
		write(1, "Wrong map information\n", 22);
	if (nb == 13)
		write(1, "Wrong information\n", 18);
	exit(0); // changer le retour de fonction par void pour exite.
//	return (0);
}
