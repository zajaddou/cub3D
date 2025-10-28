/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/27 20:31:48 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void init_data()
{
	t_window    *win;
    t_player    *parsed_player;
    t_map       *parsed_map;

    win = window_g();
    parsed_player = player_g();
    parsed_map = map_g();

    // Copy player data
    // We add 0.5 to start the player in the *middle* of their tile
    // And multiply by TILE to convert from grid units to pixel units
    win->player.x = parsed_player->x;
    win->player.y = parsed_player->y;
    win->player.angle = parsed_player->angle;
	
}

int	main(int ac, char **av)
{
	logo();
	
	if (ac != 2)
		return (error("Invalid input !"), 1);

	if (parse_input(av[1]))
		return (ERR);

	init_window();

	init_data();
	printf("player = \n x = %f \n y = %f \n angle = %f \n  %f \n", window_g()->player.x, window_g()->player.y, window_g()->player.angle, 3 * M_PI/2);
	mlx_loop_hook(window_g()->mlx, render_frame, window_g());
	mlx_key_hook(window_g()->win, key_press_handle, window_g());
	mlx_hook(window_g()->win, 3, (1L<<1), key_release_handle, window_g());
	
	mlx_loop(window_g()->mlx);

	return (OK);
}