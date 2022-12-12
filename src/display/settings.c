/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:52:45 by jbasilio          #+#    #+#             */
/*   Updated: 2022/12/12 21:52:49 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	win_close(t_frtl *frtl)
{
	if (frtl->mlx && frtl->img.img)
		mlx_destroy_image(frtl->mlx, frtl->img.img);
	frtl->img.img = 0;
	if (frtl->mlx && frtl->win)
		mlx_destroy_window(frtl->mlx, frtl->win);
	frtl->win = 0;
	return (0);
}

void	handle_error(t_frtl *frtl, char *cause)
{
	if (!frtl->set)
		ft_printf("Get ready for manual!\n");
	if (cause)
		perror(cause);
	win_close(frtl);
	if (frtl->parent)
		win_close(frtl->parent);
	if (frtl->child)
		win_close(frtl->child);
	if (frtl->mlx)
		mlx_destroy_display(frtl->mlx);
	free(frtl->mlx);
	exit(0);
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
		frtl->img.hsv.imag = 360;
	frtl->curr.cx_j = frtl->init.cx_j;
	frtl->curr.itr = frtl->init.itr;
	frtl->curr.zoom = frtl->init.zoom;
	frtl->curr.offset = frtl->init.offset;
	frtl->img.mid_win = pxl(frtl->img.win_size.x / 2, frtl->img.win_size.y / 2);
}

t_frtl	*settings(t_frtl *frtl_c, void *mlx, t_frtl *frtl_p)
{
	frtl_c->mlx = mlx;
	if (!frtl_c->mlx)
		handle_error(frtl_c, "Mlx did't init--");
	frtl_c->set = frtl_p->set;
	if (frtl_c->set == mandelbrot)
		frtl_c->title = "Mandelbrot Set";
	else if (frtl_c->set == julia)
		frtl_c->title = "Julia Set";
	else if (frtl_c->set == burning_ship)
		frtl_c->title = "Burning_Ship Set";
	if (!frtl_c->init.cx_j.real && !frtl_c->init.cx_j.imag)
		frtl_c->init.cx_j = frtl_c->curr.cx_j;
	default_win(frtl_c);
	init_win(frtl_c);
	return (frtl_c);
}
