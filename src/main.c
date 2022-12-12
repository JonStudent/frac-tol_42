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

// error handling
// window manegamnt

#include "fractol.h"

int	main(int argc, char **argv)
{
	static t_data	data;
	static t_data	data2;

	if (argc < 2 || !get_param(&data, 1, argc, argv))
		return (0);
	settings(&data);

	data.next_data = &data2;
	data2.mlx = data.mlx;
	data2.set = julia;

	px_iter(&data);
	
	// mlx_hook(data.img.win, 2, 1L<<0, keyboard, &data);
	mlx_loop(data.mlx);
}
