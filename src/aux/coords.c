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

	tmp = cmplx(data->n.cx.real, data->n.cx.imag);
	if (key == 4)
		data->sttgs.zoom *= 2;
	else if (key == 5 && data->sttgs.zoom > 1)
		data->sttgs.zoom /= 2;
	coords(data, px);
	data->sttgs.offset.real += data->n.cx.real - tmp.real;
	data->sttgs.offset.imag += data->n.cx.imag - tmp.imag;
}

t_cx	coords(t_data *data, t_px px)
{
	data->n.cx = cmplx((px.x - data->sttgs.mid_win.x) 
	/ (double)data->sttgs.zoom - data->sttgs.offset.real, \
	(data->sttgs.mid_win.y - px.y) \
	/ (double)data->sttgs.zoom - data->sttgs.offset.imag);
	if (data->set == julia)
		return (data->n.cx_j);
	return (data->n.cx);
}

int	px_iter(t_data *data)
{
	data->n.px.y = -1;
	while (++data->n.px.y < data->sttgs.win_size.y)
	{
		data->n.px.x = -1;
		while (++data->n.px.x < data->sttgs.win_size.x)
			color(data->set(data, coords(data, data->n.px), 0), data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
