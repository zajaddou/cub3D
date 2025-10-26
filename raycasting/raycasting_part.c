/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:18:53 by mgarouj           #+#    #+#             */
/*   Updated: 2025/10/26 16:09:33 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void angle_update(double* ray_angle)
{
    *ray_angle = fmod(*ray_angle, 2 * M_PI);
    if (ray_angle < 0)
        *ray_angle += 2 * M_PI;
}

void cast_hor(int id)
{
    window_g()->hit_hor_x = 0;
    window_g()->hit_ver_y = 0;
    window_g()->ray_y = floor(window_g()->player.y * TILE / TILE) * TILE;

    if (window_g()->rays[id].facing_down)
        window_g()->ray_y += TI
    
}

void cast_single_ray(t_window* win, double ray_angle, int id)
{
    
    (void )win;
    win->is_hor_wall = 0;
    win->is_ver_wall = 0;
    win->rays[id].facing_down = ray_angle > 0 && ray_angle < M_PI;
    win->rays[id].facing_up = !win->rays[id].facing_down;
    win->rays[id].facing_right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
    win->rays[id].facing_left = !win->rays[id].facing_right;
    cast_hor(id)
    
}

void cast_all_rays(t_window *win)
{
    double ray_angle;
    int i;

    i = 0;
    window_g()->iswall = 0;
    window_g()->is_hor_wall = 0;
    window_g()->is_ver_wall = 0;
    while (i < NUM_RAYS)
    {
        ungle_update(&ray_angle);
        cast_single_ray(win, ray_angle, i);
        ray_angle += INCREMENT;
        i++;
    }
}

int render_frame(void *param)
{
    t_window *win = (t_window *)param;

    render_background(win);
    cast_all_rays(win);      
    mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);

    return (0);
}