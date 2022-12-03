/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:17:17 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 18:28:41 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Moves (size_t) 'len' the (void) Parameter 'src' to the (void) Parameter 'dst',
	and returns its Adress.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src && len)
		while (len--)
			*((char *)dst + len) = *((char *)src + len);
	if (dst < src && len)
		ft_memcpy(dst, src, len);
	return (dst);
}
