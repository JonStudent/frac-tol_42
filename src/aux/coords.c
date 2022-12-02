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
t_cpx	set_coords(t_data *data, int x, int y)
{
	data->n.cpx.real = (x - data->sttgs.x_cntr) \
	/ (double)data->sttgs.zoom  - data->sttgs.x_offset;
	data->n.cpx.imag = (data->sttgs.y_cntr - y) \
	/ (double)data->sttgs.zoom  - data->sttgs.y_offset;
	return (data->n.cpx);
}

void	create(t_data *data)
{
	data->n.px_y = -1;
	while (++data->n.px_y < HEIGHT)
	{
		data->n.px_x = -1;
		while (++data->n.px_x < WIDTH)
			color(data->set(data, set_coords(data, data->n.px_x, data->n.px_y), 0), data);
	}
	mlx_put_image_to_window(data->img.mlx, data->img.win, data->img.img, 0, 0);
}
