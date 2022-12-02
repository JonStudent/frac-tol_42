#include "../fractol.h"

void    *settings(t_data *data, char *set)
{
	data->img.mlx = mlx_init();
	data->img.win = mlx_new_window(data->img.mlx, WIDTH, HEIGHT, "Mandelbrot");
	
	data->img.img = mlx_new_image(data->img.mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, \
	&data->img.line_len, &data->img.endian);

    data->sttgs.mx_itr = 60;
	data->sttgs.x_cntr = WIDTH / 2;
	data->sttgs.y_cntr = HEIGHT / 2;
	data->sttgs.zoom = CM * (HEIGHT / 200); // 86 * 4 = 344
	if (*set == 'm')
	{	
		data->sttgs.x_offset = 0;
		return (mandelbrot);
	}
	return (NULL);
}