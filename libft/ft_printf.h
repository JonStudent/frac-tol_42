/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:12:21 by jbasilio          #+#    #+#             */
/*   Updated: 2022/07/27 22:26:33 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define A_I "dic"
# define A_U "uxX"
# define A_H "pxX"
# define A_N "pdiuxX"
# define A_Z "diuxX"
# define A_T "cspdiuxX%"

typedef struct s_format
{
	char			cv;
	int				hs;
	int				sc;
	int				pl;
	int				mn;
	int				zr;
	int				pc;
	int				wd;
	int				bs;
	int				ng;
	int				c;
	int				xz;
	int				xw;
	unsigned long	dc;
	unsigned long	n;
	unsigned long	t;
	char			*hss;
	char			*dgs;
	char			*nl;
	char			*nlp;
}	t_format;
int	ft_printf(const char *s, ...);
#endif
