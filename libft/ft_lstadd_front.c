/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:18:04 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/30 14:11:01 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
				DESCRIPTION:
        Adds a node to the beginning of a Linked List.
        PARAMETERS:     Adress of Pointer to Linked List (header).
                NO_RETURN	
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *nw)
{
	if (*lst)
		nw->next = *lst;
	*lst = nw;
}
