/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:11:19 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 16:49:09 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
				DESCRIPTION:
	Returns 1 or 0 if Parameter 'c' is a digit.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
