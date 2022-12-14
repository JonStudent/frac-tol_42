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

void	*get_param(t_frtl *frtl, int i, int c, char **v)
{
	if (v[i][0] == 'j' || v[i][0] == 'J')
		frtl->set = julia;
	if ((v[i][0] == 'j' || v[i][0] == 'J') && i + 2 < c)
		frtl->init.cx_j = cmplx(atod(v[i + 1]), atod(v[i + 2]));
	else if (v[i][0] == 'm' || v[i][0] == 'M')
		frtl->set = mandelbrot;
	else if (v[i][0] == 'b' || v[i][0] == 'B')
		frtl->set = burning_ship;
	else if (v[i][0] == '-' && (v[i][1] == 'i' && i + 1 < c))
		frtl->init.itr = atod(v[i + 1]);
	else if (v[i][0] == '-' && (v[i][1] == 'z' && i + 1 < c))
		frtl->init.zoom = atod(v[i + 1]) * PP_CM;
	else if (v[i][0] == '-' && (v[i][1] == 'c' && i + 2 < c))
		frtl->img.hsv = cmplx(atod(v[i + 1]), atod(v[i + 2]));
	else if (v[i][0] == '-' && (v[i][1] == 'w' && i + 2 < c))
		frtl->img.win_size = pxl(atod(v[i + 1]), atod(v[i + 2]));
	else if (v[i][0] == '-' && (v[i][1] == 'o' && i + 2 < c))
		frtl->init.offset = cmplx(atod(v[i + 1]), atod(v[i + 2]));
	if (++i < c)
		get_param(frtl, i, c, v);
	return (frtl->set);
}

static int	keyboard_plus(int key, t_frtl *frtl)
{
	if (key == '*')
		frtl->img.opt ^= 1;
	else if (key == 'p')
		frtl->img.opt ^= 1 << 1;
	else if (key == 's')
		frtl->img.opt ^= 1 << 2;
	else if (key == 'a')
		frtl->img.opt ^= 1 << 3;
	else if (key == 'i')
		frtl->img.opt ^= 1 << 4;
	else if (key == 'r')
		default_win(frtl);
	else if (key == 'j')
		child_win(frtl);
	else
		return (0);
	return (px_iter(frtl));
}

int	keyboard(int key, t_frtl *frtl)
{
	if (key == ESC_K)
		handle_error(frtl, NULL);
	else if (key == RIGHT_K)
		frtl->curr.offset.real += OFFSET * frtl->init.zoom \
		/ frtl->curr.zoom;
	else if (key == LEFT_K)
		frtl->curr.offset.real -= OFFSET * frtl->init.zoom \
		/ frtl->curr.zoom;
	else if (key == UP_K)
		frtl->curr.offset.imag += OFFSET * frtl->init.zoom \
		/ frtl->curr.zoom;
	else if (key == DOWN_K)
		frtl->curr.offset.imag -= OFFSET * frtl->init.zoom \
		/ frtl->curr.zoom;
	else if (key == PLUS_K)
		frtl->curr.itr += 20;
	else if (key == MINUS_K && frtl->curr.itr > 20)
		frtl->curr.itr -= 20;
	else if (key == N0_K || key == N1_K || key == N2_K)
		frtl->img.clr = key;
	else
		return (keyboard_plus(key, frtl));
	return (px_iter(frtl));
}

int	mouse(int key, int x, int y, t_frtl *frtl)
{
	coords(frtl, pxl(x, y));
	if (key == 4 || key == 5)
		zoom(frtl, key, pxl(x, y));
	else if (key == 1 && frtl->set == julia)
		frtl->curr.cx_j = frtl->cx;
	else if (key == 1 && frtl->child)
		frtl->child->curr.cx_j = frtl->cx;
	if (key == 1 && frtl->img.opt >> 4 & 1)
		stats(frtl, (int)(frtl->curr.zoom / PP_CM), frtl->curr.itr);
	return (px_iter(frtl));
}
	// printf("%.9Lf %.9Lf\n", frtl->cx.real, frtl->cx.imag);
