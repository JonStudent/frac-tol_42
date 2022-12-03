/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:57:56 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 16:36:04 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
				DESCRIPTION:

	The ft_atoi function converts a string into an integer.
	It passes any space characters (isspace) and reads only one '+' or '-' 
	as the sign of the number, and finally the imidiatly after sequence of numbers.
	PARAMETER:	const string.
	RETURN:		Integer.
*/

#include "libft.h"

int	ft_atoi(const char *s)
{
	int			i;
	long int	n;

	i = 1;
	n = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			i = -1;
	while (*s >= '0' && *s <= '9')
		n = (n * 10) + (*s++ - '0');
	return (n * i);
}
/*
int	main()
{
	char nbr[] = "";
	printf("%d\n", ft_atoi(nbr));
	printf("%d\n", atoi(nbr));
}
*/
