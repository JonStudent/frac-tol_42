/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:53:30 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:53:32 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	julia_mandelbrot(t_data *data, t_cx cx, int itr)
{
	if (pow(data->cx.real, 2.0) + pow(data->cx.imag, 2.0) >= 4 \
	|| ++itr == data->sttgs.mx_itr)
		return (itr);
	data->cx.tmp = pow(data->cx.real, 2.0) - pow(data->cx.imag, 2.0) + cx.real;
	data->cx.imag = 2.0 * data->cx.real * data->cx.imag + cx.imag;
	data->cx.real = data->cx.tmp;
	return (julia_mandelbrot(data, cx, itr));
}	

double	circle(t_data *data, t_cx cx, int itr)
{
	(void)cx.imag;
	(void)cx.real;
	if (pow(data->cx.real, 2.0) + pow(data->cx.imag, 2.0) <= 4)
		itr = data->sttgs.mx_itr - 1;
	return (itr);
}
