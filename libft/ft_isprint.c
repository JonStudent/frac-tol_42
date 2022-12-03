/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:03:14 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 16:50:02 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
				DESCRIPTION;

	Returns 1 or 0 if Parameter 'c' is a rpintable characeter.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= ' ' && c < 127);
}
