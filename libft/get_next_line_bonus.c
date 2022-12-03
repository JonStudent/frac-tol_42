/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:15:24 by jbasilio          #+#    #+#             */
/*   Updated: 2022/10/06 20:44:23 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fd	tab[FOPEN_MAX];

	if (read(fd, 0, 0) == -1 || fd >= FOPEN_MAX)
		return (NULL);
	tab[fd].tp_i = -1;
	tab[fd].tp_bf = malloc(tab[fd].rt_i + BUFFER_SIZE + 1);
	while (tab[fd].tp_bf && ++tab[fd].tp_i < tab[fd].rt_i)
		tab[fd].tp_bf[tab[fd].tp_i] = tab[fd].rt_bf[tab[fd].tp_i];
	if (tab[fd].f)
		free(tab[fd].rt_bf);
	tab[fd].rt_bf = tab[fd].tp_bf;
	return (filler(&tab[fd], fd));
}
