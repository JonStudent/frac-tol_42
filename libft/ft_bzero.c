/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:04:36 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 16:39:22 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
					DESCRIPTION:
	The ft_bzero function sets n bytes of a buffer to 0.
	PARAMETERS:	void pointer.
		NO_RETURN
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
