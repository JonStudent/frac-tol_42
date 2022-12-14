/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:53:48 by jbasilio          #+#    #+#             */
/*   Updated: 2022/12/12 21:53:49 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	mandelbrot(t_frtl *f, t_cx cx, long itr)
{
	long double	tmp;

	while (pow(f->cx.real, 2.0) + pow(f->cx.imag, 2.0) < 4 \
	&& ++itr < f->live.itr)
	{
		tmp = pow(f->cx.real, 2.0) - pow(f->cx.imag, 2.0) + cx.real;
		f->cx.imag = 2.0 * f->cx.real * f->cx.imag + cx.imag;
		f->cx.real = tmp;
	}
	return (itr);
}
