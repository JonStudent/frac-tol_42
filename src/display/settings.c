#include "../fractol.h"


void	*get_param(t_data *data, int i, int c, char **v)
{
	if (v[i][0] == 'j')
	{
		if (i + 2 < c)
			data->cx_j = cmplx(atod(v[i + 1]), atod(v[i + 2]));
		data->set = julia;
	}
	else if (v[i][0] == 'm')
		data->set = mandelbrot;
	else if (v[i][0] == 'b')
		data->set = burning_ship;
	else if (v[i][0] == '-')
	{
		if (v[i][1] == 'z' && i + 1 < c)
			data->init.zoom = atod(v[i + 1]) * PP_CM;
		else if (v[i][1] == 'i' && i + 1 < c)
			data->init.itr = atod(v[i + 1]);
		else if (v[i][1] == 'w' && i + 2 < c)
			data->win_size = pxl(atod(v[i + 1]), atod(v[i + 2]));
		else if (v[i][1] == 'o' && i + 2 < c)
			data->init.offset = cmplx(atod(v[i + 1]), atod(v[i + 2]));
		else if (v[i][1] == 'c' && i + 2 < c)
		{
			data->clr.bgn = atod(v[i + 1]);
			data->clr.end = atod(v[i + 2]);
		}
	}
	if (++i < c)
		get_param(data, i, c, v);
	return (data->set);
}

void	win_default(t_data *data)
{
	if (!data->init.itr)
		data->init.itr = 64;
	if (!data->win_size.x || !data->win_size.y)
		data->win_size = pxl(WIDTH, HEIGHT);
	if (!data->init.zoom)
		data->init.zoom = PP_CM * (data->win_size.y / 350.0);
	if (!data->clr.end)
		data->clr.end = 359.99;
	data->live.itr = data->init.itr;
	data->live.zoom = data->init.zoom;
	data->live.offset = data->init.offset;
	data->mid_win = pxl(data->win_size.x / 2, data->win_size.y / 2);
}

void	settings(t_data *data)
{
	if (!data->mlx)
		data->mlx = mlx_init();
	win_default(data);
	init_win(data);
}
