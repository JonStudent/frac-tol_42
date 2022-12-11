/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:52:38 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:40 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	mod(double a, int b)
{
	return (a - pow(b, (int)(a / b)));
}

int	hsv2rgb(double h, double s, double v)
{
	double c;
	double m;
	double z;

	c = 255 * v;
	m = c * (1 - s);

	z =  (c - m) * (1 - ldabs(mod(h / 60, 2) - 1));
	if (0 <= h && h < 60)
		return ((int)c << 16 | (int)(z + m) << 8 | (int)m);
	if (60 <= h && h < 120)
		return ((int)(z + m) << 16 | (int)c << 8 | (int)m);
	if (120 <= h && h < 180)
		return ((int)m << 16 | (int)c << 8 | (int)(z + m));
	if (180 <= h && h < 240)
		return ((int)m << 16 | (int)(z + m) << 8 | (int)c);
	if (240 <= h && h < 300)
		return ((int)(z + m) << 16 | (int)m << 8 | (int)c);
	if (300 <= h && h < 360)
		return ((int)c << 16 | (int)m << 8 | (int)(z + m));
	return (0);
}

static void	black_white(t_data *data, long double itr)
{
	itr *= 255;
	itr = (int)itr << 16 | (int)itr << 8 | (int)itr;
	my_mlx_pixel_put(data, data->n.px, itr);
}

void	color(double itr, t_data *data)
{
	itr /= data->sttgs.live.itr;
	if (data->sttgs.opt >> 9 & 1)
		itr = pow(itr, 2);
	if (data->sttgs.opt >> 10 & 1)
		itr = sqrt(itr);
	if (data->sttgs.opt >> 8 & 1)
		itr = 1 - itr;
	if (!data->sttgs.clr || data->sttgs.clr == N0_K)
		black_white(data, itr);
	if (data->sttgs.clr == N1_K)
		my_mlx_pixel_put(data, data->n.px, hsv2rgb(itr * 360, 1, 1));
}
