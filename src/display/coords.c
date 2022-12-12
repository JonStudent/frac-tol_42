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

void	zoom(t_data *frtl, int key, t_px px)
{
	t_cx	tmp;

	tmp = cmplx(frtl->cx.real, frtl->cx.imag);
	if (key == 4)
		frtl->head.zoom *= 2;
	else if (key == 5 && frtl->head.zoom > 1)
		frtl->head.zoom /= 2;
	if (key == 4 && frtl->opt >> 3 & 1)
		frtl->head.itr += frtl->init.itr / 10;
	else if (key == 5 && frtl->opt >> 3 & 1)
		frtl->head.itr -= frtl->init.itr / 10;
	coords(frtl, px);
	frtl->head.offset.real -= frtl->cx.real - tmp.real;
	frtl->head.offset.imag -= frtl->cx.imag - tmp.imag;
}

t_cx	coords(t_data *frtl, t_px px)
{
	frtl->cx = cmplx((px.x - frtl->mid_win.x) \
	/ (long double)frtl->head.zoom + frtl->head.offset.real, \
	(frtl->mid_win.y - px.y) \
	/ (long double)frtl->head.zoom + frtl->head.offset.imag);
	if (frtl->set == julia || !frtl->child)
		return (frtl->cx_j);
	return (frtl->cx);
}

int	px_iter(t_data *frtl)
{
	frtl->px.y = -1;
	while (++frtl->px.y < frtl->win_size.y)
	{
		frtl->px.x = -1;
		while (++frtl->px.x < frtl->win_size.x)
			color(frtl->set(frtl, coords(frtl, frtl->px), 0), frtl);
	}
	mlx_put_image_to_window(frtl->mlx, frtl->win, frtl->img.img, 0, 0);
	if (frtl->child && frtl->child->win)
		px_iter(frtl->child);
	return (0);
}
