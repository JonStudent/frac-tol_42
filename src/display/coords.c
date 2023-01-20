/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:52:48 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:50 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_cx	zoom(t_frtl *f, int key, t_px px)
{
	if (key == 4)
		f->live.zoom *= 2;
	else if (key == 5 && f->live.zoom > 1)
		f->live.zoom /= 2;
	if (key == 4 && f->opt >> 3 & 1)
		f->live.itr += f->init.itr / 10;
	else if (key == 5 && f->opt >> 3 & 1)
		f->live.itr -= f->init.itr / 10;
	coords(f, px);
	return (f->cx);
}

t_cx	coords(t_frtl *f, t_px px)
{
	f->cx = cmplx((px.x - f->w_cntr.x) \
	/ (long double)f->live.zoom + f->live.offset.real, \
	(f->w_cntr.y - px.y) \
	/ (long double)f->live.zoom + f->live.offset.imag);
	if (f->set == julia || !f->child)
		return (f->live.cx_j);
	return (f->cx);
}

int	fill_win(t_frtl *f)
{
	if (!f || !f->win)
		return (0);
	if (!(f->opt >> 5 & 1))
		f->lock++;
	ft_printf("\nRendring %s...", f->title);
	f->px.y = -1;
	while (++f->px.y < f->w_size.y)
	{
		f->px.x = -1;
		while (++f->px.x < f->w_size.x)
			color(f->set(f, coords(f, f->px), 0), f);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	ft_printf(GN" Done\n"RT);
	return (0);
}

static void	print_coords(t_cx crd)
{
	t_cx	dec;

	ft_printf("Coordinates: ["GN);
	if (crd.real < 0 && ft_printf("-"))
		crd.real = -crd.real;
	dec.real = (crd.real - (int)crd.real) * pow(10, 9);
	ft_printf("%0d"RT"."GN"%09u ", (int)crd.real, (unsigned)dec.real);
	if (crd.imag < 0 && ft_printf("-"))
		crd.imag = -crd.imag;
	dec.imag = (crd.imag - (int)crd.imag) * pow(10, 9);
	ft_printf("%0d"RT"."GN"%09u"RT"]", (int)crd.imag, (unsigned)dec.imag);
}

int	info(t_frtl *f, char s)
{
	ft_printf("\n%s's ", f->title);
	if (s == 's' && f->opt >> 5 & 1)
		return (ft_printf("Safety: "GN"ON"RT));
	else if (s == 's')
		return (ft_printf("Safety: "RD"OFF"RT));
	if (s == 'a' && f->opt >> 3 ^ 1)
		return (ft_printf("Auto Mode: "GN"ON"RT));
	else if (s == 'a')
		return (ft_printf("Auto Mode: "RD"OFF"RT));
	if (ft_printf("Zoom: ") && f->live.zoom / PP_CM > (unsigned)-1)
		ft_printf(GN"%u"RT, (f->live.zoom / PP_CM) / 1000000000);
	ft_printf(GN"%u \n"RT, (f->live.zoom / PP_CM) % 1000000000);
	print_coords(f->cx);
	return (ft_printf("\nMax Iterations: "YL"%u\n"RT, f->live.itr));
}
