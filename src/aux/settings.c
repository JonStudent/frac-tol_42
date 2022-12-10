#include "../fractol.h"

void	win_default(t_sttgs *sttgs)
{
	if (!sttgs->mx_itr)
		sttgs->mx_itr = 80;
	if (!sttgs->offset.real)
		sttgs->offset.real = 0.5;
	if (!sttgs->win_size.x || !sttgs->win_size.y)
		sttgs->win_size = pxl(WIDTH, HEIGHT);
	sttgs->mid_win = pxl(sttgs->win_size.x / 2, sttgs->win_size.y / 2);
	if (!sttgs->zoom)
		sttgs->zoom = PP_CM * (sttgs->win_size.y / 200.0);
}

void	settings(t_data *data)
{
	if (!data->mlx)
		data->mlx = mlx_init();
	win_default(&data->sttgs);
	init_win(data);
}
