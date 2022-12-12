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

double	mandelbrot(t_frtl *frtl, t_cx cx, long itr)
{
	long double	tmp;

	while (pow(frtl->cx.real, 2.0) + pow(frtl->cx.imag, 2.0) < 4 \
	&& ++itr < frtl->curr.itr)
	{
		tmp = pow(frtl->cx.real, 2.0) - pow(frtl->cx.imag, 2.0) + cx.real;
		frtl->cx.imag = 2.0 * frtl->cx.real * frtl->cx.imag + cx.imag;
		frtl->cx.real = tmp;
	}
	return (itr);
}
