#include "../fractol.h"


void	*get_param(t_data *data, int i, int argc, char **argv)
{
	if (argv[i][0] == 'j')
	{
		if (i + 2 < argc)
			data->n.cx_j = cmplx(atod(argv[i + 1]), atod(argv[i + 2]));
		data->set = julia;
	}
	else if (argv[i][0] == 'm')
		data->set = mandelbrot;
	else if (argv[i][0] == 'b')
		data->set = burning_ship;
	else if (argv[i][0] == '-')
	{
		if (argv[i][1] == 'w' && i + 2 < argc)
			data->sttgs.win_size = pxl(atod(argv[i + 1]), atod(argv[i + 2]));
		else if (argv[i][1] == 'i' && i + 1 < argc)
			data->sttgs.init.itr = atod(argv[i + 1]);
		else if (argv[i][1] == 'c' && i + 2 < argc)
			data->sttgs.init.offset = cmplx(-atod(argv[i + 1]), -atod(argv[i + 2]));
	}
	if (++i < argc)
		get_param(data, i, argc, argv);
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
		sttgs->init.zoom = PP_CM * (sttgs->win_size.y / 200.0);
	sttgs->live.zoom = sttgs->init.zoom;
	sttgs->mid_win = pxl(sttgs->win_size.x / 2, sttgs->win_size.y / 2);
	sttgs->live.offset.real = sttgs->init.offset.real * sttgs->init.zoom;
	sttgs->live.offset.imag = sttgs->init.offset.imag * sttgs->init.zoom;
}

void	settings(t_data *data)
{
	if (!data->mlx)
		data->mlx = mlx_init();
	win_default(&data->sttgs);
	init_win(data);
}
