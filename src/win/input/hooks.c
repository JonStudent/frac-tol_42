/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:53:33 by jbasilio          #+#    #+#             */
/*   Updated: 2022/12/12 21:53:34 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

int	dance(int x, int y, t_frtl *f)
{
	return (mouse(1, x, y, f));
}

int	expose(t_frtl *f)
{
	if (f->opt >> 5 & 1)
		return (!++f->lock);
	else if (!f->lock)
		return (fill_win(f));
	return (0);
}

int	wait(t_frtl *f)
{
	if (f->opt >> 5 & 1 && f->lock)
		fill_win(f);
	if ((f->opt >> 5 & 1 || f->child->opt >> 5 & 1) && f->child->lock)
		fill_win(f->child);
	f->lock = 0;
	f->child->lock = 0;
	return (0);
}
