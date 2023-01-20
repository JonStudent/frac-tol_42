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
# define MOVE 0.5

# define ESC_K 65307
# define RIGHT_K 65363
# define LEFT_K 65361
# define UP_K 65362
# define DOWN_K 65364
# define PLUS_K 65451
# define MINUS_K 65453
# define N0_K 65438
# define N1_K 65436
# define N2_K 65433

# define GN	"\x1B[32m"
# define YL	"\x1B[33m"
# define MG	"\x1B[35m"
# define BL	"\x1B[34m"
# define CY	"\x1B[36m"
# define RD "\x1B[31m"
# define RT	"\x1B[0m"

# define WLC "\n\n\n\t\t\t\x1B[36mFract-ol Manual\x1B[0m\n\n\
\tWelcome to my little fractals exploratian program!\x1B[34m\n\n"

# define BYE "\x1B[36m\n\n\n\t\t\tBye, hope you enjoyed it\x1B[0m :)\n\n"

# define TOBIG "N/A - (reached long size number)"

# define MAN "SYNOPSIS\x1B[0m\n\n\t./frac-tol \x1B[32m<FRACTAL>\
\x1B[0m \x1B[33m[OPTIONS]...\x1B[0m\x1B[34m\n\n\
DESCRIPTION\x1B[0m\n\nAll the \x1B[32m<\x1B[0m...\x1B[32m>\
\x1B[0m selections are \x1B[31mREQUIRED\n\x1B[0mand all \x1B[33m[\x1B[0m...\
\x1B[33m]\x1B[0m are \x1B[33mOPTIONAL\x1B[0m\n\n\n\t\x1B[32mFRACTAL\x1B[0m\n\
\t(case \x1B[32minsensitive\x1B[0m)\n\n\
\t\x1B[32mm\x1B[0m, Mandelbrot\t\tGenerate Mandelbrot Set.\n\
\t\x1B[32mj\x1B[0m, Julia \x1B[33m[\x1B[0mreal, imag\x1B[33m]\x1B[0m\
\tGenerate Julia Set.\n\
\t\t\t\tIf an optional complex number is given, the Julia Set\n\
\t\t\t\twill be calculated using it as it's fixed point.\n\
\t\x1B[32mb\x1B[0m, BurningShip\t\tGenerate Burning Ship Set.\n\n\n\
\t\x1B[33mOPTIONS\x1B[0m\n\
\t(case \x1B[31msensitive\x1B[0m)\n\n\
\t-\x1B[33mz\x1B[0m \x1B[32m<\x1B[0minitial zoom\x1B[32m>\x1B[0m\
\tSelect initial zoom to be rendered.\n\
\t-\x1B[33mo\x1B[0m \x1B[32m<\x1B[0mreal\x1B[32m>\x1B[0m \x1B[32m<\x1B[0mimag\
\x1B[32m>\x1B[0m\tSelect origin Point. \
Set will be centered at that coordinate.\n\
\t\t\t\t(Complex numbers act as coordinates in the complex plane)\n\
\t-\x1B[33mi\x1B[0m \x1B[32m<\x1B[0mmax iteration\x1B[32m>\x1B[0m\
\tSelect starting Max Iteration.\n\
\t\t\t\t(Maximum number of times the different equations will run,\n\
\t\t\t\tif not escaping to infinity).\n\
\t-\x1B[33mw\x1B[0m \x1B[32m<\x1B[0mWITDH\x1B[32m>\x1B[0m \
\x1B[32m<\x1B[0mHEIGHT\x1B[32m>\x1B[0m\tSelect Window Size.\n\
\t-\x1B[33mc\x1B[0m \x1B[32m<\x1B[0mbegin\x1B[32m>\x1B[0m \
\x1B[32m<\x1B[0mend\x1B[32m>\x1B[0m\tSelect color spectrum.\n\
\t\t\t\tUse two HSV values (from 0 to 360) to select a color range.\n\n"

# define INST "\x1B[34mINSTRUCTIONS\x1B[0m\n\n\
Use both \x1B[32mKeyboard\x1B[0m and \x1B[31mMouse\x1B[0m\n\
to control exploration:\n\n\
\t\x1B[32mKEYBOARD\x1B[0m\n\n\
\t\t-\x1B[34mArrows\x1B[0m\t\tMove 0.5cm proportional to zoom.\n\
\t\t-\x1B[34m+\x1B[0m\t\tIncrease MaxIteration by 20%%.\n\
\t\t-\x1B[34m-\x1B[0m\t\tDecrease MaxIteration by 20%%.\n\
\t\t-\x1B[34ms\x1B[0m\t\tToggle Safety \
(allow multiple commands between frames).\n\
\t\t-\x1B[34ma\x1B[0m\t\tToggle Auto Mode - \
Tries to adjust Max_Iterations at each zoom\n\
\t\t-\x1B[34m0\x1B[0m, \x1B[34m1\x1B[0m\t\tSelect coloring Method.\n\
\t\t-\x1B[34mi\x1B[0m\t\tInvert color spectrum.\n\
\t\t-\x1B[34mo\x1B[0m\t\tOscillate colors.\n\
\t\t-\x1B[34mu\x1B[0m\t\tCompress colors(square-root of the linear mapping).\n\
\t\t-\x1B[34my\x1B[0m\t\tSpread colors(square of the linear mapping).\n\
\t\t-\x1B[34mj\x1B[0m\t\tToggle Julia window for corresponding set.\n\
\t\t\t\t(New window maintains all functionalities).\n\
\t\t-\x1B[34mr\x1B[0m\t\tRestart window.\n\
\t\t-\x1B[34mESC\x1B[0m\t\tClose windows and exit program.\n\
\n\t\x1B[31mMOUSE\x1B[0m\n\n\
\t\t\x1B[34mLeft-Click\x1B[0m\tSend selected point to Julia window\n\
\t\t\t\t(Continuous press Supporded).\n\
\t\t\x1B[34mRight-Click\x1B[0m\tCenter window on selected point.\n\
\t\t\x1B[34mWheel\x1B[0m\t\tZoom in/out at mouse position.\n\
\t\t\x1B[34mMiddle-Click\x1B[0m\tSee statistics for selected point.\n\
\x1B[36m\n\t\t\tGo get it !!\x1B[0m\n\n"

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
	double	hsv_dif;
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
	t_px	w_cntr;
	t_px	w_size;
	t_cx	cx;
	t_px	px;
	t_img	img;
	t_val	init;
	t_val	live;
	char	opt;
	char	lock;
	double	(*set)(t_frtl *f, t_cx cx, long itr);
};

// Input Handling Functions
int			keyboard(int key, t_frtl *f);
int			keyboard_plus(int key, t_frtl *f);
int			mouse_press(int key, int x, int y, t_frtl *f);
int			wait(t_frtl *f);
int			dance(int x, int y, t_frtl *f);
int			expose(t_frtl *f);

// Set Functions
double		julia(t_frtl *f, t_cx cx, long itr);
double		mandelbrot(t_frtl *f, t_cx cx, long itr);
double		burning_ship(t_frtl *f, t_cx cx, long itr);

//  Coords and Color Functions
int			fill_win(t_frtl *f);
int			mouse_release(int key, int x, int y, t_frtl *f);
void		color(long itr, t_frtl *f);
t_cx		zoom(t_frtl *f, int key, t_px px);
t_cx		coords(t_frtl *f, t_px px);

// Numeric Functions Functions
t_px		pxl(int a, int b);
t_cx		cmplx(long double a, long double b);
long double	atod(const char *s);

//  Window Management Functions
int			stats(t_frtl *f, char s);
int			win_close(t_frtl *f);
void		child_win(t_frtl *f);
void		init_win(t_frtl *f);
void		default_win(t_frtl *f);
void		exit_win(t_frtl *f, char *cause);
void		pixel_to_img(t_frtl *f, t_px px, int color);
void		create_win(t_frtl *frtl_c, void *mlx, t_frtl *frtl_p);
void		*get_param(t_frtl *f, int i, int c, char **v);
#endif
