/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:52:45 by jbasilio          #+#    #+#             */
/*   Updated: 2022/12/12 21:52:49 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	stats(t_frtl *f, int i, int z)
{
	ft_printf("Max Iteration: %d Zoom: x%d ", i, z);
	print_coords(f->cx.real, f->cx.imag);
}

void	handle_error(t_frtl *f, char *cause)
{
	char	bad;

	bad = 0;
	if (cause && ++bad)
		perror(cause);
	if (!f->set)
		ft_printf("Get ready for manual!\n");
	win_close(f);
	win_close(f->parent);
	win_close(f->child);
	if (f->mlx)
		mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(bad);
}

void	child_win(t_frtl *f)
{
	if (f->child && f->child->win)
		win_close(f->child);
	else if (f->child)
		create_win(f->child, f->mlx, f);
	else
		win_close(f);
}

void	create_win(t_frtl *child, void *mlx, t_frtl *parent)
{
	child->mlx = mlx;
	if (!child->mlx)
		handle_error(child, "Mlx did't init--");
	child->set = parent->set;
	if (child->set == mandelbrot)
		child->title = "Mandelbrot Set";
	else if (child->set == julia)
		child->title = "Julia Set";
	else if (child->set == burning_ship)
		child->title = "Burning_Ship Set";
	if (!child->child)
		child->init.cx_j = child->live.cx_j;
	default_win(child);
	init_win(child);
	fill_win(child);
}
