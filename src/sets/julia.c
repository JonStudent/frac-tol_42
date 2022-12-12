#include "../fractol.h"

double	julia(t_data *data, t_cx cx, int itr)
{
	long double	tmp;

	if (pow(data->cx.real, 2.0) + pow(data->cx.imag, 2.0) >= 4 \
	|| ++itr == data->live.itr)
		return (itr);
	tmp = pow(data->cx.real, 2.0) - pow(data->cx.imag, 2.0) + cx.real;
	data->cx.imag = 2.0 * data->cx.real * data->cx.imag + cx.imag;
	data->cx.real = tmp;
	return (julia(data, cx, itr));
}
