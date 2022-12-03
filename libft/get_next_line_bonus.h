/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:42 by jbasilio          #+#    #+#             */
/*   Updated: 2022/10/06 20:47:39 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_fd
{
	char	*rt_bf;
	char	*tp_bf;
	char	rd_bf[BUFFER_SIZE + 1];
	int		rt_i;
	int		rd_i;
	int		tp_i;
	int		rd;
	int		f;
	int		out;
}	t_fd;

char	*get_next_line(int fd);
char	*filler(t_fd *the_fd, int fd);
#endif
