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

static int	keyboard_plus(int key, t_frtl *f)
{
	if (key == N0_K || key == N1_K || key == N2_K)
		f->img.clr = key;
	else if (key == 'i')
		f->opt ^= 1 << 0;
	else if (key == 'u')
		f->opt ^= 1 << 1;
	else if (key == 'y')
		f->opt ^= 1 << 2;
	else if (key == 'a')
		f->opt ^= 1 << 3;
	else if (key == 'o')
		f->opt ^= 1 << 4;
	else if (key == 's' && stats(f, 's'))
		f->opt ^= 1 << 5;
	else if (key == 'r')
		default_win(f);
	else if (key == 'j')
		return (child_win(f));
	else if (key == ESC_K)
		handle_error(f, NULL);
	else
		return (0);
	if (f->opt >> 5 & 1)
		return (!++f->lock);
	return (fill_win(f));
}

int	keyboard(int key, t_frtl *f)
{
	if (!(f->opt >> 5 & 1) && f->lock)
		return (0);
	else if (key == RIGHT_K)
		f->live.offset.real += OFFSET * f->init.zoom \
		/ f->live.zoom;
	else if (key == LEFT_K)
		f->live.offset.real -= OFFSET * f->init.zoom \
		/ f->live.zoom;
	else if (key == UP_K)
		f->live.offset.imag += OFFSET * f->init.zoom \
		/ f->live.zoom;
	else if (key == DOWN_K)
		f->live.offset.imag -= OFFSET * f->init.zoom \
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

int	dance(int x, int y, t_frtl *f)
{
	return (mouse(1, x, y, f));
}

int	wait(t_frtl *f)
{
	if ((f->opt >> 5 & 1) && f->lock)
		fill_win(f);
	f->lock = 0;
	if ((f->opt >> 5 & 1) && f->child->lock)
		fill_win(f->child);
	f->child->lock = 0;
	return (0);
}
