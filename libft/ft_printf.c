/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:11:34 by jbasilio          #+#    #+#             */
/*   Updated: 2022/07/27 22:30:53 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void	ft_print(t_format *f, int in)
{	
	while (!f->mn && !f->xw && f->wd-- > 0)
		if ((f->zr && write(1, "0", 1)) || write(1, " ", 1))
			++f->c;
	if (f->hs && (f->n || !(!(f->cv == 'p') || write(1, f->nlp, f->hs-- + 4))))
		f->c += write(1, f->hss--, f->hs-- + 1);
	if ((f->pl && write(1, "+", 1)) || (f->sc && write(1, " ", 1)))
		if ((f->pl && f->pl--) || (f->sc && f->sc--))
			f->c++;
	if (f->ng && f->ng-- && write(1, "-", 1) && ++f->c)
		f->n = -(long)f->n;
	while (!f->xw && f->dc && f->pc-- > 0 && write(1, "0", 1))
		f->c++;
	while (!f->xw && f->dc && !f->xz && !(!f->n && f->cv == 'p'))
		if (write(1, &f->dgs[(f->n / f->dc) % f->bs], 1) && ++f->c)
			f->dc /= f->bs;
	if (!f->xw && f->cv == 's' && (char *)f->n)
		while (*(char *)f->n && (!f->t || f->pc-- > 0))
			f->c += write(1, (char *)f->n++, 1);
	else if (!f->xw && f->cv == 's' && (!f->t || f->pc > 5))
		f->c += write(1, f->nl, 6);
	if (!f->xw && f->cv == 'c' && !in)
		f->c += write(1, &f->n, 1);
	if ((!f->xw || --f->xw) && f->cv == '%' && !in)
		f->c += write (1, "%", 1);
}

static void	ft_calc(t_format *f, int dc)
{
	if (f->t && !f->pc && !f->n && ++f->xz)
		return ;
	if (ft_strchr(A_H, f->cv))
		f->bs = 16;
	if (f->cv == 'X')
		f->dgs = "0123456789ABCDEF";
	if (f->cv == 'X')
		f->hss = "0X";
	f->t = f->n;
	if (f->cv != 'p' && (long)f->n < 0 && ++f->ng)
		if ((!f->pl || f->pl--) && (!f->sc || f->sc--))
			f->t = -(long)f->n;
	while (f->t / f->bs && ++dc)
		f->t /= f->bs;
	f->pc -= dc;
	if (f->pc > 0)
		f->wd -= f->pc;
	f->wd -= dc + f->ng + f->sc + f->pl;
	if (!f->n && f->cv == 'p')
		f->wd -= 2;
	while ((!f->dc && f->dc++) || --dc)
		f->dc *= f->bs;
	if (f->zr && (f->ng || f->pl || f->sc || f->hs))
		f->xw = 1;
}

static int	ft_prep(t_format *f, int in)
{
	if (f->cv != 'd' && f->cv != 'i' && (!f->sc || f->sc--))
		f->pl = 0;
	if (ft_strchr(A_Z, f->cv) && f->t)
		f->zr = 0;
	if (!f->n && f->cv == 'p')
		f->c += 5;
	if (ft_strchr(A_N, f->cv))
		ft_calc(f, 1);
	else if (f->cv != 's' && (!f->wd || f->wd--))
		if (f->cv == 'c')
			f->n = (unsigned char)(long)f->n;
	if (f->cv == 's' && (char *)f->n)
	{
		if (f->t && (int)ft_strlen((char *)f->n) - f->pc > 0)
			f->wd -= f->pc;
		else
			f->wd -= ft_strlen((char *)f->n);
	}
	else if (f->cv == 's' && f->t && 6 - f->pc > 0)
		f->wd -= f->pc;
	else if (f->cv == 's')
		f->wd -= 6;
	while (f->xw || !--in || !--f->mn)
		ft_print(f, in);
	return (f->c);
}

static void	ft_parse(t_format *f, const char **s, va_list	*p)
{
	if (**s == '#')
		f->hs = 1;
	if (**s == ' ' && !f->pl)
		f->sc = 1;
	if (**s == '+' && !(f->sc && --f->sc))
		f->pl = 1;
	if (**s == '-' && !(f->zr && --f->zr))
		f->mn = 1;
	if (**s == '0' && !f->wd && !f->t && !f->mn)
		f->zr = 1;
	if ((**s > '0' && **s <= '9') && !f->wd && !f->t)
		f->wd = ft_atoi(*s);
	if (**s == '.' && ++f->t)
		f->pc = ft_atoi(++(*s));
	if (ft_strchr(A_T, *((*s)++)))
		f->cv = *(*s - 1);
	if (f->cv && ft_strchr(A_I, f->cv))
		f->n = va_arg(*p, int);
	if (f->cv && ft_strchr(A_U, f->cv))
		f->n = va_arg(*p, unsigned int);
	if (f->cv == 'p' || f->cv == 's')
		f->n = va_arg(*p, unsigned long);
	if (f->cv && (f->hs || (f->cv == 'p' && ++f->hs)))
		f->wd -= 2;
}

int	ft_printf(const char *s, ...)
{
	int			count;
	va_list		p;
	t_format	f;

	count = 0;
	va_start(p, s);
	while (*s)
	{
		if ((*s++ != '%' && write(1, s - 1, 1)) && ++count)
			continue ;
		ft_bzero(&f, sizeof(f));
		f.dgs = "0123456789abcdef";
		f.hss = "0x";
		f.nlp = "(nil)";
		f.nl = "(null)";
		f.bs = 10;
		while (!f.cv)
			ft_parse(&f, &s, &p);
		count += ft_prep(&f, 1);
	}
	va_end(p);
	return (count);
}
