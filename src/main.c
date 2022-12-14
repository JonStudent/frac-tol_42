/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasilio <jbasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:52:25 by jbasilio          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:27 by jbasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// review perror
// window manegamnt
// Funky colors (modulos and powers)

#include "fractol.h"

int	main(int argc, char **argv)
{
	static t_frtl	parent;
	static t_frtl	child;

	if (argc < 2 || !get_param(&parent, 1, argc, argv))
		handle_error(&parent, NULL);
	parent.child = &child;
	child.parent = &parent;
	px_iter(settings(&parent, mlx_init(), &parent));
	mlx_loop(parent.mlx);
}
	// mlx_hook(parent.win, 2, 1L<<0, keyboard, &parent);
