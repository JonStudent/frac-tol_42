#include "../fractol.h"

static void	palette(t_data *data)
{
	data->sttgs.palette[0] = 0x0000001F;
	data->sttgs.palette[1] = 0x0000003F;
	data->sttgs.palette[2] = 0x00003FFF;
	data->sttgs.palette[3] = 0x00007FFF;
	data->sttgs.palette[4] = 0x0000BFFF;
	data->sttgs.palette[5] = 0x0000FFFF;
	data->sttgs.palette[6] = 0x0000FFBF;
	data->sttgs.palette[7] = 0x0000FF7F;
	data->sttgs.palette[8] = 0x0000FF3F;
	data->sttgs.palette[9] = 0x0000FF00;
	data->sttgs.palette[10] = 0x003FFF00;
	data->sttgs.palette[11] = 0x007FFF00;
	data->sttgs.palette[12] = 0x00BFFF00;
	data->sttgs.palette[13] = 0x00FFFF00;
	data->sttgs.palette[14] = 0x00FF3F00;
	data->sttgs.palette[15] = 0x00FF7F00;
	data->sttgs.palette[16] = 0x00FFBF00;
	data->sttgs.palette[17] = 0x00FF0000;
	data->sttgs.palette[18] = 0x00000000;
}

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
static void	get_param(t_data *data)
{
	data->cx_j.real = atod(data->arg.argv[2]);
	data->cx_j.imag = atod(data->arg.argv[3]);
	while (data->arg.argc-- > 2)
	{
		if (*data->arg.argv[data->arg.argc] == '-')
		{
			if (data->arg.argv[data->arg.argc][1] == 'w')
			{
				data->sttgs.win_size.x = (int)atod(data->arg.argv[data->arg.argc + 1]);
				data->sttgs.win_size.y = (int)atod(data->arg.argv[data->arg.argc + 2]);
			}
		}
	}
}

void	settings(t_data *data, int argc, char **argv)
{
	data->sttgs.mx_itr = 80;
	data->sttgs.zoom = CM * (data->sttgs.win_size.y / 200.0);
	data->sttgs.offset.real = 0.5;
	data->sttgs.offset.imag = 0;
	if (!argc)
		return ;
	data->arg.argc = argc;
	data->arg.argv = argv;
	if (*argv[1] == 'm' || *argv[1] == 'j')
		data->set = julia_mandelbrot;
	data->sttgs.set_flag = *argv[1];
	data->sttgs.win_size.x = WIDTH;
	data->sttgs.win_size.y = HEIGHT;
	data->cx_j.real = 0;
	data->cx_j.imag = -0.78;
	if (data->arg.argc > 3)
		get_param(data);
	data->sttgs.mid_win.x = data->sttgs.win_size.x / 2;
	data->sttgs.mid_win.y = data->sttgs.win_size.y / 2;
	data->sttgs.zoom = CM * (data->sttgs.win_size.y / 200.0);
	printf("zoom: %ld\n", data->sttgs.zoom);
	init_mlx(data);
	palette(data);
}
