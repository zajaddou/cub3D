/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:39:46 by mgarouj           #+#    #+#             */
/*   Updated: 2025/11/07 10:44:08 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_player(t_window *win, double rot_speed)
{
	win->player.angle += rot_speed;
	angle_update(&win->player.angle);
}

void	angle_update(double *ray_angle)
{
	*ray_angle = fmod(*ray_angle, 2 * M_PI);
	if (*ray_angle < 0)
		*ray_angle += 2 * M_PI;
}

void	init_window(void)
{
	t_window	*win;

	win = window_g();
	win->mlx = mlx_init();
	if (!win->mlx)
		error("mlx_init failed");
	win->win = mlx_new_window(win->mlx, WIN_W, WIN_H, "Cub3D");
	if (!win->win)
		error("mlx_new_window failed");
	win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
	if (!win->img)
		error("mlx_new_image failed");
	win->addr = mlx_get_data_addr(win->img,
			&win->bpp, &win->line_len, &win->endian);
	if (!win->addr)
		error("mlx_get_data_addr failed");
}

void	init_textures(void)
{
	t_window	*win;

	win = window_g();
	load_textures();
	win->textures[0].addr = mlx_get_data_addr(win->textures[0].img,
			&win->textures[0].bits_per_pixel, &win->textures[0].line_lenght,
			&win->textures[0].endian);
	win->textures[1].addr = mlx_get_data_addr(win->textures[1].img,
			&win->textures[1].bits_per_pixel, &win->textures[1].line_lenght,
			&win->textures[1].endian);
	win->textures[2].addr = mlx_get_data_addr(win->textures[2].img,
			&win->textures[2].bits_per_pixel, &win->textures[2].line_lenght,
			&win->textures[2].endian);
	win->textures[3].addr = mlx_get_data_addr(win->textures[3].img,
			&win->textures[3].bits_per_pixel, &win->textures[3].line_lenght,
			&win->textures[3].endian);
	if (!win->textures[0].addr || !win->textures[1].addr
		|| !win->textures[2].addr || !win->textures[3].addr)
		error(" mlx -> get_data address \n");
}

void	init_data(void)
{
	t_window	*win;
	t_player	*parsed_player;
	t_map		*parsed_map;

	win = window_g();
	parsed_player = player_g();
	parsed_map = map_g();
	win->player.x = parsed_player->x;
	win->player.y = parsed_player->y;
	win->player.angle = parsed_player->angle;
}
