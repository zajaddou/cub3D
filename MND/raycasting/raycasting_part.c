/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:18:53 by mgarouj           #+#    #+#             */
/*   Updated: 2025/11/09 13:41:29 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_wall(double x, double y)
{
	t_map	*map;
	int		map_x;
	int		map_y;

	map = map_g();
	if (!map || !map->map)
		return (1);
	map_x = (int)(x / TILE);
	map_y = (int)(y / TILE);
	if (map_x < 0 || map_x >= map->w || map_y < 0 || map_y >= map->h)
		return (1);
	if (map->map[map_y] && (int) ft_strlen(map->map[map_y]) > map_x)
		if (map->map[map_y][map_x] == '1')
			return (1);
	return (0);
}

void	update_cast(t_window *win, double ray_angle, int id)
{
	angle_update(&ray_angle);
	win->rays[id].ray_angle = ray_angle;
	win->is_hor_wall = 0;
	win->is_ver_wall = 0;
	win->rays[id].facing_down = ray_angle > 0 && ray_angle < M_PI;
	win->rays[id].facing_up = !win->rays[id].facing_down;
	win->rays[id].facing_right = ray_angle < 0.5 * M_PI
		||ray_angle > 1.5 * M_PI;
	win->rays[id].facing_left = !win->rays[id].facing_right;
	is_hor_ray(win, ray_angle, id);
	is_ver_ray(win, ray_angle, id);
}

void	cast_ray(t_window *win, double ray_angle, int id)
{
	update_cast(win, ray_angle, id);
	if (win->ver_distace < win->hor_distace)
	{
		win->rays[id].distance = win->ver_distace;
		win->rays[id].wall_hit_x = win->ray_x;
		win->rays[id].wall_hit_y = win->hit_ver_y;
		win->rays[id].hit_vertical = 1;
	}
	else
	{
		win->rays[id].distance = win->hor_distace;
		win->rays[id].wall_hit_x = win->hit_hor_x;
		win->rays[id].wall_hit_y = win->ray_y;
		win->rays[id].hit_vertical = 0;
	}
}

void	cast_all_rays(t_window *win)
{
	double	ray_angle;
	int		i;

	i = 0;
	ray_angle = win->player.angle - (FOV / 2);
	while (i < NUM_RAYS)
	{
		cast_ray(win, ray_angle, i);
		ray_angle += FOV / NUM_RAYS;
		i++;
	}
}

int	render_frame(void)
{
	t_window	*win;

	win = window_g();
	update_player(win);
	render_background(win);
	cast_all_rays(win);
	draw_textures(win, 0, ((double)WIN_W) / (2.0 * tan(FOV / 2.0)));
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	return (0);
}
