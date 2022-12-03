/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 06:36:30 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 18:38:14 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Writes the (int) Parameter 'n' into the (int) FILE DESCRIPTOR Parameter 'fd'.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;

	ln = n;
	if (ln < 0 && write(fd, "-", 1))
		ln = -ln;
	if (ln > 9)
		ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd("0123456789"[ln % 10], fd);
}
