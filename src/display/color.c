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

void	color(double itr, t_data *data)
{
	itr /= data->sttgs.mx_itr;
	data->sttgs.opt |= (unsigned char)255;
	itr *= data->sttgs.opt;
	
	if (data->sttgs.opt >> 8 & 1)
		itr = data->sttgs.opt - itr;
	
	if ((unsigned char)data->sttgs.opt == 255)
		itr = (int)itr << 16 | (int)itr << 8 | (int)itr;
	my_mlx_pixel_put(data, data->n.px, itr);
}
