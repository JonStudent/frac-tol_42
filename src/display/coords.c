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

void	zoom(t_data *data, int key, t_px px)
{
	t_cx	tmp;

	tmp = cmplx(data->cx.real, data->cx.imag);
	if (key == 4)
		data->head.zoom *= 2;
	else if (key == 5 && data->head.zoom > 1)
		data->head.zoom /= 2;
	if (key == 4 && data->opt >> 3 & 1)
		data->head.itr += data->init.itr / 10;
	else if (key == 5 && data->opt >> 3 & 1)
		data->head.itr -= data->init.itr / 10;
	coords(data, px);
	data->head.offset.real -= data->cx.real - tmp.real;
	data->head.offset.imag -= data->cx.imag - tmp.imag;
}

t_cx	coords(t_data *data, t_px px)
{
	data->cx = cmplx((px.x - data->mid_win.x) \
	/ (long double)data->head.zoom + data->head.offset.real, \
	(data->mid_win.y - px.y) \
	/ (long double)data->head.zoom + data->head.offset.imag);
	if (data->set == julia)
		return (data->cx_j);
	return (data->cx);
}

int	px_iter(t_data *data)
{
	data->px.y = -1;
	while (++data->px.y < data->win_size.y)
	{
		data->px.x = -1;
		while (++data->px.x < data->win_size.x)
			color(data->set(data, coords(data, data->px), 0), data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	if (data->n_data && data->n_data->win)
		px_iter(data->n_data);
	return (0);
}
