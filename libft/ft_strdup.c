/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 03:41:32 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/26 06:25:27 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
				DESCRIPTION:
	Duplicates (malloc) the (const char) Parameter 's'.
If sucessful returns the created string, if not returns 0.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	p = malloc(ft_strlen(s) + 1);
	if (p)
		return (ft_memcpy(p, s, ft_strlen(s) + 1));
	return (0);
}
