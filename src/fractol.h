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

# define GN	"\x1B[32m"
# define YL	"\x1B[33m"
# define BL	"\x1B[34m"
# define MG	"\x1B[35m"
# define CY	"\x1B[36m"
# define RD "\x1B[31m"
# define RT	"\x1B[0m"

# define TOBIG "too big for ft_printf (reached long size number)"
# define MAN CY"\n\t\tFract-ol Manual"RT\
			 "\n\n\tWelcome to my little fractals exploratian program!"\
			 BL"\n\nSYNOPSIS"RT"\n\n\t./frac-tol "GN"<FRACTAL>"RT" "YL"[OPTIONS]..."RT\
			 BL"\n\nDESCRIPTION"RT"\n\nAll the "GN"<"RT"..."GN">"RT" selections are "\
			 RD"REQUIRED\n"RT"and all "YL"["RT"..."YL"]"RT" are "YL"OPTIONAL"RT\
			 "\n\n\t"GN"FRACTAL"RT":"\
			 "\n\t("RD"not"RT" case sensitive)"\
			 "\n\n\t "GN"m"RT", Mandelbrot\t\t Generate Mandelbrot Set."\
			 "\n\n\t "GN"j"RT", Julia "YL"["RT"real, imag"YL"]"RT"\t Generate Julia Set."\
			 "\n\t\t\t\t If an optional complex number is given, the Julia Set"\
			 "\n\t\t\t\t will be calculated using it as it's fixed point."\
			 "\n\n\t "GN"b"RT", BurningShip\t\t Generate Burning Ship Set."\
			 "\n\n\t"YL"OPTIONS"RT":"\
			 "\n\t(case sensitive)"\
			 "\n\n\t-"YL"z"RT" "GN"<"RT"initial zoom"GN">"RT\
			 "\t Select initial zoom to be rendered."\
			 "\n\n\t-"YL"o"RT" "GN"<"RT"real"GN">"RT" "GN"<"RT"imag"GN">"RT\
			 "\t Select origin Point. Set will be centered at that coordinate."\
			 "\n\t\t\t\t (Complex numbers act as coordinates in the complex plane)"\
			 "\n\n\t-"YL"i"RT" "GN"<"RT"max iteration"GN">"RT\
			 "\t Select starting Max Iteration."\
			 "\n\t\t\t\t (Maximum number of times the different equations will run,"\
			 "\n\t\t\t\t if not escaping to infinity).\n"\
			 "\n\n\t-"YL"w"RT" "GN"<"RT"WITDH"GN">"RT" "GN"<"RT"HEIGHT"GN">"RT\
			 "\t Select Window Size.\n"

typedef struct s_px {
	int	x;
	int	y;
}	t_px;

typedef struct s_cx {
	long double	real;
	long double	imag;
}	t_cx;

typedef struct s_val {
	long	itr;
	long	zoom;
	t_cx	offset;
	t_cx	cx_j;
}	t_val;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		line_len;
	int		bits_per_pixel;
	int		endian;
	int		clr;
	t_cx	hsv;
}	t_img;

//Main  struct
typedef struct s_frtl	t_frtl;

struct s_frtl {
	t_frtl	*child;
	t_frtl	*parent;
	char	*title;
	void	*mlx;
	void	*win;
	char	lock;
	char	opt;
	t_cx	cx;
	t_px	px;
	t_img	img;
	t_val	init;
	t_val	live;
	t_px	w_cntr;
	t_px	w_size;
	double	(*set)(t_frtl *f, t_cx cx, long itr);
};

// Input Handling Functions
int			keyboard(int key, t_frtl *f);
int			keyboard_plus(int key, t_frtl *f);
int			mouse(int key, int x, int y, t_frtl *f);
int			wait(t_frtl *f);
int			dance(int x, int y, t_frtl *f);
int			expose(t_frtl *f);

// Set Functions
double		julia(t_frtl *f, t_cx cx, long itr);
double		mandelbrot(t_frtl *f, t_cx cx, long itr);
double		burning_ship(t_frtl *f, t_cx cx, long itr);

//  Coords and Color Functions
int			fill_win(t_frtl *f);
int			move(t_frtl *f, int key, t_px px);
void		color(double itr, t_frtl *f);
t_cx		zoom(t_frtl *f, int key, t_px px);
t_cx		coords(t_frtl *f, t_px px);

// Numeric Functions Functions
t_px		pxl(int a, int b);
t_cx		cmplx(long double a, long double b);
long double	atod(const char *s);

//  Window Management Functions
int			stats(t_frtl *f, char s);
int			win_close(t_frtl *f);
int			child_win(t_frtl *f);
void		init_win(t_frtl *f);
void		default_win(t_frtl *f);
void		handle_error(t_frtl *f, char *cause);
void		pixel_to_img(t_frtl *f, t_px px, int color);
void		create_win(t_frtl *frtl_c, void *mlx, t_frtl *frtl_p);
void		*get_param(t_frtl *f, int i, int c, char **v);
#endif
