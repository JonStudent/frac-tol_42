#include "../fractol.h"

void    settings(t_data *data)
{
    data->sttgs.mx_itr = 120;
	data->sttgs.zoom = CM * (HEIGHT / 200);
	data->sttgs.x_offset = 0.5;
}