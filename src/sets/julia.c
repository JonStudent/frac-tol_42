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

double	julia(t_data *frtl, t_cx cx, long itr)
{
	long double	tmp;

	if (pow(frtl->cx.real, 2.0) + pow(frtl->cx.imag, 2.0) >= 4 \
	|| ++itr == frtl->head.itr)
		return (itr);
	tmp = pow(frtl->cx.real, 2.0) - pow(frtl->cx.imag, 2.0) + cx.real;
	frtl->cx.imag = 2.0 * frtl->cx.real * frtl->cx.imag + cx.imag;
	frtl->cx.real = tmp;
	return (julia(frtl, cx, itr));
}
