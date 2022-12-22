/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:53:04 by jbasilio          #+#    #+#             */
/*   Updated: 2022/12/12 21:53:14 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_cx	cmplx(long double a, long double b)
{
	t_cx	c;

	c.real = a;
	c.imag = b;
	return (c);
}

t_px	pxl(int a, int b)
{
	t_px	p;

	p.x = a;
	p.y = b;
	return (p);
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

int	stats(t_frtl *f, char s)
{
	ft_printf("\n%s's ", f->title);
	if (s == 's' && ft_printf("Safety: "))
		if (f->opt >> 5 & 1)
			return (ft_printf(GN"ON"RT));
	if (s == 's')
		return (ft_printf(RD"OFF"RT));
	if (s == 'a' && ft_printf("Auto Mode: "))
		if (!(f->opt >> 3 & 1))
			return (ft_printf(GN"ON"RT));
	if (s == 'a')
		return (ft_printf(RD"OFF"RT));
	if (f->live.zoom / PP_CM > (unsigned)-1)
		ft_printf("Zoom: "RD"%s "RT, TOBIG);
	else
		ft_printf("Zoom: "GN"%u "RT, f->live.zoom / PP_CM);
	print_coords(f->cx);
	ft_printf("\nMax Iterations: "YL"%u\n"RT, f->live.itr);
	return (0);
}

long double	atod(const char *s)
{
	long double	i;
	long double	n;

	i = 1.0;
	n = 0.0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' && s++)
		i = -1;
	while (*s >= '0' && *s <= '9')
		n = (n * 10) + i * (*s++ - '0');
	while (*s++ == '.' || (*s >= '0' && *s <= '9'))
	{
		i *= 0.1;
		n += i * (*s - '0');
	}
	return (n);
}
