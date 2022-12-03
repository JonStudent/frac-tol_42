/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:56:47 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/30 14:10:37 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
				DESCRIPTION:
	Adds a node to the end of a Linked List.
	PARAMETERS:	Adress of Pointer to Linked List(header).
		NO_RETURN
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	if (*lst)
		ft_lstlast(*lst)->next = nw;
	else
		*lst = nw;
}
