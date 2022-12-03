/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:17:43 by jbasilio          #+#    #+#             */
/*   Updated: 2022/10/06 20:51:40 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*filler(t_fd *f, int fd)
{
	if (!f->rd)
	{
		f->rd_i = 0;
		f->rd = read(fd, f->rd_bf, BUFFER_SIZE);
		if (f->rd < BUFFER_SIZE && f->rd >= 0)
			f->out = 1;
	}
	if (!f->rt_bf || f->rd < 0 || (!f->rt_i && !f->rd && f->out))
	{
		free(f->rt_bf);
		return (NULL);
	}
	if (!((f->rt_i + 1) % BUFFER_SIZE) && (!f->f || --f->f) && ++f->f)
		return (get_next_line(fd));
	if (f->rd && f->rd--)
		f->rt_bf[f->rt_i++] = f->rd_bf[f->rd_i++];
	if ((f->rd || !f->out) && f->rt_bf[f->rt_i - 1] != '\n')
		return (filler(f, fd));
	f->rt_bf[f->rt_i] = '\0';
	f->rt_i = 0;
	return (f->rt_bf);
}
