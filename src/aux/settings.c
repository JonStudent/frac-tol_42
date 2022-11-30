#include "../fractol.h"

void    settings(t_data *data)
{
    data->sttgs.mx_itr = 60;
	data->sttgs.x_cntr = WIDTH / 2.0;
	data->sttgs.y_cntr = HEIGHT / 2.0;
	data->sttgs.zoom = CM * (HEIGHT / 200); // 86 * 4 = 344
	data->sttgs.x_offset = 0.5;
}