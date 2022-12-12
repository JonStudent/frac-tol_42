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

# define WIDTH 600
# define HEIGHT 600
# define PP_CM 86
# define OFFSET 0.5 
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

typedef struct s_px {
	int	y;
	int	x;
}	t_px;

typedef struct s_cx {
	long double	real;
	long double	imag;
}	t_cx;

typedef struct s_vol {
	long	itr;
	long	zoom;
	t_cx	offset;
	t_cx	cx_j;
}	t_vol;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		line_len;
	int		bits_per_pixel;
	int		endian;
	int		clr;
	char	opt;
	t_cx	hsv;
	t_px	mid_win;
	t_px	win_size;
}	t_img;

//Main  struct
typedef struct s_frtl	t_frtl;

struct s_frtl {
	t_frtl	*child;
	t_frtl	*parent;
	char	*title;
	void	*mlx;
	void	*win;
	t_cx	cx;
	t_px	px;
	t_img	img;
	t_vol	init;
	t_vol	curr;
	double	(*set)(t_frtl *frtl, t_cx cx, long itr);
};

//  Window Management Functions
int			win_close(t_frtl *frtl);
void		init_win(t_frtl *frtl);
void		default_win(t_frtl *frtl);
void		handle_error(t_frtl *frtl, char *cause);
void		pixel_to_img(t_frtl *frtl, t_px px, int color);
t_frtl		*settings(t_frtl *frtl_c, void *mlx, t_frtl *frtl_p);

//  Coords and Color Functions
int			px_iter(t_frtl *frtl);
t_cx		coords(t_frtl *frtl, t_px px);
void		color(double itr, t_frtl *frtl);
void		zoom(t_frtl *frtl, int key, t_px px);

// Input Handling Functions
long double	atod(const char *s);
int			keyboard(int key, t_frtl *frtl);
int			mouse(int key, int x, int y, t_frtl *frtl);
void		*get_param(t_frtl *frtl, int i, int c, char **v);

// Numeric Functions Functions
t_px		pxl(int a, int b);
t_cx		cmplx(long double a, long double b);
long double	ldabs(long double a);
double		d_mod(double a, int b);

// Set Functions
double		julia(t_frtl *frtl, t_cx cx, long itr);
double		mandelbrot(t_frtl *frtl, t_cx cx, long itr);
double		burning_ship(t_frtl *frtl, t_cx cx, long itr);

#endif
