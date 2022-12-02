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

int	mandelbrot(t_data *data, t_cpx cpx, int itr)
{
	if (pow(data->n.cpx.real, 2.0) + pow(data->n.cpx.imag, 2.0) >= 4 \
	|| ++itr == data->sttgs.mx_itr)
		return (itr);
	data->n.tmp = data->n.cpx.real;
	data->n.cpx.real = pow(data->n.cpx.real, 2.0) - pow(data->n.cpx.imag, 2.0) + cpx.real;
	data->n.cpx.imag = 2.0 * data->n.tmp * data->n.cpx.imag + cpx.imag;
	return (mandelbrot(data, cpx, itr));
}	

int	circle(t_data *data, t_cpx cpx, int itr)
{
	(void)cpx.imag;
	(void)cpx.real;
	if (pow(data->n.cpx.real, 2.0) + pow(data->n.cpx.imag, 2.0) <= 4)
		itr = data->sttgs.mx_itr - 1;
	return (itr);
}
			// if(sqrt(pow(data->n.cpx.real, 2.0) + pow(data->n.cpx.imag, 2.0)) <= 4.0)
			// 	my_mlx_pixel_put(data, data->n.px_x, data->n.px_y, 0x00FF0000);
			// if (!data->n.cpx.real || !data->n.cpx.imag)
			// 	my_mlx_pixel_put(data, data->n.px_x, data->n.px_y, 0x00FFFFFF);
