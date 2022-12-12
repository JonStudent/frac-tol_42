#include "../fractol.h"

double	mandelbrot(t_data *frtl, t_cx cx, long itr)
{
	long double	tmp;

	while (pow(frtl->cx.real, 2.0) + pow(frtl->cx.imag, 2.0) < 4 \
	&& ++itr < frtl->head.itr)
	{
		tmp = pow(frtl->cx.real, 2.0) - pow(frtl->cx.imag, 2.0) + cx.real;
		frtl->cx.imag = 2.0 * frtl->cx.real * frtl->cx.imag + cx.imag;
		frtl->cx.real = tmp;
	}
	return (itr);
}
