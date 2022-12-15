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

void	pixel_to_img(t_frtl *f, t_px px, int color)
{
	char	*dst;

	dst = f->img.addr + \
	(px.y * f->img.line_len + px.x * (f->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	child_win(t_frtl *f)
{
	if (f->child && f->child->win)
		return (win_close(f->child));
	if (f->child)
		create_win(f->child, f->mlx, f);
	else
		return (win_close(f));
	return (0);
}

int	win_close(t_frtl *f)
{
	if (!f)
		return (0);
	if (f->img.img)
		mlx_destroy_image(f->mlx, f->img.img);
	f->img.img = 0;
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	f->win = 0;
	win_close(f->child);
	if (f->child)
		handle_error(f, NULL);
	return (0);
}

void	init_win(t_frtl *f)
{
	f->win = mlx_new_window(f->mlx, f->img.w_size.x, \
	f->img.w_size.y, f->title);
	if (!f->win)
		handle_error(f, "Mlx didn't create window--");
	f->img.img = mlx_new_image(f->mlx, f->img.w_size.x, \
	f->img.w_size.y);
	if (!f->img.img)
		handle_error(f, "Mlx didn't create image--");
	f->img.addr = mlx_get_data_addr(f->img.img, \
	&f->img.bits_per_pixel, &f->img.line_len, &f->img.endian);
	mlx_key_hook(f->win, keyboard, f);
	mlx_mouse_hook(f->win, mouse, f);
	mlx_hook(f->win, 33, 1L << 5, win_close, f);
	mlx_expose_hook(f->win, fill_win, f);
}

void	default_win(t_frtl *f)
{
	if (!f->init.itr)
		f->init.itr = 70;
	if (!f->img.w_size.x || !f->img.w_size.y)
		f->img.w_size = pxl(WIDTH, HEIGHT);
	if (!f->init.zoom)
		f->init.zoom = PP_CM * (f->img.w_size.y / 350.0);
	if (!f->img.hsv.imag)
		f->img.hsv.imag = 240;
	f->live.cx_j = f->init.cx_j;
	f->live.itr = f->init.itr;
	f->live.zoom = f->init.zoom;
	f->live.offset = f->init.offset;
	f->img.w_cntr = pxl(f->img.w_size.x / 2, f->img.w_size.y / 2);
}
