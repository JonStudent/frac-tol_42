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
	data->n.rl = (data->n.px_x - WIDTH / 2.0) \
	/ data->sttgs.zoom - data->sttgs.x_offset;
	data->n.ig = (HEIGHT / 2.0 - data->n.px_y) \
	/ data->sttgs.zoom - data->sttgs.y_offset;
	return (0);
}

void	pix_iter(t_data *data, \
int (*set)(t_data *data, double i_rl, double i_ig, int itr))
{
	data->n.px_y = -1;
	while (++data->n.px_y < HEIGHT)
	{
		data->n.px_x = -1;
		while (++data->n.px_x < WIDTH)
			color(set(data, data->n.rl, data->n.ig, set_coords(data)), data);
	}
	mlx_put_image_to_window(data->img.mlx, data->img.win, data->img.img, 0, 0);
}
