/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:09:49 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/30 15:12:19 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
				DESCRIPTION:
	Converts a Parameter integer to a sring, Returning the new string.
*/

#include "libft.h"

static char	*ft_write(char *nbr, long int n, int chrs)
{
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}
	if (n > 9)
		ft_write(nbr, (n / 10), chrs - 1);
	nbr[chrs] = "0123456789"[n % 10];
	return (nbr);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			chrs;
	long int	ln;

	ln = n;
	chrs = 1;
	if ((ln < 0 && chrs++) || 1)
		while (n / 10 && ++chrs)
			n /= 10;
	nbr = (char *)malloc(sizeof(char) * (chrs + 1));
	if (!nbr)
		return (0);
	ft_write(nbr, ln, chrs - 1)[chrs] = 0;
	return (nbr);
}
