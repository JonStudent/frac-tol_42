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
	if (!data->sttgs.clr)
		data->sttgs.clr = 255;
	if (data->sttgs.clr == 1)
		data->sttgs.clr = 0x00FFFFFF;
	
	itr /= data->sttgs.mx_itr;
	if (data->sttgs.opt >> 1 & 1 && itr < 1)
		itr *= (data->sttgs.mx_itr / (double)data->sttgs.ini_mx_itr);
	itr *= data->sttgs.clr;
	
	if (data->sttgs.opt & 1)
		itr = data->sttgs.clr - itr;
	
	if (data->sttgs.clr == 255)
		itr = (int)itr << 16 | (int)itr << 8 | (int)itr;
	
	my_mlx_pixel_put(data, data->px.x, data->px.y, itr);
}
