/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/31 15:51:26 by zajaddou         ###   ########.fr       */
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
    win->player.x = parsed_player->x;
    win->player.y = parsed_player->y;
    win->player.angle = parsed_player->angle;
	
}

int mouse_move_handle(int x, int y, t_window *win)
{
    int center_x = WIN_W / 2;
    int dx = x - center_x;

    double sensitivity = 0.002;
    win->player.angle += dx * sensitivity;
    angle_update(&win->player.angle);

    // Recenter mouse to middle after handling movement
    mlx_mouse_move(win->mlx, win->win, center_x, WIN_H / 2);

    return (0);
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
	init_animation();

	mlx_loop_hook(window_g()->mlx, render_frame, window_g());
	// mlx_key_hook(window_g()->win, key_press_handle, window_g());
	mlx_hook(window_g()->win, 3, (1L<<1), key_release_handle, window_g());
	mlx_hook(window_g()->win, 2, (1L<<1), key_press_handle, window_g());
	mlx_hook(window_g()->win, 2, (1L<<1), key_press_handle, window_g());
	
	mlx_loop(window_g()->mlx);

	return (OK);
}

