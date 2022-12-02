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
	if (keycode == 'd')
		data->sttgs.x_offset -= 34.4 / data->sttgs.zoom;
	if (keycode == 'a')
		data->sttgs.x_offset += 34.4 / data->sttgs.zoom;
	if (keycode == 'w')
		data->sttgs.y_offset -= 34.4 / data->sttgs.zoom;
	if (keycode == 's')
		data->sttgs.y_offset += 34.4 / data->sttgs.zoom;
	if (keycode == ESC_K)
		exit(0);
	create(data);
	return (0);
}

int	mouse(int keycode, int x, int y, t_data *data)
{

	t_cpx old_pos;

	old_pos = set_coords(data, x, y);
	printf("keycode: %d p(x:%d,y:%d) n(x: %Lf, y:%Lf) zoom: %ld\n", keycode, x, y, data->n.cpx.real, data->n.cpx.imag, data->sttgs.zoom);

	if (keycode == 4)
		data->sttgs.zoom *= 2.0;
	if (keycode == 5 && data->sttgs.zoom > 1)
		data->sttgs.zoom /= 2.0;
		
	set_coords(data, x, y);
	data->sttgs.x_offset += data->n.cpx.real - old_pos.real;
	data->sttgs.y_offset += data->n.cpx.imag - old_pos.imag;

	printf("x_offset = %Lf (real %Lf - old %Lf)\n", data->sttgs.x_offset, data->n.cpx.real, old_pos.real);
	create(data);
	return (0);
}

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc < 2)
		return (0);
	
	data.set = settings(&data, argv[1]);
	create(&data);

	// mlx_hook(data.img.win, 2, 1L<<0, keyboard, &data);
	mlx_key_hook(data.img.win, keyboard, &data);
	mlx_mouse_hook(data.img.win, mouse, &data);

	mlx_loop(data.img.mlx);
}
