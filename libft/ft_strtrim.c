/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:47:50 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/26 08:12:17 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
		Trims from the 's1' string any of the 'set' chars from the begging and end.
*/

#include "libft.h"

static int	check(const char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		s1_len;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	while (check(*s1, set))
		if (s1++)
			s1_len--;
	if (!(*s1))
		return (ft_strdup(""));
	while (check(s1[s1_len - 1], set))
		s1_len--;
	trim = ft_substr(s1, 0, &s1[s1_len] - s1);
	if (!trim)
		return (NULL);
	return (trim);
}
