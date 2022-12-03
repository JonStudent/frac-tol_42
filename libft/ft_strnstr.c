/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:00:47 by jbasilio          #+#    #+#             */
/*   Updated: 2022/04/01 21:49:22 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Finds and returns the 's2' string in the 's1' string.
	Returns NULL if not found.
*/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n-- && *s1 && s2[i])
	{
		if (*s1++ != s2[i++])
		{
			s1 -= --i;
			n += i;
			i = 0;
		}
	}
	if (!s2[i])
		return ((char *)s1 - i);
	return (NULL);
}
