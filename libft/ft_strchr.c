/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:48:51 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 18:47:06 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Finds a (int) Parameter 'c' in the (const char) Parameter 's' and Returnsi
	its (char) Adress, or NULL if not found.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*
int	main()
{
	int lt = 367;
	char *str = "godmother";
	printf("%s\n%s\n", ft_strchr(str, lt), strchr(str, lt));
}*/
