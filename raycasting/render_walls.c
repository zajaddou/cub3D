/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:28:43 by mgarouj           #+#    #+#             */
/*   Updated: 2025/10/27 17:39:20 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



 
static void	my_pixel_put(t_window *win, int x, int y, int color)
{
	char	*dst;

	// Only draw if the pixel is within the window
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
	*(unsigned int *)dst = color;
}

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

/**
 * @brief Draws a single vertical line of pixels for a wall slice.
 */
static void	draw_vertical_line(t_window *win, int x, int draw_start, int draw_end, int color)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		my_pixel_put(win, x, y, color);
		y++;
	}
}



void render_walls(t_window *win)
{
    int i;
    double perp_dist;
    double wall_hieght;
    int draw_start;
    int drwaw_end;
    int color;


    i = 0;
    while (i < NUM_RAYS)
    {
        perp_dist = win->rays[i].distance * cos(win->rays[i].ray_angle - win->player.angle);

        wall_hieght = (TILE / perp_dist) * ((WIN_W / 2) / tan(FOV / 2));

        draw_start = (WIN_H / 2) - (wall_hieght / 2);
        if (draw_start < 0)
            draw_start = 0;
        drwaw_end = (WIN_H / 2) + (wall_hieght / 2);
        if (drwaw_end >= WIN_H)
            drwaw_end = WIN_H - 1;
        
        color = get_wall_color(&win->rays[i]);
        draw_vertical_line(win, i, draw_start, drwaw_end, color);
        i++;
        
    }
}