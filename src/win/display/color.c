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

#include "../../fractol.h"

static long	hsv2rgb(double h, double s, double v)
{
	double	c;
	double	m;
	double	z;

	c = 255 * v;
	m = c * (1 - s);
	z = (c - m) * (1 - fabs(fmod(h / 60, 2) - 1));
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
	if (300 <= h && h <= 360)
		return ((int)c << 16 | (int)m << 8 | (int)(z + m));
	return (0);
}

static void	black_white(t_frtl *f, double itr)
{
	if (f->opt >> 4 & 1 && (int)(itr * f->live.itr) % 2)
		itr = 1 - itr;
	itr *= 255;
	itr = (int)itr << 16 | (int)itr << 8 | (int)itr;
	pixel_to_img(f, f->px, itr);
}

static void	hsv_scale(t_frtl *f, double itr)
{	
	int		rgb;
	double	perc;

	perc = itr;
	if (f->opt >> 4 & 1 && (int)(itr * f->live.itr) % 2)
		perc = 1 - perc;
	rgb = hsv2rgb(f->img.hsv.begin + perc * f->img.hsv.diff, 1, 1);
	if ((f->opt & 1 && !itr) || (!(f->opt & 1) && (int)itr))
		rgb = 0;
	pixel_to_img(f, f->px, rgb);
}

void	color(long itr, t_frtl *f)
{
	double	smooth;

	smooth = 0;
	if (f->opt >> 6 & 1 && itr && f->live.itr != itr)
		smooth = 1 - log(log2(pow(f->cx.real, 2.0) + pow(f->cx.imag, 2.0)));
	smooth = (itr + smooth) / (f->live.itr + smooth);
	if (f->opt >> 1 & 1)
		smooth = pow(smooth, 2);
	if (f->opt >> 2 & 1)
		smooth = sqrt(smooth);
	if (f->opt & 1)
		smooth = 1 - smooth;
	if (!f->img.clr || f->img.clr == N1_K)
		hsv_scale(f, smooth);
	if (f->img.clr == N0_K)
		black_white(f, smooth);
}
