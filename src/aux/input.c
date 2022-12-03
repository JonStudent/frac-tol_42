#include "../fractol.h"

int	keyboard(int	keycode, t_data *data)
{
	if (keycode == 'd')
		data->sttgs.offset.real -= 34.4 / data->sttgs.zoom;
	if (keycode == 'a')
		data->sttgs.offset.real += 34.4 / data->sttgs.zoom;
	if (keycode == 'w')
		data->sttgs.offset.imag -= 34.4 / data->sttgs.zoom;
	if (keycode == 's')
		data->sttgs.offset.imag += 34.4 / data->sttgs.zoom;
	if (keycode == ESC_K)
		exit(0);
	create(data);
	return (0);
}

int	mouse(int keycode, int x, int y, t_data *data)
{
	data->tmp = set_coords(data, x, y);

	if (keycode == 4)
		data->sttgs.zoom *= 2.0;
	if (keycode == 5 && data->sttgs.zoom > 1)
		data->sttgs.zoom /= 2.0;
		
	set_coords(data, x, y);
	data->sttgs.offset.real += data->cx.real - data->tmp.real;
	data->sttgs.offset.imag += data->cx.imag - data->tmp.imag;

	printf("x_offset = %Lf (real %Lf - old %Lf)\n", data->sttgs.offset.real, data->cx.real, data->tmp.real);
	create(data);
	return (0);
}