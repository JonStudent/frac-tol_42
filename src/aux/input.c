#include "../fractol.h"

static int	keyboard_plus(int key, t_data *data)
{
	if (key == 'i')
		data->opt ^= 1;
	else if (key == 'p')
		data->opt ^= 1 << 1;
	else if (key == 's')
		data->opt ^= 1 << 2;
	else if (key == 'a')
		data->opt ^= 1 << 3; 
	else if (key == 'r')
		default_win(data);
	else if (key == 'j' && data->n_data && !data->n_data->win)
		settings(data->n_data, data->mlx, data->set);
	else if (key == 'j' && data->n_data)
		win_close(data->n_data);
	else if (key == 'j')
		return (win_close(data));
	else
		return (0);
	return (px_iter(data));
}

int	keyboard(int key, t_data *data)
{
	if (key == ESC_K)
		exit(0);
	else if (key == RIGHT_K)
		data->head.offset.real += OFFSET * data->init.zoom \
		/ data->head.zoom;
	else if (key == LEFT_K)
		data->head.offset.real -= OFFSET * data->init.zoom \
		/ data->head.zoom;
	else if (key == UP_K)
		data->head.offset.imag += OFFSET * data->init.zoom \
		/ data->head.zoom;
	else if (key == DOWN_K)
		data->head.offset.imag -= OFFSET * data->init.zoom \
		/ data->head.zoom;
	else if (key == PLUS_K)
		data->head.itr += 20;
	else if (key == MINUS_K && data->head.itr > 20)
		data->head.itr -= 20;
	else if (key == N0_K || key == N1_K || key == N2_K)
		data->clr = key;
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
		data->cx_j = data->cx;
	if (key == 1 && data->n_data)
		data->n_data->cx_j = data->cx;
	printf("coords: [%Lf %Lf]	zoom: %ld iter: %ld\n", data->cx.real, data->cx.imag, data->head.zoom / PP_CM, data->head.itr);
	return (px_iter(data));
}
