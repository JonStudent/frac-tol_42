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
		f->img.opt ^= 1;
	else if (key == 'p')
		f->img.opt ^= 1 << 1;
	else if (key == 's')
		f->img.opt ^= 1 << 2;
	else if (key == 'a')
		f->img.opt ^= 1 << 3;
	else if (key == 'c')
		f->img.opt ^= 1 << 4;
	else if (key == 'r')
		default_win(f);
	else if (key == 'j')
		return (child_win(f));
	else
		return (0);
	return (fill_win(f));
}

int	keyboard(int key, t_frtl *f)
{
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
	return (fill_win(f));
}

int	mouse(int key, int x, int y, t_frtl *f)
{
	coords(f, pxl(x, y));
	if (key == 1 && f->img.opt >> 4 & 1)
		stats(f);
	if (key == 4 || key == 5)
		return (zoom(f, key, pxl(x, y)));
	if (key == 3)
		move(f);
	if (!f->child || key != 1)
		return (fill_win(f));
	f->child->live.cx_j = f->cx;
	f->live.cx_j = f->cx;
	if (f->set == julia)
		fill_win(f);
	return (fill_win(f->child));
}
