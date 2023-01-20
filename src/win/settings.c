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

static int	verify(t_frtl *f, char **v)
{
	if (!isnum(v[1]) || (v[0][1] != 'i' && v[0][1] != 'z' && !isnum(v[2])))
		exit_win(f, "@");
	if ((v[0][1] == 'i' || v[0][1] == 'z') && atod(v[1]) < 1)
		exit_win(f, "@");
	if (v[0][1] == 'c' && (atod(v[1]) < 0 || atod(v[1]) > 360 \
		|| atod(v[2]) < 0 || atod(v[2]) > 360))
		exit_win(f, "@");
	if (v[0][1] == 'w' && (atod(v[1]) < 200 || atod(v[2]) < 200))
		exit_win(f, "@");
	return (1);
}

void	*get_param(t_frtl *f, char **v)
{
	if (v[0][0] == 'j' || v[0][0] == 'J')
		f->set = julia;
	if ((v[0][0] == 'j' || v[0][0] == 'J') \
		&& isnum(v[1]) && isnum(v[2]))
		f->init.cx_j = cmplx(atod(v[1]), atod(v[2]));
	else if (v[0][0] == 'm' || v[0][0] == 'M')
		f->set = mandelbrot;
	else if (v[0][0] == 'b' || v[0][0] == 'B')
		f->set = burning_ship;
	else if (v[0][0] == '-' && v[0][1] == 'i' && verify(f, v))
		f->init.itr = atod(v[1]);
	else if (v[0][0] == '-' && v[0][1] == 'z' && verify(f, v))
		f->init.zoom = atod(v[1]) * PP_CM;
	else if (v[0][0] == '-' && v[0][1] == 'c' && verify(f, v))
		f->img.hsv = hvss(atod(v[1]), atod(v[2]));
	else if (v[0][0] == '-' && v[0][1] == 'w' && verify(f, v))
		f->w_size = pxl(atod(v[1]), atod(v[2]));
	else if (v[0][0] == '-' && v[0][1] == 'o' && verify(f, v))
		f->init.offset = cmplx(atod(v[1]), atod(v[2]));
	if (*++v)
		get_param(f, v);
	return (f->set);
}

void	default_win(t_frtl *f)
{
	if (!f->init.itr)
		f->init.itr = 50;
	if (!f->w_size.x || !f->w_size.y)
		f->w_size = pxl(WIDTH, HEIGHT);
	if (!f->init.zoom)
		f->init.zoom = PP_CM * (f->w_size.y / 350.0);
	if (!f->img.hsv.begin && !f->img.hsv.end)
		f->img.hsv.end = 360;
	if (!f->img.hsv.diff)
		f->img.hsv.diff = f->img.hsv.end - f->img.hsv.begin;
	f->live.cx_j = f->init.cx_j;
	f->live.itr = f->init.itr;
	f->live.zoom = f->init.zoom;
	f->live.offset = f->init.offset;
	f->w_cntr = pxl(f->w_size.x / 2, f->w_size.y / 2);
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
		exit_win(child, "Mlx could not init");
	child->set = parent->set;
	if (child->set == julia || child->parent)
		child->title = "Julia";
	else if (child->set == mandelbrot)
		child->title = "Mandelbrot";
	else if (child->set == burning_ship)
		child->title = "Burning Ship";
	if (child->parent)
		child->init.cx_j = child->live.cx_j;
	default_win(child);
	init_win(child);
}
