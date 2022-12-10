#include "../fractol.h"

long double	julia(t_data *data, t_cx cx, int itr)
{
	long double	tmp;

	if (pow(data->n.cx.real, 2.0) + pow(data->n.cx.imag, 2.0) >= 4 \
	|| ++itr == data->sttgs.live.itr)
		return (itr);
	tmp = pow(data->n.cx.real, 2.0) - pow(data->n.cx.imag, 2.0) + cx.real;
	data->n.cx.imag = 2.0 * data->n.cx.real * data->n.cx.imag + cx.imag;
	data->n.cx.real = tmp;
	return (julia(data, cx, itr));
}
