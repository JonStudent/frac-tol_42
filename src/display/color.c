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

static void	black_white(t_data *frtl, double itr)
{
	itr *= 255;
	itr = (int)itr << 16 | (int)itr << 8 | (int)itr;
	img_pixel(frtl, frtl->px, itr);
}

static void	hsv_scale(t_data *frtl, double itr)
{	
	int	rgb;

	rgb = hsv2rgb(frtl->init.hsv + itr * frtl->head.hsv, 1, 1);
	if ((frtl->opt & 1 && !itr) || (!(frtl->opt & 1) && (int)itr))
		rgb = 0;
	img_pixel(frtl, frtl->px, rgb);
}

void	color(double itr, t_data *frtl)
{
	itr /= frtl->head.itr;
	if (frtl->opt >> 1 & 1)
		itr = pow(itr, 2);
	if (frtl->opt >> 2 & 1)
		itr = sqrt(itr);
	if (frtl->opt & 1)
		itr = 1 - itr;
	if (!frtl->clr || frtl->clr == N1_K)
		hsv_scale(frtl, itr);
	if (frtl->clr == N0_K)
		black_white(frtl, itr);
}
