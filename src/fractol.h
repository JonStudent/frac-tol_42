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

typedef struct s_sttgs {
	int	mx_itr;
	long double	zoom;
	long double x_offset;
	long double y_offset;
}	t_sttgs;

typedef struct s_n {
	int		px_x;
	int		px_y;
	long double	rl;
	long double	ig;
	long double	tmp;
}	t_n;

typedef struct s_img {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		lenght;
	int		endian;
}	t_img;

//Main  struct
typedef struct s_data {
	t_sttgs	sttgs;
	t_img	img;
	t_n		n;
}				t_data;

//  AUX Functions
int		set_coords(t_data *data);
void	color(int itr, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//  Sets Functions
int		mandelbrot(t_data *data, double i_rl, double i_ig, int itr);
void	pix_iter(t_data *data, int \
(*set)(t_data *data, double i_rl, double i_ig, int itr));

//	Debbug
int	circle(t_data *data, double i_rl, double i_ig, int itr);

#endif
