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
	static t_data	frtl;
	static t_data	child;

	if (argc < 2 || !get_param(&frtl, 1, argc, argv))
		handle_error(&frtl, NULL);
	frtl.child = &child;
	child.parent = &frtl;
	px_iter(settings(&frtl, mlx_init(), frtl.set));
	mlx_loop(frtl.mlx);
}
	// mlx_hook(frtl.win, 2, 1L<<0, keyboard, &frtl);
