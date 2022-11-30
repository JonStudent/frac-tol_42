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
int	set_coords(t_data *data)
{
	data->n.real = (data->n.px_x - data->sttgs.x_cntr) \
	/ data->sttgs.zoom - data->sttgs.x_offset;
	data->n.imag = (data->sttgs.y_cntr - data->n.px_y) \
	/ data->sttgs.zoom - data->sttgs.y_offset;
	return (0);
}

void	create(t_data *data, \
int (*set)(t_data *data, double i_real, double i_imag, int itr))
{
	data->n.px_y = -1;
	while (++data->n.px_y < HEIGHT)
	{
		data->n.px_x = -1;
		while (++data->n.px_x < WIDTH)
			color(set(data, data->n.real, data->n.imag, set_coords(data)), data);
	}
	mlx_put_image_to_window(data->img.mlx, data->img.win, data->img.img, 0, 0);
}
