#include "../fractol.h"

static void	palette(t_data *data)
{
	data->sttgs.palette[0] = 0x0000001F;
	data->sttgs.palette[1] = 0x0000003F;
	data->sttgs.palette[2] = 0x00003FFF;
	data->sttgs.palette[3] = 0x00007FFF;
	data->sttgs.palette[4] = 0x0000BFFF;
	data->sttgs.palette[5] = 0x0000FFFF;
	data->sttgs.palette[6] = 0x0000FFBF;
	data->sttgs.palette[7] = 0x0000FF7F;
	data->sttgs.palette[8] = 0x0000FF3F;
	data->sttgs.palette[9] = 0x0000FF00;
	data->sttgs.palette[10] = 0x003FFF00;
	data->sttgs.palette[11] = 0x007FFF00;
	data->sttgs.palette[12] = 0x00BFFF00;
	data->sttgs.palette[13] = 0x00FFFF00;
	data->sttgs.palette[14] = 0x00FF3F00;
	data->sttgs.palette[15] = 0x00FF7F00;
	data->sttgs.palette[16] = 0x00FFBF00;
	data->sttgs.palette[17] = 0x00FF0000;
	data->sttgs.palette[18] = 0x00000000;

}

void    settings(t_data *data, char *set)
{
    data->sttgs.mx_itr = 80;
	data->sttgs.mid_win.x = WIDTH / 2;
	data->sttgs.mid_win.y = HEIGHT / 2;
	data->sttgs.zoom = CM * (HEIGHT / 200); // 86 * 4 = 344
	data->sttgs.offset.real = 0;
	data->sttgs.offset.imag = 0;
	data->cx_j.real = 0;
	data->cx_j.imag = -0.78;
	if (set && (*set == 'm' || *set == 'j'))
		data->set = julia_mandelbrot;
	else if (!set)
		return ;
	data->sttgs.set_flag = *set;
	init_mlx(data);
	palette(data);
}