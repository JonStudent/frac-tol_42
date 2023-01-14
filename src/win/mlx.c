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
	f->win = mlx_new_window(f->mlx, f->w_size.x, \
	f->w_size.y, f->title);
	if (!f->win)
		handle_error(f, "Mlx could not create window");
	f->img.img = mlx_new_image(f->mlx, f->w_size.x, \
	f->w_size.y);
	if (!f->img.img)
		handle_error(f, "Mlx could not create image");
	f->img.addr = mlx_get_data_addr(f->img.img, \
	&f->img.bits_per_pixel, &f->img.line_len, &f->img.endian);
	mlx_key_hook(f->win, keyboard, f);
	mlx_hook(f->win, 04, (1L << 2), mouse, f);
	mlx_hook(f->win, 05, (1L << 3), move, f);
	mlx_expose_hook(f->win, expose, f);
	mlx_hook(f->win, 06, (1L << 8), dance, f);
	mlx_hook(f->win, 33, (1L << 5), win_close, f);
}
