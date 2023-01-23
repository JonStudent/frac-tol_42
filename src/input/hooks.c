/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:53:33 by jbasilio          #+#    #+#             */
/*   Updated: 2022/12/12 21:53:34 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	expose(t_frtl *f)
{
	return (!++f->lock);
}

int	bridge(int x, int y, t_frtl *f)
{
	return (mouse_press(1, x, y, f));
}

int	wait(t_frtl *f)
{
	if (f->lock)
		fill_win(f);
	if (f->child->lock)
		fill_win(f->child);
	f->lock = 0;
	f->child->lock = 0;
	return (0);
}
