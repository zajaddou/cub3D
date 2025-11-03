/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/03 11:01:37 by mgarouj          ###   ########.fr       */
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


void init_textures()
{
	t_window *win = window_g();
	
	win->tex_data[0].img = mlx_xpm_file_to_image(win->mlx, "./textures/1.xpm", &win->tex_data[0].width, &win->tex_data[0].height);
	win->tex_data[1].img = mlx_xpm_file_to_image(win->mlx, "./textures/2.xpm", &win->tex_data[1].width, &win->tex_data[1].height);
	win->tex_data[2].img = mlx_xpm_file_to_image(win->mlx, "./textures/3.xpm", &win->tex_data[2].width, &win->tex_data[2].height);
	win->tex_data[3].img = mlx_xpm_file_to_image(win->mlx, "./textures/4.xpm", &win->tex_data[3].width, &win->tex_data[3].height);
	if (!win->tex_data[0].img || !win->tex_data[1].img || !win->tex_data[2].img || !win->tex_data[3].img)
	{
		printf("eroooooooor in mlx ______________________________ file to xpm \n");
		return ;
	}
	win->tex_data[0].addr = mlx_get_data_addr(win->tex_data[0].img, &win->tex_data[0].bits_per_pixel, &win->tex_data[0].line_lenght, &win->tex_data[0].endian);
	win->tex_data[1].addr = mlx_get_data_addr(win->tex_data[1].img, &win->tex_data[1].bits_per_pixel, &win->tex_data[1].line_lenght, &win->tex_data[1].endian);
	win->tex_data[2].addr = mlx_get_data_addr(win->tex_data[2].img, &win->tex_data[2].bits_per_pixel, &win->tex_data[2].line_lenght, &win->tex_data[2].endian);
	win->tex_data[3].addr = mlx_get_data_addr(win->tex_data[3].img, &win->tex_data[3].bits_per_pixel, &win->tex_data[3].line_lenght, &win->tex_data[3].endian);
	if (!win->tex_data[0].addr || !win->tex_data[1].addr || !win->tex_data[2].addr || !win->tex_data[3].addr)
	{
		printf("eroooooooor in mlx ______________________________ get_data address \n");
		return ;
	}
}

int	main(int ac, char **av)
{
	logo();
	
	if (ac != 2)
		return (error("Invalid input !"), 1);

	if (parse_input(av[1]))
		return (ERR);

	init_window();
	init_textures();
	init_data();



	printf("here \n");
	mlx_loop_hook(window_g()->mlx, render_frame, window_g());
	mlx_hook(window_g()->win, 3, (1L<<1), key_release_handle, window_g());
	mlx_hook(window_g()->win, 2, (1L<<1), key_press_handle, window_g());
	
	mlx_loop(window_g()->mlx);

	return (OK);
}

