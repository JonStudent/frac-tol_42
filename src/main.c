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
// help colors

#include "fractol.h"

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc < 2 || !get_param(&data, 1, argc, argv))
		return (0);
	settings(&data);
	px_iter(&data);
	
	// mlx_hook(data.img.win, 2, 1L<<0, keyboard, &data);

	mlx_loop(data.mlx);
}
