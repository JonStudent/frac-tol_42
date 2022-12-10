#include "../fractol.h"

long double	atod(const char *s)
{
	long double	i;
	long double	n;

	i = 1.0;
	n = 0.0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' && s++)
		i = -1;
	while (*s >= '0' && *s <= '9')
		n = (n * 10) + i * (*s++ - '0');
	while (*s++ == '.' || (*s >= '0' && *s <= '9'))
	{
		i *= 0.1;
		n += i * (*s - '0');
	}
	return (n);
}

char	get_param(t_data *data, int i, int argc, char **argv)
{
	if (argv[i][0] == 'j')
	{
		if (argv[i][0] == 'j' && i + 2 < argc)
			data->n.cx_j = cmplx(atod(argv[i + 1]), atod(argv[i + 2]));
		data->set = julia;
	}
	else if (argv[i][0] == 'm')
		data->set = julia;
	else if (argv[i][0] == 'b')
		data->set = burning_ship;
	else if (argv[i][0] == '-')
	{
		if (argv[i][1] == 'w')
			data->sttgs.win_size = pxl(atod(argv[i + 1]), atod(argv[i + 2]));
	}
	if (++i < argc)
		get_param(data, i, argc, argv);
	return (data->set);
}

static int	keyboard_plus(int key, t_data *data)
{
	if (key == PLUS_K)
		data->sttgs.mx_itr += 5;
	else if (key == MINUS_K && data->sttgs.mx_itr > 5)
		data->sttgs.mx_itr -= 5;
	else if (key == N0_K)
		data->sttgs.opt |= (char)0;
	else if (key == N1_K)
		data->sttgs.opt |= (char)1;
	else if (key == N2_K)
		data->sttgs.opt |= (char)2;
	else if (key == 'i')
		data->sttgs.opt ^= 1 << 8;
	else
		return (0);
	ft_printf("max_iter: %d, key: %d\n", data->sttgs.mx_itr, key);
	return (px_iter(data));
}

int	keyboard(int key, t_data *data)
{
	if (key == ESC_K)
		exit(0);
	else if (key == 'd' || key == RIGHT_K)
		data->sttgs.offset.real -= 34.4 / data->sttgs.zoom;
	else if (key == 'a' || key == LEFT_K)
		data->sttgs.offset.real += 34.4 / data->sttgs.zoom;
	else if (key == 'w' || key == UP_K)
		data->sttgs.offset.imag -= 34.4 / data->sttgs.zoom;
	else if (key == 's' || key == DOWN_K)
		data->sttgs.offset.imag += 34.4 / data->sttgs.zoom;
	else if (key == 'r')
		win_default(&data->sttgs);
	else
		return (keyboard_plus(key, data));
	return (px_iter(data));
}

int	mouse(int key, int x, int y, t_data *data)
{
	coords(data, pxl(x, y));
	if (key == 4 || key == 5)
		zoom(data, key, pxl(x, y));
	else if (key == 1)
		data->n.cx_j = data->n.cx;
	printf("zoom: %ld\n", data->sttgs.zoom / PP_CM);
	return (px_iter(data));
}
