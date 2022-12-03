/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:11:26 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/23 22:37:32 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Returns the newly created (malloc) string from the iteracion of 's' with 'f'.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	size_t	i;

	if (s)
		rtn = ft_strdup(s);
	if (!s || !rtn)
		return (0);
	i = -1;
	while (rtn[++i])
		rtn[i] = f(i, s[i]);
	return (rtn);
}
