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

int	move(int key, int x, int y, t_frtl *f)
{
	t_cx	from;
	t_cx	to;

	if (!(f->opt >> 5 & 1) && f->lock)
		return (0);
	if (key == 1 || key == 2)
		return (0);
	from = f->cx;
	coords(f, pxl(x, y));
	to = f->cx;
	if (key != 3)
		to = zoom(f, key, pxl(x, y));
	f->live.offset.real -= to.real - from.real;
	f->live.offset.imag -= to.imag - from.imag;
	if (f->opt >> 5 & 1)
		return (!++f->lock);
	return (fill_win(f));
}

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
