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

void	stats(t_frtl *f, int i, int z)
{
	ft_printf("Max Iteration: %d Zoom: x%d ", i, z);
	print_coords(f->cx.real, f->cx.imag);
}

void	handle_error(t_frtl *frtl, char *cause)
{
	char	bad;

	bad = 0;
	if (cause && ++bad)
		perror(cause);
	if (!frtl->set)
		ft_printf("Get ready for manual!\n");
	win_close(frtl);
	win_close(frtl->parent);
	win_close(frtl->child);
	if (frtl->mlx)
		mlx_destroy_display(frtl->mlx);
	free(frtl->mlx);
	exit(bad);
}

void	child_win(t_frtl *f)
{
	if (f->child && f->child->win)
		win_close(f->child);
	else if (f->child)
		settings(f->child, f->mlx, f);
	else
		win_close(f);
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
