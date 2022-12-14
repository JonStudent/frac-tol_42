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

void	pixel_to_img(t_frtl *frtl, t_px px, int color)
{
	char	*dst;

	dst = frtl->img.addr + \
	(px.y * frtl->img.line_len + px.x * (frtl->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	win_close(t_frtl *frtl)
{
	if (!frtl)
		return ;
	if (frtl->mlx && frtl->img.img)
		mlx_destroy_image(frtl->mlx, frtl->img.img);
	frtl->img.img = 0;
	if (frtl->mlx && frtl->win)
		mlx_destroy_window(frtl->mlx, frtl->win);
	frtl->win = 0;
}

void	init_win(t_frtl *frtl)
{
	frtl->win = mlx_new_window(frtl->mlx, frtl->img.win_size.x, \
	frtl->img.win_size.y, frtl->title);
	if (!frtl->win)
		handle_error(frtl, "Mlx didn't create window--");
	frtl->img.img = mlx_new_image(frtl->mlx, frtl->img.win_size.x, \
	frtl->img.win_size.y);
	if (!frtl->img.img)
		handle_error(frtl, "Mlx didn't create image--");
	frtl->img.addr = mlx_get_data_addr(frtl->img.img, \
	&frtl->img.bits_per_pixel, &frtl->img.line_len, &frtl->img.endian);
	mlx_key_hook(frtl->win, keyboard, frtl);
	mlx_mouse_hook(frtl->win, mouse, frtl);
}

void	default_win(t_frtl *frtl)
{
	if (!frtl->init.itr)
		frtl->init.itr = 64;
	if (!frtl->img.win_size.x || !frtl->img.win_size.y)
		frtl->img.win_size = pxl(WIDTH, HEIGHT);
	if (!frtl->init.zoom)
		frtl->init.zoom = PP_CM * (frtl->img.win_size.y / 350.0);
	if (!frtl->img.hsv.imag)
		frtl->img.hsv.imag = 240;
	frtl->curr.cx_j = frtl->init.cx_j;
	frtl->curr.itr = frtl->init.itr;
	frtl->curr.zoom = frtl->init.zoom;
	frtl->curr.offset = frtl->init.offset;
	frtl->img.mid_win = pxl(frtl->img.win_size.x / 2, frtl->img.win_size.y / 2);
}
