#include "../fractol.h"

double	mandelbrot(t_data *data, t_cx cx, long itr)
{
	long double	tmp;

	while (pow(data->cx.real, 2.0) + pow(data->cx.imag, 2.0) < 4 \
	&& ++itr < data->head.itr)
	{
		tmp = pow(data->cx.real, 2.0) - pow(data->cx.imag, 2.0) + cx.real;
		data->cx.imag = 2.0 * data->cx.real * data->cx.imag + cx.imag;
		data->cx.real = tmp;
	}
	return (itr);
}
