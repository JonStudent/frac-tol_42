/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:54:19 by jbasilio          #+#    #+#             */
/*   Updated: 2022/04/15 14:34:01 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Returns the first diference between 's1' 's2'. Comparing 'n' characters at most

*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (n > ++i)
		if (*(unsigned char *)(s1 + i) != ((unsigned char *)s2)[i]
				|| !s1[i] || !s2[i])
			return (*(unsigned char *)(s1 + i) - ((unsigned char *)s2)[i]);
	return (0);
}
