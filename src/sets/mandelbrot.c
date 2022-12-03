/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:53:30 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:53:32 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_data *data, t_cx cx, int itr)
{
	if (pow(data->cx.real, 2.0) + pow(data->cx.imag, 2.0) >= 4 \
	|| ++itr == data->sttgs.mx_itr)
		return (itr);
	data->cx.tmp = data->cx.real;
	data->cx.real = pow(data->cx.real, 2.0) - pow(data->cx.imag, 2.0) + cx.real;
	data->cx.imag = 2.0 * data->cx.tmp * data->cx.imag + cx.imag;
	return (mandelbrot(data, cx, itr));
}	

int	circle(t_data *data, t_cx cx, int itr)
{
	(void)cx.imag;
	(void)cx.real;
	if (pow(data->cx.real, 2.0) + pow(data->cx.imag, 2.0) <= 4)
		itr = data->sttgs.mx_itr - 1;
	return (itr);
}
