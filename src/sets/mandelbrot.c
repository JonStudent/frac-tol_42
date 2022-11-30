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

int	mandelbrot(t_data *data, double i_real, double i_imag, int itr)
{
	if (pow(data->n.real, 2.0) + pow(data->n.imag, 2.0) >= 4 \
	|| ++itr == data->sttgs.mx_itr)
		return (itr);
	data->n.tmp = data->n.real;
	data->n.real = pow(data->n.real, 2.0) - pow(data->n.imag, 2.0) + i_real;
	data->n.imag = 2.0 * data->n.tmp * data->n.imag + i_imag;
	return (mandelbrot(data, i_real, i_imag, itr));
}	

int	circle(t_data *data, double i_real, double i_imag, int itr)
{
	(void)i_imag;
	(void)i_real;
	if (pow(data->n.real, 2.0) + pow(data->n.imag, 2.0) <= 4)
		itr = data->sttgs.mx_itr;
	return (itr);
}
			// if(sqrt(pow(data->n.real, 2.0) + pow(data->n.imag, 2.0)) <= 4.0)
			// 	my_mlx_pixel_put(data, data->n.px_x, data->n.px_y, 0x00FF0000);
			// if (!data->n.real || !data->n.imag)
			// 	my_mlx_pixel_put(data, data->n.px_x, data->n.px_y, 0x00FFFFFF);
