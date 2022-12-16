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
	if (key == 'i')
		f->opt ^= 1 << 0;
	else if (key == 'u')
		f->opt ^= 1 << 1;
	else if (key == 'y')
		f->opt ^= 1 << 2;
	else if (key == 'a')
		f->opt ^= 1 << 3;
	else if (key == 'o')
		f->opt ^= 1 << 4;
	else if (key == 's')
		f->opt ^= 1 << 5;
	else if (key == 'd')
		f->opt ^= 1 << 6;
	else if (key == 'r')
		default_win(f);
	else if (key == 'j')
		return (child_win(f));
	else
		return (0);
	if (f->opt >> 5 & 1)
		return (!++f->locked);
	return (fill_win(f));
}

int	keyboard(int key, t_frtl *f)
{
	if (!(f->opt >> 5 & 1) && f->locked)
		return (0);
	if (key == ESC_K)
		handle_error(f, NULL);
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
	else if (key == N0_K || key == N1_K || key == N2_K)
		f->img.clr = key;
	else
		return (keyboard_plus(key, f));
	if (f->opt >> 5 & 1)
		return (!++f->locked);
	return (fill_win(f));
}

int	mouse(int key, int x, int y, t_frtl *f)
{
	if (!(f->opt >> 5 & 1) && f->locked)
		return (0);
	coords(f, pxl(x, y));
	if (key == 2)
		stats(f);
	else if (key >= 3 && key <= 5)
		return (move(f, key, pxl(x, y)));
	if (!f->child || key != 1)
		return (0);
	f->child->live.cx_j = f->cx;
	f->live.cx_j = f->cx;
	if (f->set == julia)
		fill_win(f);
	if (f->opt >> 5 & 1)
		return (!++f->locked);
	return (fill_win(f->child));
}
int	dance(int x, int y, t_frtl *f)
{
	if (!(f->opt >> 6 & 1) || \
	(!(f->opt >> 5 & 1) && f->locked))
		return (0);
	coords(f, pxl(x, y));
	f->live.cx_j = f->cx;
	if (f->opt >> 5 & 1)
		return (!++f->locked);
	return (fill_win(f));
}

int	wait(t_frtl *f)
{
	if (f->opt >> 5 & 1 && f->locked)
		fill_win(f);
	f->locked = 0;
	return (0);
}
