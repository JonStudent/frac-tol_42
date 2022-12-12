#include "../fractol.h"


void	*get_param(t_data *data, int i, int c, char **v)
{
	if (v[i][0] == 'j' || v[i][0] == 'J')
	{
		if (i + 2 < c)
			data->cx_j = cmplx(atod(v[i + 1]), atod(v[i + 2]));
		data->set = julia;
	}
	else if (v[i][0] == 'm' || v[i][0] == 'M')
		data->set = mandelbrot;
	else if (v[i][0] == 'b' || v[i][0] == 'B')
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
			data->init.hsv = atod(v[i + 1]);
			data->head.hsv = atod(v[i + 2]);
		}
	}
	if (++i < c)
		get_param(data, i, c, v);
	return (data->set);
}

void	default_win(t_data *data)
{
	if (!data->init.itr)
		data->init.itr = 64;
	if (!data->win_size.x || !data->win_size.y)
		data->win_size = pxl(WIDTH, HEIGHT);
	if (!data->init.zoom)
		data->init.zoom = PP_CM * (data->win_size.y / 350.0);
	if (!data->head.hsv)
		data->head.hsv = 359.99;
	data->head.itr = data->init.itr;
	data->head.zoom = data->init.zoom;
	data->head.offset = data->init.offset;
	data->mid_win = pxl(data->win_size.x / 2, data->win_size.y / 2);
}

int	win_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	data->win = 0;
	return (0);
}

t_data *settings(t_data *data, void *mlx, void *set)
{
	data->mlx = mlx;
	data->set = set;
	default_win(data);
	if (data->set == mandelbrot)
		data->title = "Mandelbrot Set";
	else if (data->set == julia)
		data->title = "Julia Set";
	else if (data->set == burning_ship)
		data->title = "Burning_Ship Set";
	init_win(data);
	return (data);
}
