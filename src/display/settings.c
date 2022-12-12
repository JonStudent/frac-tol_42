#include "../fractol.h"

void	default_win(t_data *frtl)
{
	if (!frtl->init.itr)
		frtl->init.itr = 64;
	if (!frtl->win_size.x || !frtl->win_size.y)
		frtl->win_size = pxl(WIDTH, HEIGHT);
	if (!frtl->init.zoom)
		frtl->init.zoom = PP_CM * (frtl->win_size.y / 350.0);
	if (!frtl->head.hsv)
		frtl->head.hsv = 359.99;
	frtl->head.itr = frtl->init.itr;
	frtl->head.zoom = frtl->init.zoom;
	frtl->head.offset = frtl->init.offset;
	frtl->mid_win = pxl(frtl->win_size.x / 2, frtl->win_size.y / 2);
}

int	win_close(t_data *frtl)
{
	if (frtl->mlx && frtl->img.img)
		mlx_destroy_image(frtl->mlx, frtl->img.img);
	if (frtl->mlx && frtl->win)
		mlx_destroy_window(frtl->mlx, frtl->win);
	frtl->win = 0;
	return (0);
}

void	handle_error(t_data *frtl, char *cause)
{
	if (!frtl->set)
		printf("Get ready for manual");
	if (cause)
		perror(cause);
	win_close(frtl);
	if (frtl->parent)
		win_close(frtl->parent);
	mlx_destroy_display(frtl->mlx);
	free(frtl->mlx);
	exit(0);
}

t_data *settings(t_data *frtl, void *mlx, void *set)
{
	default_win(frtl);
	frtl->mlx = mlx;
	frtl->set = set;
	if (frtl->set == mandelbrot)
		frtl->title = "Mandelbrot Set";
	else if (frtl->set == julia)
		frtl->title = "Julia Set";
	else if (frtl->set == burning_ship)
		frtl->title = "Burning_Ship Set";
	if (!frtl->mlx)
		handle_error(frtl, "mlx did't init--");
	init_win(frtl);
	return (frtl);
}
