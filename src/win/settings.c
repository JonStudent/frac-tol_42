/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:52:45 by jbasilio          #+#    #+#             */
/*   Updated: 2022/12/12 21:52:49 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	keyboard_plus(int key, t_frtl *f)
{
	if (key == N0_K || key == N1_K || key == N2_K)
		f->img.clr = key;
	else if (key == 'i')
		f->opt ^= 1 << 0;
	else if (key == 'u')
		f->opt ^= 1 << 1;
	else if (key == 'y')
		f->opt ^= 1 << 2;
	else if (key == 'a' && stats(f, key))
		f->opt ^= 1 << 3;
	else if (key == 'o')
		f->opt ^= 1 << 4;
	else if (key == 's' && stats(f, key))
		f->opt ^= 1 << 5;
	else if (key == 'r')
		default_win(f);
	else if (key == 'j')
		return (child_win(f));
	else if (key == ESC_K)
		handle_error(f, NULL);
	else
		return (0);
	if (f->opt >> 5 & 1)
		return (!++f->lock);
	return (fill_win(f));
}

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
		f->w_size = pxl(atod(v[i + 1]), atod(v[i + 2]));
	else if (v[i][0] == '-' && (v[i][1] == 'o' && i + 2 < c))
		f->init.offset = cmplx(atod(v[i + 1]), atod(v[i + 2]));
	if (++i < c)
		get_param(f, i, c, v);
	return (f->set);
}

void	handle_error(t_frtl *f, char *cause)
{
	if (cause)
		perror(cause);
	if (!f->set)
		ft_printf(WLC"\n"MAN);
	if (f->win)
		win_close(f);
	win_close(f->parent);
	if (f->mlx)
		mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
}

void	create_win(t_frtl *child, void *mlx, t_frtl *parent)
{
	child->mlx = mlx;
	if (!child->mlx)
		handle_error(child, "Mlx could not init");
	child->set = parent->set;
	if (child->set == julia || child->parent)
		child->title = "Julia";
	else if (child->set == mandelbrot)
		child->title = "Mandelbrot";
	else if (child->set == burning_ship)
		child->title = "Burning_Ship";
	if (child->parent)
		child->init.cx_j = child->live.cx_j;
	default_win(child);
	init_win(child);
}
