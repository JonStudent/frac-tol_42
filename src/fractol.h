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
# define HEIGHT 600

# define PP_CM 86

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
	double	real;
	double	imag;
}	t_cx;

typedef struct s_px {
	int		y;
	int		x;
}	t_px;

typedef struct s_n {
	t_cx	cx_j;
	t_cx	cx;
	t_px	px;
}	t_n;

typedef struct s_sttgs {
	int			opt;
	long int	zoom;
	int			mx_itr;
	int			init_mx_itr;
	t_cx		offset;
	t_px		mid_win;
	t_px		win_size;
}	t_sttgs;

typedef struct s_img {
	void		*img;
	char		*addr;
	int			lenght;
	int			line_len;
	int			bits_per_pixel;
	int			endian;
}	t_img;

//Main  struct
typedef struct s_data t_data;

struct s_data {
	void	*mlx;
	void	*win;
	t_n		n;
	t_img	img;
	t_sttgs	sttgs;
	double	(*set)(t_data *data, t_cx cx, int itr);
};

// Sets
double	julia(t_data *data, t_cx cx, int itr);
double	mandelbrot(t_data *data, t_cx cx, int itr);
double	burning_ship(t_data *data, t_cx cx, int itr);

//  Window Management
void	init_win(t_data *data);
void	settings(t_data *data);
void	win_default(t_sttgs *sttgs, char force);
void	my_mlx_pixel_put(t_data *data, t_px px, int color);

//  Coords and color
int		px_iter(t_data *data);
t_cx	coords(t_data *data, t_px px);
void	color(double itr, t_data *data);
void	zoom(t_data *data, int key, t_px px);

// Input Handling
long double	atod(const char *s);
int			keyboard(int	key, t_data *data);
int			mouse(int key, int x, int y, t_data *data);
void		*get_param(t_data *data, int i, int argc, char **argv);

// Calculus
t_px	pxl(int a, int b);
t_cx	cmplx(double a, double b);
#endif
