/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:52:48 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:50 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

t_cx	zoom(t_frtl *f, int key, t_px px)
{
	if (key == 4)
		f->live.zoom *= 2;
	else if (key == 5 && f->live.zoom > 1)
		f->live.zoom /= 2;
	if (key == 4 && f->opt >> 3 & 1)
		f->live.itr += f->init.itr / 10;
	else if (key == 5 && f->opt >> 3 & 1)
		f->live.itr -= f->init.itr / 10;
	coords(f, px);
	return (f->cx);
}

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

t_cx	coords(t_frtl *f, t_px px)
{
	f->cx = cmplx((px.x - f->w_cntr.x) \
	/ (long double)f->live.zoom + f->live.offset.real, \
	(f->w_cntr.y - px.y) \
	/ (long double)f->live.zoom + f->live.offset.imag);
	if (f->set == julia || !f->child)
		return (f->live.cx_j);
	return (f->cx);
}

int	fill_win(t_frtl *f)
{
	if (!f || !f->win)
		return (0);
	if (!(f->opt >> 5 & 1))
		f->lock++;
	ft_printf("\nRendring %s...", f->title);
	f->px.y = -1;
	while (++f->px.y < f->w_size.y)
	{
		f->px.x = -1;
		while (++f->px.x < f->w_size.x)
			color(f->set(f, coords(f, f->px), 0), f);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	ft_printf(GN" Done\n"RT);
	return (0);
}
