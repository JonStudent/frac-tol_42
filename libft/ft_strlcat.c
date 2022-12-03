/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:39:36 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/26 03:45:59 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
				DESCRIPTION:
	Concatenates 'src' in 'dst', respecting 'dstsize'.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize || (!dst || !src))
		return (dstsize + ft_strlen(src));
	while (dstsize - 1 > dst_len && *src)
		dst[dst_len++] = *src++;
	dst[dst_len] = '\0';
	return (dst_len + ft_strlen(src));
}
/*
int	main()
{
	char *dst;
	dst = (char *)malloc(sizeof(*dst) * 15);
	memset(dst, 'r', 15);
	printf("%ld\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 5));
	write(1, dst, 15);
}*/
