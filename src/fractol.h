/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:52:13 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:16 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1600
# define HEIGHT 900

//Pixels in one Centimeter
# define CM 86
# define ESC_K 65307

typedef struct s_sttgs {
	int			mx_itr;
	int			x_cntr;
	int			y_cntr;
	long int	zoom;
	long double x_offset;
	long double y_offset;
}	t_sttgs;

typedef struct s_cpx {
	long double	real;
	long double	imag;
}	t_cpx;

typedef struct s_n {
	int			px_x;
	int			px_y;
	t_cpx		cpx;
	long double	tmp;
}	t_n;

typedef struct s_img {
	int			bits_per_pixel;
	int			line_len;
	int			lenght;
	int			endian;
	char		*addr;
	void		*mlx;
	void		*win;
	void		*img;
}	t_img;

//Main  struct
typedef struct s_data t_data;

struct s_data {
	t_n		n;
	t_img	img;
	t_sttgs	sttgs;
	int		(*set)(t_data *data, t_cpx cpx, int itr);
};

//  AUX Functions
t_cpx		set_coords(t_data *data, int x, int y);
void	color(int itr, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    *settings(t_data *data, char *set);

//  Sets Functions
int		mandelbrot(t_data *data, t_cpx cpx, int itr);
void	create(t_data *data);

//	Debbug
int	circle(t_data *data, t_cpx cpx, int itr);

#endif
