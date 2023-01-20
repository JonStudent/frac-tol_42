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

#include "fractol.h"

int	main(int argc, char **argv)
{
	static t_frtl	parent;
	static t_frtl	child;

	if (argc < 2 || !get_param(&parent, argv))
		exit_win(&parent, "@");
	ft_printf(WLC"\n"INST);
	parent.child = &child;
	child.parent = &parent;
	create_win(&parent, mlx_init(), &parent);


	mlx_loop_hook(parent.mlx, wait, &parent);
	mlx_loop(parent.mlx);
}
