#include "../fractol.h"


void	*get_param(t_data *data, int i, int c, char **v)
{
	if (v[i][0] == 'j')
	{
		if (i + 2 < c)
			data->n.cx_j = cmplx(atod(v[i + 1]), atod(v[i + 2]));
		data->set = julia;
	}
	else if (v[i][0] == 'm')
		data->set = mandelbrot;
	else if (v[i][0] == 'b')
		data->set = burning_ship;
	else if (v[i][0] == '-')
	{
		if (v[i][1] == 'z' && i + 1 < c)
			data->sttgs.init.zoom = atod(v[i + 1]) * PP_CM;
		else if (v[i][1] == 'i' && i + 1 < c)
			data->sttgs.init.itr = atod(v[i + 1]);
		else if (v[i][1] == 'w' && i + 2 < c)
			data->sttgs.win_size = pxl(atod(v[i + 1]), atod(v[i + 2]));
		else if (v[i][1] == 'c' && i + 2 < c)
			data->sttgs.init.offset = cmplx(-atod(v[i + 1]), -atod(v[i + 2]));
	}
	if (++i < c)
		get_param(data, i, c, v);
	return (data->set);
}

void	win_default(t_sttgs *sttgs)
{
	if (!sttgs->init.itr)
		sttgs->init.itr = 80;
	sttgs->live.itr = sttgs->init.itr;
	if (!sttgs->win_size.x || !sttgs->win_size.y)
		sttgs->win_size = pxl(WIDTH, HEIGHT);
	if (!sttgs->init.zoom)
		sttgs->init.zoom = PP_CM;
	sttgs->live.zoom = sttgs->init.zoom;
	sttgs->mid_win = pxl(sttgs->win_size.x / 2, sttgs->win_size.y / 2);
	sttgs->live.offset.real = sttgs->init.offset.real;
	sttgs->live.offset.imag = sttgs->init.offset.imag;
}

void	settings(t_data *data)
{
	if (!data->mlx)
		data->mlx = mlx_init();
	win_default(&data->sttgs);
	init_win(data);
}
