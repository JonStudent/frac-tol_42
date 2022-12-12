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

// I could add one more set...

// error handling and check
// window manegamnt

#include "fractol.h"

int	main(int argc, char **argv)
{
	static t_data	data;
	static t_data	data2;

	if (argc < 2 || !get_param(&data, 1, argc, argv))
		return (0);
	data.n_data = &data2;
	px_iter(settings(&data, mlx_init(), data.set));
	
	// mlx_hook(data.img.win, 2, 1L<<0, keyboard, &data);
	mlx_loop(data.mlx);
}
