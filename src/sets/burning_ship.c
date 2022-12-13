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

double	burning_ship(t_frtl *frtl, t_cx cx, long itr)
{
	long double	tmp;

	if (pow(frtl->cx.real, 2.0) + pow(frtl->cx.imag, 2.0) >= 4 \
	|| ++itr == frtl->curr.itr)
		return (itr);
	tmp = pow(frtl->cx.real, 2.0) - pow(frtl->cx.imag, 2.0) + cx.real;
	frtl->cx.imag = -2.0 * fabs((double)(frtl->cx.real * frtl->cx.imag)) + cx.imag;
	frtl->cx.real = tmp;
	return (burning_ship(frtl, cx, itr));
}
