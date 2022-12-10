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
		if (argv[i][1] == 'w')
			data->sttgs.win_size = pxl(atod(argv[i + 1]), atod(argv[i + 2]));
		else if (argv[i][1] == 'i')
			data->sttgs.init_mx_itr = atod(argv[i + 1]);
	}
	if (++i < argc)
		get_param(data, i, argc, argv);
	return (data->set);
}

void	win_default(t_sttgs *sttgs, char force)
{
	if (!sttgs->init_mx_itr)
		sttgs->init_mx_itr = 80;
	sttgs->mx_itr = sttgs->init_mx_itr;
	if (force || !sttgs->offset.real)
		sttgs->offset.real = 0.5;
	if (!sttgs->win_size.x || !sttgs->win_size.y)
		sttgs->win_size = pxl(WIDTH, HEIGHT);
	sttgs->mid_win = pxl(sttgs->win_size.x / 2, sttgs->win_size.y / 2);
	if (force || !sttgs->zoom)
		sttgs->zoom = PP_CM * (sttgs->win_size.y / 200.0);
}

void	settings(t_data *data)
{
	if (!data->mlx)
		data->mlx = mlx_init();
	win_default(&data->sttgs, 0);
	init_win(data);
}
