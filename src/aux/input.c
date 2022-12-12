#include "../fractol.h"

void	*get_param(t_data *frtl, int i, int c, char **v)
{
	if (v[i][0] == 'j' || v[i][0] == 'J')
	{
		if (i + 2 < c)
			frtl->cx_j = cmplx(atod(v[i + 1]), atod(v[i + 2]));
		frtl->set = julia;
	}
	else if (v[i][0] == 'm' || v[i][0] == 'M')
		frtl->set = mandelbrot;
	else if (v[i][0] == 'b' || v[i][0] == 'B')
		frtl->set = burning_ship;
	else if (v[i][0] == '-')
	{
		if (v[i][1] == 'z' && i + 1 < c)
			frtl->init.zoom = atod(v[i + 1]) * PP_CM;
		else if (v[i][1] == 'i' && i + 1 < c)
			frtl->init.itr = atod(v[i + 1]);
		else if (v[i][1] == 'w' && i + 2 < c)
			frtl->win_size = pxl(atod(v[i + 1]), atod(v[i + 2]));
		else if (v[i][1] == 'o' && i + 2 < c)
			frtl->init.offset = cmplx(atod(v[i + 1]), atod(v[i + 2]));
		else if (v[i][1] == 'c' && i + 2 < c)
		{
			frtl->init.hsv = atod(v[i + 1]);
			frtl->head.hsv = atod(v[i + 2]);
		}
	}
	if (++i < c)
		get_param(frtl, i, c, v);
	return (frtl->set);
}

static int	keyboard_plus(int key, t_data *frtl)
{
	if (key == 'i')
		frtl->opt ^= 1;
	else if (key == 'p')
		frtl->opt ^= 1 << 1;
	else if (key == 's')
		frtl->opt ^= 1 << 2;
	else if (key == 'a')
		frtl->opt ^= 1 << 3; 
	else if (key == 'r')
		default_win(frtl);
	else if (key == 'j' && frtl->child && !frtl->child->win)
		settings(frtl->child, frtl->mlx, frtl->set);
	else if (key == 'j' && frtl->child)
		win_close(frtl->child);
	else if (key == 'j')
		return (win_close(frtl));
	else
		return (0);
	return (px_iter(frtl));
}

int	keyboard(int key, t_data *frtl)
{
	if (key == ESC_K)
		exit(0);
	else if (key == RIGHT_K)
		frtl->head.offset.real += OFFSET * frtl->init.zoom \
		/ frtl->head.zoom;
	else if (key == LEFT_K)
		frtl->head.offset.real -= OFFSET * frtl->init.zoom \
		/ frtl->head.zoom;
	else if (key == UP_K)
		frtl->head.offset.imag += OFFSET * frtl->init.zoom \
		/ frtl->head.zoom;
	else if (key == DOWN_K)
		frtl->head.offset.imag -= OFFSET * frtl->init.zoom \
		/ frtl->head.zoom;
	else if (key == PLUS_K)
		frtl->head.itr += 20;
	else if (key == MINUS_K && frtl->head.itr > 20)
		frtl->head.itr -= 20;
	else if (key == N0_K || key == N1_K || key == N2_K)
		frtl->clr = key;
	else
		return (keyboard_plus(key, frtl));
	return (px_iter(frtl));
}

int	mouse(int key, int x, int y, t_data *frtl)
{
	coords(frtl, pxl(x, y));
	if (key == 4 || key == 5)
		zoom(frtl, key, pxl(x, y));
	else if (key == 1)
		frtl->cx_j = frtl->cx;
	if (key == 1 && frtl->child)
		frtl->child->cx_j = frtl->cx;
	printf("coords: [%Lf %Lf]	zoom: %ld iter: %ld\n", frtl->cx.real, frtl->cx.imag, frtl->head.zoom / PP_CM, frtl->head.itr);
	return (px_iter(frtl));
}
