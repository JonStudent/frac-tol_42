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
	static t_data	data;

	if (argc < 2)
		return (0);
	settings(&data, argv[1]);
	create(&data);
	
	// mlx_hook(data.img.win, 2, 1L<<0, keyboard, &data);
	mlx_key_hook(data.img.win, keyboard, &data);
	mlx_mouse_hook(data.img.win, mouse, &data);

	mlx_loop(data.img.mlx);
}
