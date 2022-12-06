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

void	new_mlx_win(t_data *data, t_img *img)
{	
	img->img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, \
	&img->bits_per_pixel, &img->line_len, &img->endian);
}

void	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, "Fract-ol");
	new_mlx_win(data, &data->mlx.img);
	mlx_key_hook(data->mlx.win, keyboard, &data);
	mlx_mouse_hook(data->mlx.win, mouse, &data);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.img.addr + \
	(y * data->mlx.img.line_len + x * (data->mlx.img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
