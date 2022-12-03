#include "../fractol.h"

int	keyboard(int key, t_data *data)
{
	if (key == 'd')
		data->sttgs.offset.real -= 34.4 / data->sttgs.zoom;
	else if (key == 'a')
		data->sttgs.offset.real += 34.4 / data->sttgs.zoom;
	else if (key == 'w')
		data->sttgs.offset.imag -= 34.4 / data->sttgs.zoom;
	else if (key == 's')
		data->sttgs.offset.imag += 34.4 / data->sttgs.zoom;
	else if (key == PLUS_K)
		data->sttgs.mx_itr += 10;
	else if (key == MINUS_K && data->sttgs.mx_itr > 0)
		data->sttgs.mx_itr -= 10;
	else if (key == 'r')
		settings(data, NULL);
	else if (key == ESC_K)
		exit(0);
	ft_printf("%d\n", key);
	return (create(data));
}

int	mouse(int key, int x, int y, t_data *data)
{
	data->tmp = set_coords(data, x, y);
	if (key == 4)
		data->sttgs.zoom *= 2.0;
	else if (key == 5 && data->sttgs.zoom > 1)
		data->sttgs.zoom /= 2.0;
	else 
		return (0);
	set_coords(data, x, y);
	data->sttgs.offset.real += data->cx.real - data->tmp.real;
	data->sttgs.offset.imag += data->cx.imag - data->tmp.imag;

	printf("x_offset = %Lf (real %Lf - old %Lf)\n", data->sttgs.offset.real, data->cx.real, data->tmp.real);
	return (create(data));
}