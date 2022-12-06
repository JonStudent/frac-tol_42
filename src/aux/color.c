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

	if (!data->sttgs.pltt)
		data->sttgs.pltt = 255;
	else if (data->sttgs.pltt == 1)
		data->sttgs.pltt = 0x00FFFFFF;
	else if (data->sttgs.pltt == 2)
		data->sttgs.pltt = 18;

	itr *= data->sttgs.pltt;
	
	if (data->sttgs.opt >> 7 & 1)
		itr = data->sttgs.pltt - itr;
	
	if (data->sttgs.pltt == 255)
		itr = (int)itr << 16 | (int)itr << 8 | (int)itr;
	else if (data->sttgs.pltt == 18)
		itr = data->sttgs.palette[(int)itr];
	my_mlx_pixel_put(data, data->px.x, data->px.y, itr);
}
