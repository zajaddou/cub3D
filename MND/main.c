/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 13:57:22 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	logo(void)
{
	printf(BOLD CYAN);
	printf("   ______      __   _____ ____   \n");
	printf("  / ____/_  __/ /_ |__  // __ \\ \n");
	printf(" / /   / / / / __ \\ /_ </ / / / \n");
	printf("/ /___/ /_/ / /_/ /__/ / /_/ /   \n");
	printf("\\____/\\__,_/_.___/____/_____/  \n\n");
	printf(RESET);
}

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
	mlx_loop_hook(window_g()->mlx, render_frame, window_g());
	mlx_hook(window_g()->win, 3, 0, key_release_handle, window_g());
	mlx_hook(window_g()->win, 2, 0, key_press_handle, window_g());
	mlx_hook(window_g()->win, 17, 0, close_window, window_g());
	mlx_loop(window_g()->mlx);
	return (OK);
}
