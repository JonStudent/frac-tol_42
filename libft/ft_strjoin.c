/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:47:12 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/26 09:01:26 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Creates (malloc) a new string joinning s1 and s2.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (s2 && s1)
		s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s2 || !s1 || !s3)
		return (0);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (s3);
}
