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

void	*get_param(t_frtl *f, int i, int c, char **v)
{
	if (v[i][0] == 'j' || v[i][0] == 'J')
		f->set = julia;
	if ((v[i][0] == 'j' || v[i][0] == 'J') && i + 2 < c)
		f->init.cx_j = cmplx(atod(v[i + 1]), atod(v[i + 2]));
	else if (v[i][0] == 'm' || v[i][0] == 'M')
		f->set = mandelbrot;
	else if (v[i][0] == 'b' || v[i][0] == 'B')
		f->set = burning_ship;
	else if (v[i][0] == '-' && (v[i][1] == 'i' && i + 1 < c))
		f->init.itr = atod(v[i + 1]);
	else if (v[i][0] == '-' && (v[i][1] == 'z' && i + 1 < c))
		f->init.zoom = atod(v[i + 1]) * PP_CM;
	else if (v[i][0] == '-' && (v[i][1] == 'c' && i + 2 < c))
		f->img.hsv = cmplx(atod(v[i + 1]), atod(v[i + 2]));
	else if (v[i][0] == '-' && (v[i][1] == 'w' && i + 2 < c))
		f->img.w_size = pxl(atod(v[i + 1]), atod(v[i + 2]));
	else if (v[i][0] == '-' && (v[i][1] == 'o' && i + 2 < c))
		f->init.offset = cmplx(atod(v[i + 1]), atod(v[i + 2]));
	if (++i < c)
		get_param(f, i, c, v);
	return (f->set);
}

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
		child_win(f);
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
		stats(f, f->live.itr, f->live.zoom / PP_CM);
	if (key == 4 || key == 5)
		return (zoom(f, key, pxl(x, y)));
	if (key == 1 && !f->child)
		return (0);
	f->child->live.cx_j = f->cx;
	f->live.cx_j = f->cx;
	if (f->set == julia)
		return (fill_win(f));
	return (fill_win(f->child));
}
