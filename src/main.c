/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:52:25 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:27 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyboard(int	keycode, t_data *data)
{
	printf("keyboard: %d %d\n", keycode, 'd');
	if (keycode == 'd')
		data->sttgs.x_offset -= 34.4 / data->sttgs.zoom;
	if (keycode == 'a')
		data->sttgs.x_offset += 34.4 / data->sttgs.zoom;
	if (keycode == 'w')
		data->sttgs.y_offset -= 34.4 / data->sttgs.zoom;
	if (keycode == 's')
		data->sttgs.y_offset += 34.4 / data->sttgs.zoom;
	if (keycode == 65307)
		exit(0);
	pix_iter(data, mandelbrot);
	return (0);
}

int	mouse(int keycode, int x, int y, t_data *data)
{
	printf("keycode: %d (x:%d,y:%d)\n", keycode, x, y);
	if (keycode == 4)
		data->sttgs.zoom *= 2.0;
	if (keycode == 5)
		data->sttgs.zoom /= 2.0;
	pix_iter(data, mandelbrot);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.img.mlx = mlx_init();
	data.img.win = mlx_new_window(data.img.mlx, WIDTH, HEIGHT, "Mandelbrot");
	data.img.img = mlx_new_image(data.img.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, \
	&data.img.line_len, &data.img.endian);

	data.sttgs.mx_itr = 120;
	data.sttgs.zoom = CM * (HEIGHT / 200);
	data.sttgs.x_offset = 0.5;

	// pix_iter(&data, circle);
	pix_iter(&data, mandelbrot);

	// mlx_key_hook(data.img.win, keyboard, &data);
	mlx_hook(data.img.win, 2, 1L<<0, keyboard, &data);

	mlx_mouse_hook(data.img.win, mouse, &data);

	mlx_loop(data.img.mlx);
}
