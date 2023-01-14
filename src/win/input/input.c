/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:11:24 by jbasilio          #+#    #+#             */
/*   Updated: 2023/01/14 03:11:27 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

int	keyboard_plus(int key, t_frtl *f)
{
	if (key == N0_K || key == N1_K || key == N2_K)
		f->img.clr = key;
	else if (key == 'i')
		f->opt ^= 1 << 0;
	else if (key == 'u')
		f->opt ^= 1 << 1;
	else if (key == 'y')
		f->opt ^= 1 << 2;
	else if (key == 'a' && stats(f, key))
		f->opt ^= 1 << 3;
	else if (key == 'o')
		f->opt ^= 1 << 4;
	else if (key == 's' && stats(f, key))
		f->opt ^= 1 << 5;
	else if (key == 'r')
		default_win(f);
	else if (key == 'j')
		child_win(f);
	else if (key == ESC_K)
		exit_win(f, NULL);
	return (key != 'a' && key != 's' && key != 'j');
}

int	keyboard(int key, t_frtl *f)
{
	if (f->opt >> 5 ^ 1 && f->lock)
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
	else if (!keyboard_plus(key, f))
		return (0);
	if (f->opt >> 5 & 1)
		return (!++f->lock);
	return (fill_win(f));
}

int	mouse(int key, int x, int y, t_frtl *f)
{
	if (f->opt >> 5 ^ 1 && f->lock)
		return (0);
	coords(f, pxl(x, y));
	if (key == 2)
		stats(f, 0);
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
