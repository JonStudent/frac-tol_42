/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:39:00 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 18:12:44 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:
	Returns the (int)size of the Linked List Adress Parameter 'lst'.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	lstsize;

	lstsize = 0;
	while (lst && ++lstsize)
		lst = lst->next;
	return (lstsize);
}
