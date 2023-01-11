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

#include "../fractol.h"

int	keyboard(int key, t_frtl *f)
{
	if (!(f->opt >> 5 & 1) && f->lock)
		return (0);
	else if (key == RIGHT_K)
		f->live.offset.real += MOVE * f->init.zoom \
		/ f->live.zoom;
	else if (key == LEFT_K)
		f->live.offset.real -= MOVE * f->init.zoom \
		/ f->live.zoom;
	else if (key == UP_K)
		f->live.offset.imag += MOVE * f->init.zoom \
		/ f->live.zoom;
	else if (key == DOWN_K)
		f->live.offset.imag -= MOVE * f->init.zoom \
		/ f->live.zoom;
	else if (key == PLUS_K)
		f->live.itr += 20;
	else if (key == MINUS_K && f->live.itr > 20)
		f->live.itr -= 20;
	else
		return (keyboard_plus(key, f));
	if (f->opt >> 5 & 1)
		return (!++f->lock);
	return (fill_win(f));
}

int	mouse(int key, int x, int y, t_frtl *f)
{
	if (!(f->opt >> 5 & 1) && f->lock)
		return (0);
	coords(f, pxl(x, y));
	if (key == 2)
		stats(f, 0);
	else if (key >= 3 && key <= 5)
		return (move(f, key, pxl(x, y)));
	if (!f->child || key != 1)
		return (0);
	f->live.cx_j = f->cx;
	f->child->live.cx_j = f->cx;
	if (f->opt >> 5 & 1 || !++f->lock)
		if (f->set != julia || ++f->lock)
			return (!++f->child->lock);
	if (f->set == julia)
		fill_win(f);
	return (fill_win(f->child));
}

int	expose(t_frtl *f)
{
	if (f->opt >> 5 & 1)
		return (!++f->lock);
	else if (!f->lock)
		return (fill_win(f));
	return (0);
}

int	dance(int x, int y, t_frtl *f)
{
	return (mouse(1, x, y, f));
}

int	wait(t_frtl *f)
{
	if (f->opt >> 5 & 1 && f->lock)
		fill_win(f);
	if (f->opt >> 5 & 1 && f->child->lock)
		fill_win(f->child);
	f->lock = 0;
	f->child->lock = 0;
	return (0);
}
