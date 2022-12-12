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

int	win_close(t_data *frtl)
{
	if (frtl->mlx && frtl->img.img)
		mlx_destroy_image(frtl->mlx, frtl->img.img);
	frtl->img.img = 0;
	if (frtl->mlx && frtl->win)
		mlx_destroy_window(frtl->mlx, frtl->win);
	frtl->win = 0;
	return (0);
}

void	handle_error(t_data *frtl, char *cause)
{
	printf("Error handler called\n");
	if (!frtl->set)
		printf("Get ready for manual\n");
	if (cause)
		perror(cause);
	win_close(frtl);
	if (frtl->parent)
		win_close(frtl->parent);
	if (frtl->child)
		win_close(frtl->child);
	mlx_destroy_display(frtl->mlx);
	free(frtl->mlx);
	exit(0);
}

void	default_win(t_data *frtl)
{
	if (!frtl->init.itr)
		frtl->init.itr = 64;
	if (!frtl->win_size.x || !frtl->win_size.y)
		frtl->win_size = pxl(WIDTH, HEIGHT);
	if (!frtl->init.zoom)
		frtl->init.zoom = PP_CM * (frtl->win_size.y / 350.0);
	if (!frtl->hsv.imag)
		frtl->hsv.imag = 359.99;
	frtl->head.itr = frtl->init.itr;
	frtl->head.zoom = frtl->init.zoom;
	frtl->head.offset = frtl->init.offset;
	frtl->mid_win = pxl(frtl->win_size.x / 2, frtl->win_size.y / 2);
}

t_data	*settings(t_data *frtl, void *mlx, void *set)
{
	default_win(frtl);
	frtl->mlx = mlx;
	if (!frtl->mlx)
		handle_error(frtl, "mlx did't init--");
	frtl->set = set;
	if (frtl->set == mandelbrot)
		frtl->title = "Mandelbrot Set";
	else if (frtl->set == julia)
		frtl->title = "Julia Set";
	else if (frtl->set == burning_ship)
		frtl->title = "Burning_Ship Set";
	init_win(frtl);
	return (frtl);
}
