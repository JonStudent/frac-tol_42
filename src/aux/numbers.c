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

int	isnum(const char *s)
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
