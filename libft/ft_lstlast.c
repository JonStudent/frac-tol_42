/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:46:07 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/29 17:09:34 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
			DESCRIPTION:

	Returns the adress to the last node of the Parameter List 'lst'.
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
