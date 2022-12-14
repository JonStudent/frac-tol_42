/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:53:56 by jbasilio          #+#    #+#             */
/*   Updated: 2022/12/12 21:53:57 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	burning_ship(t_frtl *f, t_cx cx, long itr)
{
	long double	tmp;

	if (pow(f->cx.real, 2.0) + pow(f->cx.imag, 2.0) >= 4 \
	|| ++itr == f->live.itr)
		return (itr);
	tmp = -2.0 * fabs((double)(f->cx.real * f->cx.imag)) + cx.imag;
	f->cx.real = pow(f->cx.real, 2.0) - pow(f->cx.imag, 2.0) + cx.real;
	f->cx.imag = tmp;
	return (burning_ship(f, cx, itr));
}
