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
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1600
# define HEIGHT 1000

//Pixels in one Centimeter
# define CM 86

# define RIGHT_K 65363
# define LEFT_K 65361
# define UP_K 65362
# define DOWN_K 65364

# define ESC_K 65307
# define PLUS_K 65451
# define MINUS_K 65453

# define N0_K 65438
# define N1_K 65436
# define N2_K 65433

typedef struct s_cx {
	long double	real;
	long double	imag;
	long double tmp;
}	t_cx;

typedef struct s_px {
	int		y;
	int		x;
}	t_px;

typedef struct s_sttgs {
	int			pltt;
	int			opt;
	int			palette[19];
	int			mx_itr;
	int			ini_mx_itr;
	long int	zoom;
	t_cx		offset;
	t_px		mid_win;
}	t_sttgs;

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
	t_cx	cx;
	t_px	px;
	t_cx	i_cx;
	t_cx	tmp;
	t_img	img;
	t_sttgs	sttgs;
	char	set_flag;
	double		(*set)(t_data *data, t_cx cx, int itr);
};

//  AUX Functions
t_cx	coords(t_data *data, int x, int y);
void	color(double itr, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    settings(t_data *data, char *set);
int		keyboard(int	key, t_data *data);
int		mouse(int key, int x, int y, t_data *data);
void	init_mlx(t_data *data);

//  Sets Functions
double		julia_mandelbrot(t_data *data, t_cx cx, int itr);
int			px_iter(t_data *data);

//	Debbug
double	circle(t_data *data, t_cx cx, int itr);

#endif
