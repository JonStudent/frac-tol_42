/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:52:58 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:59 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, t_px px, int color)
{
	char	*dst;

	dst = data->img.addr + \
	(px.y * data->img.line_len + px.x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_win(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->sttgs.win_size.x, \
	data->sttgs.win_size.y, "Fract-ol");
	data->img.img = mlx_new_image(data->mlx, data->sttgs.win_size.x, \
	data->sttgs.win_size.y);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
	mlx_key_hook(data->win, keyboard, data);
	mlx_mouse_hook(data->win, mouse, data);
}
