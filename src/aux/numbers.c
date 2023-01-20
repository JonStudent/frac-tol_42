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

t_hvs	hvss(long double a, long double b)
{
	t_hvs	hvs;

	hvs.begin = a;
	hvs.end = b;
	return (hvs);
}

int	verify(t_frtl *f, char **v)
{
	if (!isnum(v[1]) || (v[0][1] != 'i' && v[0][1] != 'z' && !isnum(v[2])))
		exit_win(f, "@");
	if ((v[0][1] == 'i' || v[0][1] == 'z') && atod(v[1]) < 1)
		exit_win(f, "@");
	if (v[0][1] == 'c' && (atod(v[1]) < 0 || atod(v[1]) > 360 \
		|| atod(v[2]) < 0 || atod(v[2]) > 360))
		exit_win(f, "@");
	if (v[0][1] == 'w' && (atod(v[1]) < 1 || atod(v[2]) < 1))
		exit_win(f, "@");
	return (1);
}

int isnum(const char *s)
{
	if (!s)
		return (0);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '.')
		s++;
	if (*s >= '0' && *s <= '9')
		return (1);
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

int	stats(t_frtl *f, char s)
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

long double	atod(const char *s)
{
	long double	i;
	long double	n;
	char		t;

	i = 1;
	n = 0;
	t = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' && s++)
		i = -1;
	while (*s >= '0' && *s <= '9' && ++t)
		n = (n * 10) + i * (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9' && ++t)
	{
		i *= 0.1;
		n += i * (*s++ - '0');
	}
	return (n);
}
