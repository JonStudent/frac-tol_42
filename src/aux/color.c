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

void	color(int itr, t_data *data)
{
	itr = 0x00FFFFFF - (0x00FFFFFF * itr / data->sttgs.mx_itr);
	my_mlx_pixel_put(data, data->px.x, data->px.y, itr);
}
