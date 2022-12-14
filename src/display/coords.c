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

#include "../fractol.h"

void	zoom(t_frtl *frtl, int key, t_px px)
{
	t_cx	tmp;

	tmp = cmplx(frtl->cx.real, frtl->cx.imag);
	if (key == 4)
		frtl->curr.zoom *= 2;
	else if (key == 5 && frtl->curr.zoom > 1)
		frtl->curr.zoom /= 2;
	if (key == 4 && frtl->img.opt >> 3 & 1)
		frtl->curr.itr += frtl->init.itr / 10;
	else if (key == 5 && frtl->img.opt >> 3 & 1)
		frtl->curr.itr -= frtl->init.itr / 10;
	coords(frtl, px);
	frtl->curr.offset.real -= frtl->cx.real - tmp.real;
	frtl->curr.offset.imag -= frtl->cx.imag - tmp.imag;
}

t_cx	coords(t_frtl *frtl, t_px px)
{
	frtl->cx = cmplx((px.x - frtl->img.mid_win.x) \
	/ (long double)frtl->curr.zoom + frtl->curr.offset.real, \
	(frtl->img.mid_win.y - px.y) \
	/ (long double)frtl->curr.zoom + frtl->curr.offset.imag);
	if (frtl->set == julia || !frtl->child)
		return (frtl->curr.cx_j);
	return (frtl->cx);
}

int	px_iter(t_frtl *frtl)
{
	if (!frtl || !frtl->win)
		return (0);
	frtl->px.y = -1;
	while (++frtl->px.y < frtl->img.win_size.y)
	{
		frtl->px.x = -1;
		while (++frtl->px.x < frtl->img.win_size.x)
			color(frtl->set(frtl, coords(frtl, frtl->px), 0), frtl);
	}
	mlx_put_image_to_window(frtl->mlx, frtl->win, frtl->img.img, 0, 0);
	return (px_iter(frtl->child));
}
