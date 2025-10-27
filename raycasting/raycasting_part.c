/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:18:53 by mgarouj           #+#    #+#             */
/*   Updated: 2025/10/27 20:38:12 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	calc_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void angle_update(double* ray_angle)
{
    *ray_angle = fmod(*ray_angle, 2 * M_PI);
    if (*ray_angle < 0)
        *ray_angle += 2 * M_PI;
}



int has_wall(double x, double y)
{
    t_map *map;
    int map_x;
    int map_y;
    
    map = map_g();
    if (!map || !map->map)
        return 1;
    
    map_x = (int) (x / TILE);
    map_y = (int) (y / TILE);

    if (map_x < 0 || map_x >= map->w || map_y < 0 || map_y >= map->h)
        return 1;
    
    if (map->map[map_y] && (int) ft_strlen(map->map[map_y]) > map_x)
    {
        if (map->map[map_y][map_x] == '1')
            return 1;

    }

    return 0;
}




// ratcastiing : horizontal



void	init_hor(t_window *win, double ray_angle, int id)
{
	win->hor_distace = 1e30; // Set to "infinity"
	win->is_hor_wall = 0;
	
	// Find the Y-coordinate of the first horizontal grid line
	win->ray_y = floor(win->player.y / TILE) * TILE;
	if (win->rays[id].facing_down)
		win->ray_y += TILE;

	// Find the X-coordinate of where the ray hits that line
	win->ray_x = win->player.x + ((win->ray_y - win->player.y) / tan(ray_angle));
	
	// Calculate the step size for subsequent grid lines
	win->step_y = TILE;
	if (win->rays[id].facing_up)
		win->step_y *= -1;
	
	win->step_x = TILE / tan(ray_angle);
	if (win->rays[id].facing_left && win->step_x > 0)
		win->step_x *= -1;
	if (win->rays[id].facing_right && win->step_x < 0)
		win->step_x *= -1;
	
	// Subtract a tiny bit if facing up to check the correct tile
	if (win->rays[id].facing_up)
		win->ray_y -= 0.01;
}



void cast_hor(t_window *win, double ray_angle, int id)
{
    init_hor(win, ray_angle, id);

    while (!has_wall(win->ray_x, win->ray_y))
    {
        win->ray_x += win->step_x;
        win->ray_y += win->step_y;
    }

    win->hor_distace = calc_distance(win->player.x, win->player.y, win->ray_x, win->ray_y);
    win->hit_hor_x = win->ray_x;
    win->is_hor_wall = 1;
}
// ratcastiing : vertical


void init_ver(t_window *win, double ray_angle, int id)
{
    win->ver_distace = 1e30;
    win->is_ver_wall = 0;
    
    win->ray_x = floor(win->player.x / TILE) * TILE;
    if (win->rays[id].facing_right)
        win->ray_x += TILE;

    win->ray_y = win->player.y + ((win->ray_x - win->player.x) * tan(ray_angle));
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

void cast_ver(t_window *win, double ray_angle, int id)
{
    init_ver(win, ray_angle, id);
    while (!has_wall(win->ray_x, win->ray_y))
    {
        win->ray_x += win->step_x;
        win->ray_y += win->step_y;
    }

    win->ver_distace = calc_distance(win->player.x, win->player.y, win->ray_x, win->ray_y);
    win->hit_ver_y = win->ray_y;
    win->is_ver_wall = 1;
}

void cast_single_ray(t_window* win, double ray_angle, int id)
{
    
    angle_update(&ray_angle);
    win->rays[id].ray_angle = ray_angle;
    win->is_hor_wall = 0;
    win->is_ver_wall = 0;
    win->rays[id].facing_down = ray_angle > 0 && ray_angle < M_PI;
    win->rays[id].facing_up = !win->rays[id].facing_down;
    win->rays[id].facing_right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
    win->rays[id].facing_left = !win->rays[id].facing_right;
    cast_hor(win, ray_angle, id);
    cast_ver(win, ray_angle, id);
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

void cast_all_rays(t_window *win)
{
    double ray_angle;
    int i;

    i = 0;
    ray_angle = win->player.angle - (FOV / 2);
    window_g()->iswall = 0;
    window_g()->is_hor_wall = 0;
    window_g()->is_ver_wall = 0;
    while (i < NUM_RAYS)
    {
        cast_single_ray(win, ray_angle, i);
        ray_angle += INCREMENT;
        i++;
    }
}

int render_frame(void *param)
{
    t_window *win = (t_window *)param;

    update_player(win);

    
    render_background(win);
    cast_all_rays(win);
    render_walls(win);   
    mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);

    return (0);
}
