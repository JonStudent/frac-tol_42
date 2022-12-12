/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:52:58 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:59 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	img_pixel(t_data *frtl, t_px px, int color)
{
	char	*dst;

	dst = frtl->img.addr + \
	(px.y * frtl->img.line_len + px.x * (frtl->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_win(t_data *frtl)
{
	frtl->win = mlx_new_window(frtl->mlx, frtl->win_size.x, \
	frtl->win_size.y, frtl->title);
	if (!frtl->win)
		handle_error(frtl, "mlx didn't create window--");
	frtl->img.img = mlx_new_image(frtl->mlx, frtl->win_size.x, \
	frtl->win_size.y);
	if (!frtl->img.img)
		handle_error(frtl, "mlx didn't create image--");
	frtl->img.addr = mlx_get_data_addr(frtl->img.img, \
	&frtl->img.bits_per_pixel, &frtl->img.line_len, &frtl->img.endian);
	mlx_key_hook(frtl->win, keyboard, frtl);
	mlx_mouse_hook(frtl->win, mouse, frtl);
}
