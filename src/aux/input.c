#include "../fractol.h"

static void	zoom(t_data *data, int key, int x, int y)
{
	data->tmp.real = data->cx.real;
	data->tmp.imag = data->cx.imag;
	if (key == 4)
		data->sttgs.zoom *= 2;
	else if (key == 5 && data->sttgs.zoom > 1)
		data->sttgs.zoom /= 2;
	coords(data, x, y);
	data->sttgs.offset.real += data->cx.real - data->tmp.real;
	data->sttgs.offset.imag += data->cx.imag - data->tmp.imag;
}

static int	keyboard_plus(int key, t_data *data)
{
	if (key == PLUS_K)
		data->sttgs.mx_itr += 5;
	else if (key == MINUS_K && data->sttgs.mx_itr > 5)
		data->sttgs.mx_itr -= 5;
	else if (key == N0_K)
		data->sttgs.pltt = 0;
	else if (key == N1_K)
		data->sttgs.pltt = 1;
	else if (key == N2_K)
		data->sttgs.pltt = 2;
	else if (key == 'i')
		data->sttgs.opt ^= 1 << 7;
	else if (key == 'l')
	{
		data->sttgs.ini_mx_itr = data->sttgs.mx_itr;
		data->sttgs.opt ^= 1 << 8;
	}
	ft_printf("max_iter: %d, key: %d\n", data->sttgs.mx_itr, key);
	return (px_iter(data));
}

int	keyboard(int key, t_data *data)
{
	if (key == ESC_K)
		exit(0);
	else if (key == 'd' || key == RIGHT_K)
		data->sttgs.offset.real -= 34.4 / data->sttgs.zoom;
	else if (key == 'a' || key == LEFT_K)
		data->sttgs.offset.real += 34.4 / data->sttgs.zoom;
	else if (key == 'w' || key == UP_K)
		data->sttgs.offset.imag -= 34.4 / data->sttgs.zoom;
	else if (key == 's' || key == DOWN_K)
		data->sttgs.offset.imag += 34.4 / data->sttgs.zoom;
	else if (key == 'r')
		settings(data, NULL);
	else
		return (keyboard_plus(key, data));
	return (px_iter(data));
}

int	mouse(int key, int x, int y, t_data *data)
{
	coords(data, x, y);
	if (key == 4 || key == 5)
		zoom(data, key, x, y);
	else if (key == 1)
		data->i_cx = data->cx;
	printf("zoom: %ld\n", data->sttgs.zoom / CM);
	return (px_iter(data));
}
