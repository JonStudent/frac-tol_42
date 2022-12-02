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
	itr = itr * 255 / data->sttgs.mx_itr;
	if (itr == 255)
		itr = 0;
	itr = itr << 10 | itr << 3 | itr;
	my_mlx_pixel_put(data, data->n.px_x, data->n.px_y, itr);
}
