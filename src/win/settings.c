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

void	*get_param(t_frtl *f, int i, int c, char **v)
{
	if (v[i][0] == 'j' || v[i][0] == 'J')
		f->set = julia;
	if ((v[i][0] == 'j' || v[i][0] == 'J') && i + 2 < c)
		f->init.cx_j = cmplx(atod(v[i + 1]), atod(v[i + 2]));
	else if (v[i][0] == 'm' || v[i][0] == 'M')
		f->set = mandelbrot;
	else if (v[i][0] == 'b' || v[i][0] == 'B')
		f->set = burning_ship;
	else if (v[i][0] == '-' && (v[i][1] == 'i' && i + 1 < c))
		f->init.itr = atod(v[i + 1]);
	else if (v[i][0] == '-' && (v[i][1] == 'z' && i + 1 < c))
		f->init.zoom = atod(v[i + 1]) * PP_CM;
	else if (v[i][0] == '-' && (v[i][1] == 'c' && i + 2 < c))
		f->img.hsv = cmplx(atod(v[i + 1]), atod(v[i + 2]));
	else if (v[i][0] == '-' && (v[i][1] == 'w' && i + 2 < c))
		f->img.w_size = pxl(atod(v[i + 1]), atod(v[i + 2]));
	else if (v[i][0] == '-' && (v[i][1] == 'o' && i + 2 < c))
		f->init.offset = cmplx(atod(v[i + 1]), atod(v[i + 2]));
	if (++i < c)
		get_param(f, i, c, v);
	return (f->set);
}

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
	if (f->win)
		win_close(f);
	win_close(f->parent);
	if (f->mlx)
		mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(bad);
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
