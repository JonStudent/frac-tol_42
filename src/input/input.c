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

#include "../fractol.h"

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
	else if (key == 'a' && info(f, key))
		f->opt ^= 1 << 3;
	else if (key == 'o')
		f->opt ^= 1 << 4;
	else if (key == 's')
		f->opt ^= 1 << 5;
	else if (key == 'r')
		default_win(f);
	else if (key == 'j')
		child_win(f);
	else if (key == ESC_K)
		exit_win(f, NULL);
	else
		return (0);
	return (key != 'a' && key != 'j');
}

int	keyboard(int key, t_frtl *f)
{
	if (key == RIGHT_K)
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
		f->live.itr += 10;
	else if (key == MINUS_K && f->live.itr > 10)
		f->live.itr -= 10;
	else if (!keyboard_plus(key, f))
		return (0);
	return (!++f->lock);
}

int	mouse_press(int key, int x, int y, t_frtl *f)
{
	coords(f, pxl(x, y));
	if ((key == 2 && info(f, 0)) || !f->child || key != 1)
		return (0);
	f->live.cx_j = f->cx;
	f->child->live.cx_j = f->cx;
	if (f->set == julia)
		++f->lock;
	return (!++f->child->lock);
}

int	mouse_release(int key, int x, int y, t_frtl *f)
{
	t_cx	from;
	t_cx	to;

	if (key == 1 || key == 2)
		return (0);
	from = f->cx;
	coords(f, pxl(x, y));
	to = f->cx;
	if (key != 3)
		to = zoom(f, key, pxl(x, y));
	f->live.offset.real -= to.real - from.real;
	f->live.offset.imag -= to.imag - from.imag;
	return (!++f->lock);
}
