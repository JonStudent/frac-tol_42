#include "../fractol.h"

double	burning_ship(t_data *data, t_cx cx, int itr)
{
	long double	tmp;

	if (pow(data->cx.real, 2.0) + pow(data->cx.imag, 2.0) >= 4 \
	|| ++itr == data->sttgs.mx_itr)
		return (itr);
	tmp = pow(data->cx.real, 2.0) - pow(data->cx.imag, 2.0) + cx.real;
	data->cx.imag = -2.0 * fabs(data->cx.real * data->cx.imag) + cx.imag;
	data->cx.real = tmp;
	return (burning_ship(data, cx, itr));
}