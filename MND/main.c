/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/10 14:28:51 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	logo();
	if (ac != 2)
		error("Invalid input !");
	parsing(av[1]);
	init_window();
	init_textures();
	free_parsing();
	init_data();
	mlx_loop_hook(window_g()->mlx, render_frame, NULL);
	mlx_hook(window_g()->win, 3, 0, key_release_handle, NULL);
	mlx_hook(window_g()->win, 2, 0, key_press_handle, NULL);
	mlx_hook(window_g()->win, 17, 0, close_window, NULL);
	mlx_loop(window_g()->mlx);
	return (OK);
}
