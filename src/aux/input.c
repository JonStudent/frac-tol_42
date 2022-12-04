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
	else if (key == 'r')
		settings(data, NULL);
	else if (key == 'i')
		data->sttgs.opt ^= 1; 
	else if (key == 'l')
		data->sttgs.opt ^= 1 << 1; 
	else if (key == PLUS_K)
		data->sttgs.mx_itr += 10;
	else if (key == MINUS_K && data->sttgs.mx_itr > 10)
		data->sttgs.mx_itr -= 10;
	else if (key == N0_K)
		data->sttgs.clr = 0;
	else if (key == N1_K)
		data->sttgs.clr = 1;
	else if (key == ESC_K)
		exit(0);
	ft_printf("max_iter: %d\n", data->sttgs.mx_itr);
	return (create(data));
}

int	mouse(int key, int x, int y, t_data *data)
{
	data->tmp = set_coords(data, x, y);
	if (key == 4)
		data->sttgs.zoom *= 1.5;
	else if (key == 5 && data->sttgs.zoom > 1)
		data->sttgs.zoom /= 1.5;
	else 
		return (0);
	set_coords(data, x, y);
	data->sttgs.offset.real += data->cx.real - data->tmp.real;
	data->sttgs.offset.imag += data->cx.imag - data->tmp.imag;

	printf("zoom: %ld\n", data->sttgs.zoom / CM);
	return (create(data));
}