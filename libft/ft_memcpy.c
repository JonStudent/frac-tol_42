/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 10:24:06 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/30 14:14:18 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Returns the (void) Adress of the Parameter 'dst' copyied 
	from (void) Parameter 'src', 
	within (size_t) Perameter 'n'.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src || !n)
		return (dst);
	i = -1;
	while (++i < n)
		*((char *)dst + i) = *(char *)src++;
	return (dst);
}
