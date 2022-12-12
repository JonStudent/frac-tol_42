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

static long	hsv2rgb(double h, double s, double v)
{
	double c;
	double m;
	double z;

	c = 255 * v;
	m = c * (1 - s);
	if (h == 360)
		h = 0;
	z =  (c - m) * (1 - ldabs(d_mod(h / 60, 2) - 1));
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

static void	black_white(t_data *data, double itr)
{
	itr *= 255;
	itr = (int)itr << 16 | (int)itr << 8 | (int)itr;
	img_pixel(data, data->px, itr);
}

static void	hsv_scale(t_data *data, double itr)
{	
	int	rgb;

	rgb = hsv2rgb(data->init.hsv + itr * data->head.hsv, 1, 1);
	if ((data->opt & 1 && !itr) || (!(data->opt & 1) && (int)itr))
		rgb = 0;
	img_pixel(data, data->px, rgb);
}

void	color(double itr, t_data *data)
{
	itr /= data->head.itr;
	if (data->opt >> 1 & 1)
		itr = pow(itr, 2);
	if (data->opt >> 2 & 1)
		itr = sqrt(itr);
	if (data->opt & 1)
		itr = 1 - itr;
	if (!data->clr || data->clr == N1_K)
		hsv_scale(data, itr);
	if (data->clr == N0_K)
		black_white(data, itr);
}
