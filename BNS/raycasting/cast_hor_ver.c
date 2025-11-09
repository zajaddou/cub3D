/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_hor_ver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:29:03 by mgarouj           #+#    #+#             */
/*   Updated: 2025/10/31 08:31:14 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	calc_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	init_ver_data(t_window *win, double ray_angle, int id)
{
	win->ver_distace = INFINITY;
	win->is_ver_wall = 0;
	win->ray_x = floor(win->player.x / TILE) * TILE;
	if (win->rays[id].facing_right)
		win->ray_x += TILE;
	win->ray_y = win->player.y + ((win->ray_x - win->player.x)
			* tan(ray_angle));
	win->step_x = TILE;
	if (win->rays[id].facing_left)
		win->step_x *= -1;
	win->step_y = TILE * tan(ray_angle);
	if (win->rays[id].facing_up && win->step_y > 0)
		win->step_y *= -1;
	if (win->rays[id].facing_down && win->step_y < 0)
		win->step_y *= -1;
	if (win->rays[id].facing_left)
		win->ray_x -= 0.01;
}

void	is_ver_ray(t_window *win, double ray_angle, int id)
{
	init_ver_data(win, ray_angle, id);
	while (!has_wall(win->ray_x, win->ray_y))
	{
		win->ray_x += win->step_x;
		win->ray_y += win->step_y;
	}
	win->ver_distace = calc_distance(win->player.x,
			win->player.y, win->ray_x, win->ray_y);
	win->hit_ver_y = win->ray_y;
	win->is_ver_wall = 1;
}

void	init_hor_data(t_window *win, double ray_angle, int id)
{
	win->hor_distace = INFINITY;
	win->is_hor_wall = 0;
	win->ray_y = floor(win->player.y / TILE) * TILE;
	if (win->rays[id].facing_down)
		win->ray_y += TILE;
	win->ray_x = win->player.x
		+ ((win->ray_y - win->player.y) / tan(ray_angle));
	win->step_y = TILE;
	if (win->rays[id].facing_up)
		win->step_y *= -1;
	win->step_x = TILE / tan(ray_angle);
	if (win->rays[id].facing_left && win->step_x > 0)
		win->step_x *= -1;
	if (win->rays[id].facing_right && win->step_x < 0)
		win->step_x *= -1;
	if (win->rays[id].facing_up)
		win->ray_y -= 0.01;
}

void	is_hor_ray(t_window *win, double ray_angle, int id)
{
	init_hor_data(win, ray_angle, id);
	while (!has_wall(win->ray_x, win->ray_y))
	{
		win->ray_x += win->step_x;
		win->ray_y += win->step_y;
	}
	win->hor_distace = calc_distance(win->player.x,
			win->player.y, win->ray_x, win->ray_y);
	win->hit_hor_x = win->ray_x;
	win->is_hor_wall = 1;
}
