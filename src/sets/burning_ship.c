#include "../fractol.h"

double	burning_ship(t_data *frtl, t_cx cx, long itr)
{
	long double	tmp;

	if (pow(frtl->cx.real, 2.0) + pow(frtl->cx.imag, 2.0) >= 4 \
	|| ++itr == frtl->head.itr)
		return (itr);
	tmp = pow(frtl->cx.real, 2.0) - pow(frtl->cx.imag, 2.0) + cx.real;
	frtl->cx.imag = -2.0 * ldabs(frtl->cx.real * frtl->cx.imag) + cx.imag;
	frtl->cx.real = tmp;
	return (burning_ship(frtl, cx, itr));
}