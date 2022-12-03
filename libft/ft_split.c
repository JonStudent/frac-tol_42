/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:59:02 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 18:44:39 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Splits the (const char) Adress Parameter 's' into sub strings with (malloc), 
	divided by the (char) Parameter 'c'.
	Returns the (char) Adress of the created array of 
	sub strings Adresses.
*/

#include "libft.h"

static	int	word_c(const char *s, char c, char **tab)
{
	int	count;
	int	ltrs;

	count = 0;
	while (*s)
	{
		ltrs = 0;
		if ((*s != c && ++count) || !s++)
			while (*s && *s != c)
				if (s++ && tab)
					ltrs++;
		if (ltrs)
		{
			tab[count - 1] = ft_substr((s - ltrs), 0, ltrs);
			if (!(tab[count - 1]))
				return (-1);
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = 0;
	if (s)
		tab = (char **)ft_calloc(sizeof(char *), (word_c(s, c, tab) + 1));
	if (!tab || word_c(s, c, tab) == -1)
		return (0);
	return (tab);
}
