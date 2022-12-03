/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 03:09:05 by jbasilio          #+#    #+#             */
/*   Updated: 2022/04/26 13:18:35 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
					DESCRIPTION:
	Allocate and sets to 0 count * size bytes.
	PARAMERS: 	SIZE and COUNT (of the bytes to allocate).
	RETURN:		void pointer to the created memory.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && ((size_t)(-1) / size) < count)
		return (NULL);
	p = malloc(count * size);
	if (p)
		ft_bzero(p, count * size);
	return (p);
}
