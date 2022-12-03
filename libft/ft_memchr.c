/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:56:16 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 18:17:09 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Returns the Adress in the (const)Adress of a string Parameter 's', if the 
	(int)Parameter 'c' is found within (size_t)Parameter 'n'.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (n && n > ++i)
		if (*(char *)(s + i) == (char)c)
			return ((void *)(s + i));
	return (NULL);
}
/*
int	main()
{
	char str[] = "hi my name";
	printf("%s\n", (char *)ft_memchr(str, 'y',4));
	printf("%s\n", (char *)memchr(str, 'y',4));
}*/
