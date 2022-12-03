/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 09:24:27 by jbasilio          #+#    #+#             */
/*   Updated: 2022/03/30 14:17:28 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                          DESCRIPTION:
* Ft_lstnew allocates (malloc) and returns a new node/element of 
* the t_list struct/list.
* The MEMBER variable 'content' is initialized with the value of the parameter 
* 'content' and the 'next' with NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlst;

	newlst = (t_list *)malloc(sizeof(t_list));
	if (!newlst)
		return (0);
	(*newlst).content = content;
	newlst->next = 0;
	return (newlst);
}
