/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:56:02 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/21 19:56:04 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Returns a pointer to the last occurrence of the character c in the string s.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (s && len && s[len] != (char)c)
		len--;
	if (s && s[len] == (char)c)
		return ((char *)(s + len));
	return (NULL);
}
/*
int     main()
{
        int lt = 367;
        char *str = "";
        printf("%s\n%s\n", ft_strrchr(str, lt), strrchr(str, lt));
}*/
