#include "../fractol.h"

void    settings(t_data *data, char *set)
{
	if (set && *set == 'm')
		data->set = mandelbrot;
	else if (set && *set == 'c')
		data->set = circle;
	else if (set)
		return ;
	data->sttgs.clr = 0x00FFFFFF;
    data->sttgs.mx_itr = 80;
	data->sttgs.mid_win.x = WIDTH / 2;
	data->sttgs.mid_win.y = HEIGHT / 2;
	data->sttgs.zoom = CM * (HEIGHT / 200); // 86 * 4 = 344
	data->sttgs.offset.real = 0;
	data->sttgs.offset.imag = 0;
	if (!data->img.win)
		init_mlx(data);
}