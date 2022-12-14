/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:53:40 by jbasilio          #+#    #+#             */
/*   Updated: 2022/12/12 21:53:42 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	julia(t_frtl *f, t_cx cx, long itr)
{
	long double	tmp;

	if (pow(f->cx.real, 2.0) + pow(f->cx.imag, 2.0) >= 4 \
	|| ++itr == f->live.itr)
		return (itr);
	tmp = pow(f->cx.real, 2.0) - pow(f->cx.imag, 2.0) + cx.real;
	f->cx.imag = 2.0 * f->cx.real * f->cx.imag + cx.imag;
	f->cx.real = tmp;
	return (julia(f, cx, itr));
}
