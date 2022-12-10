#include "../fractol.h"

static int	keyboard_plus(int key, t_data *data)
{
	if (key == PLUS_K)
		data->sttgs.live.itr += 5;
	else if (key == MINUS_K && data->sttgs.live.itr > 5)
		data->sttgs.live.itr -= 5;
	else if (key == N0_K)
		data->sttgs.opt |= (char)0;
	else if (key == N1_K)
		data->sttgs.opt |= (char)1;
	else if (key == N2_K)
		data->sttgs.opt |= (char)2;
	else if (key == 'i')
		data->sttgs.opt ^= 1 << 8;
	else if (key == 'p')
		data->sttgs.opt ^= 1 << 9;
	else if (key == 's')
		data->sttgs.opt ^= 1 << 10;
	else
		return (0);
	ft_printf("max_iter: %d, key: %d\n", data->sttgs.live.itr, key);
	return (px_iter(data));
}

int	keyboard(int key, t_data *data)
{
	if (key == ESC_K)
		exit(0);
	else if (key == RIGHT_K)
		data->sttgs.live.offset.real -= OFFSET * data->sttgs.init.zoom \
		/ data->sttgs.live.zoom;
	else if (key == LEFT_K)
		data->sttgs.live.offset.real += OFFSET * data->sttgs.init.zoom \
		/ data->sttgs.live.zoom;
	else if (key == UP_K)
		data->sttgs.live.offset.imag -= OFFSET * data->sttgs.init.zoom \
		/ data->sttgs.live.zoom;
	else if (key == DOWN_K)
		data->sttgs.live.offset.imag += OFFSET * data->sttgs.init.zoom \
		/ data->sttgs.live.zoom;
	else if (key == 'r')
		win_default(&data->sttgs);
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
	printf("zoom: %ld\n", data->sttgs.live.zoom / PP_CM);
	return (px_iter(data));
}
