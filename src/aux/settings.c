#include "../fractol.h"

void	palette(t_data *data)
{
	data->sttgs.palette[0] = 0x0000003F;
	data->sttgs.palette[1] = 0x00007FFF;
	data->sttgs.palette[2] = 0x0000FFFF;
	data->sttgs.palette[3] = 0x0000FF7F;
	data->sttgs.palette[4] = 0x0000FF00;
	data->sttgs.palette[5] = 0x007FFF00;
	data->sttgs.palette[6] = 0x00FFFF00;
	data->sttgs.palette[7] = 0x00FF7F00;
	data->sttgs.palette[8] = 0x00FF0000;
	data->sttgs.palette[9] = 0x00000000;

}

void    settings(t_data *data, char *set)
{
    data->sttgs.mx_itr = 80;
	data->sttgs.mid_win.x = WIDTH / 2;
	data->sttgs.mid_win.y = HEIGHT / 2;
	data->sttgs.zoom = CM * (HEIGHT / 200); // 86 * 4 = 344
	data->sttgs.offset.real = 0;
	data->sttgs.offset.imag = 0;
	data->i_cx.real = 0;
	data->i_cx.imag = -0.78;
	if (set && *set == 'm')
		data->set = mandelbrot;
	else if (set && *set == 'j')
		data->set = julia;
	else if (set)
		return ;
	if (!data->img.win)
	{
		init_mlx(data);
		palette(data);
	}
}