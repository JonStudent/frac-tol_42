#include "../fractol.h"

double	mandelbrot(t_data *data, t_cx cx, int itr)
{
	long double	tmp;

	while (pow(data->n.cx.real, 2.0) + pow(data->n.cx.imag, 2.0) < 4 \
	&& ++itr < (int)data->sttgs.live.itr)
	{
		tmp = pow(data->n.cx.real, 2.0) - pow(data->n.cx.imag, 2.0) + cx.real;
		data->n.cx.imag = 2.0 * data->n.cx.real * data->n.cx.imag + cx.imag;
		data->n.cx.real = tmp;
	}
	return (itr);
}
