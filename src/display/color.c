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

#include "../fractol.h"

static void	black_white(t_data *data, long double itr)
{
	itr *= 255;
	itr = (int)itr << 16 | (int)itr << 8 | (int)itr;
	my_mlx_pixel_put(data, data->n.px, itr);
}

void	color(long double itr, t_data *data)
{
	itr /= data->sttgs.live.itr;
	if (data->sttgs.opt >> 9 & 1)
		itr = pow(itr, 2);
	if (data->sttgs.opt >> 10 & 1)
		itr = sqrt(itr);
	if (data->sttgs.opt >> 8 & 1)
		itr = 1 - itr;
	if (!(char)data->sttgs.opt)
		black_white(data, itr);	
}
