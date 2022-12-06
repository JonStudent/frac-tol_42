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

void	init_mlx(t_data *data)
{
	data->img.mlx = mlx_init();
	data->img.win = mlx_new_window(data->img.mlx, WIDTH, HEIGHT, "Fract-ol");
	data->img.img = mlx_new_image(data->img.mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, \
	&data->img.line_len, &data->img.endian);

	mlx_key_hook(data->img.win, keyboard, &data);
	mlx_mouse_hook(data->img.win, mouse, &data);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + \
	(y * data->img.line_len + x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
