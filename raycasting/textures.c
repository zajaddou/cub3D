/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:48 by mgarouj           #+#    #+#             */
/*   Updated: 2025/11/03 12:13:53 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_texture_id(t_ray *ray)
{
	if (ray->hit_vertical)
	{
		if (ray->facing_right)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray->facing_down)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void	draw_wall_strip(t_window *win, int x, int y, t_ray *ray)
{
	t_tex	*tex;

	tex = &win->tex_data[get_texture_id(ray)];
	if (ray->hit_vertical)
		tex->wall_hit_x = ray->wall_hit_y;
	else
		tex->wall_hit_x = ray->wall_hit_x;
	tex->wall_hit_x /= TILE;
	tex->wall_hit_x -= floor(tex->wall_hit_x);
	tex->tex_x = (int)(tex->wall_hit_x * tex->width);
	if ((ray->hit_vertical && ray->facing_left)
		|| (!ray->hit_vertical && ray->facing_up))
		tex->tex_x = tex->width - tex->tex_x - 1;
	tex->step = 1.0 * tex->height / ray->wall_height;
	tex->tex_pos = (ray->draw_start - WIN_H / 2
			+ ray->wall_height / 2) * tex->step;
	y = ray->draw_start;
	while (y++ < ray->draw_end)
	{
		tex->tex_y = (int)tex->tex_pos & (tex->height - 1);
		tex->tex_pos += tex->step;
		tex->color = *(int *)(tex->addr + (tex->tex_y * tex->line_lenght
					+ tex->tex_x * (tex->bits_per_pixel / 8)));
		put_pixel(win, x, y, tex->color);
	}
}

void	draw_textures(t_window *win, int i, double distance_proj_plane)
{
	double	perp_dist;
	double	wall_height;
	int		draw_start;
	int		draw_end;

	while (i < NUM_RAYS)
	{
		perp_dist = win->rays[i].distance
			* cos(win->rays[i].ray_angle - win->player.angle);
		if (perp_dist < 1e-30)
			perp_dist = 1e-30;
		wall_height = (TILE / perp_dist) * distance_proj_plane;
		draw_start = (WIN_H / 2) - (wall_height / 2);
		if (draw_start < 0)
			draw_start = 0;
		draw_end = (WIN_H / 2) + (wall_height / 2);
		if (draw_end >= WIN_H)
			draw_end = WIN_H - 1;
		win->rays[i].draw_start = draw_start;
		win->rays[i].draw_end = draw_end;
		win->rays[i].wall_height = wall_height;
		draw_wall_strip(win, i, 0, &win->rays[i]);
		i++;
	}
}
