/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:28:43 by mgarouj           #+#    #+#             */
/*   Updated: 2025/10/29 14:36:41 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_wall_color(t_ray *ray)
{
	if (ray->hit_vertical)
	{
		if (ray->facing_right)
			return (COLOR_EAST);
		else
			return (COLOR_WEST);
	}
	else
	{
		if (ray->facing_down)
			return (COLOR_SOUTH);
		else
			return (COLOR_NORTH);
	}
}

static void	draw_vertical_line(t_window *win, int x, int draw_start, int draw_end, int color)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		put_pixel(win, x, y, color);
		y++;
	}
}

void render_walls(t_window *win)
{
    int i;
    double perp_dist;
    double wall_height;
    int draw_start;
    int draw_end;
    int color;


    i = 0;
    while (i < NUM_RAYS)
    {
        perp_dist = win->rays[i].distance * cos(win->rays[i].ray_angle - win->player.angle);

		if (perp_dist == 0)
            perp_dist = 1e-30;

        wall_height = (TILE / perp_dist) * (((WIN_W )  / (2*tan(FOV / 2))));

        draw_start = (WIN_H / 2) - (wall_height / 2);
        if (draw_start < 0)
            draw_start = 0;
        draw_end = (WIN_H / 2) + (wall_height / 2);
        if (draw_end >= WIN_H)
            draw_end = WIN_H - 1;
        
        color = get_wall_color(&win->rays[i]);
        draw_vertical_line(win, i, draw_start, draw_end, color);
        i++;
        
    }
}