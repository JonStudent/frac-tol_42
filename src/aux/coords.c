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

//38 pixels in a cm
t_cx	set_coords(t_data *data, int x, int y)
{
	data->cx.real = (x - data->sttgs.mid_win.x) \
	/ (double)data->sttgs.zoom  - data->sttgs.offset.real;
	data->cx.imag = (data->sttgs.mid_win.y - y) \
	/ (double)data->sttgs.zoom  - data->sttgs.offset.imag;
	return (data->cx);
}

int	create(t_data *data)
{
	data->px.y = -1;
	while (++data->px.y < HEIGHT)
	{
		data->px.x = -1;
		while (++data->px.x < WIDTH)
			color(data->set(data, set_coords(data, data->px.x, data->px.y), 0), data);
	}
	mlx_put_image_to_window(data->img.mlx, data->img.win, data->img.img, 0, 0);
	return (0);
}
