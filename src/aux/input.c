#include "../fractol.h"

static int	keyboard_plus(int key, t_data *data)
{
	if (key == PLUS_K)
		data->sttgs.mx_itr += 5;
	else if (key == MINUS_K && data->sttgs.mx_itr > 5)
		data->sttgs.mx_itr -= 5;
	else if (key == N0_K)
		data->sttgs.opt |= (char)0;
	else if (key == N1_K)
		data->sttgs.opt |= (char)1;
	else if (key == N2_K)
		data->sttgs.opt |= (char)2;
	else if (key == 'i')
		data->sttgs.opt ^= 1 << 8;
	else
		return (0);
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
		win_default(&data->sttgs, 1);
	else
		return (keyboard_plus(key, data));
	return (px_iter(data));
}

int	mouse(int key, int x, int y, t_data *data)
{
	coords(data, pxl(x, y));
	if (key == 4 || key == 5)
		zoom(data, key, pxl(x, y));
	else if (key == 1)
		data->n.cx_j = data->n.cx;
	printf("zoom: %ld\n", data->sttgs.zoom / PP_CM);
	return (px_iter(data));
}
