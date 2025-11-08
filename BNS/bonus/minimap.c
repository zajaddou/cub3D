/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:42:55 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 14:45:42 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h" 

void	draw_square(t_window *win, int x, int y, int color)
{
	int	h;
	int	w;

	h = -1;
	while (++h < 10)
	{
		w = -1;
		while (++w < 10)
			put_pixel(win, x + w, y + h, color);
	}
}

int	color(int x, int y, t_map *map)
{
	if (y < 0 || y >= map->h)
		return (COLOR_WALL);
	if (x < 0 || x >= map->w)
		return (COLOR_WALL);
	if (map->map[y][x] == '1' || map->map[y][x] == '.')
		return (COLOR_WALL);
	if (map->map[y][x] == 'D')
		return (COLOR_DOOR_C);
	if (map->map[y][x] == 'd')
		return (COLOR_DOOR_O);
	return (COLOR_FLOOR);
}

void	draw_minimap(void *param)
{
	t_window	*win;
	t_map		*map;
	int			h;
	int			w;
	int			start_x;
	int			start_y;

	map = map_g();
	win = (t_window *)param;
	start_x = (int)(win->player.x / TILE) - 5;
	start_y = (int)(win->player.y / TILE) - 5;
	h = -1;
	while (++h <= 10)
	{
		w = -1;
		while (++w <= 10)
			draw_square(win, h * 10, w * 10,
				color(start_x + h, start_y + w, map));
	}
	draw_square(win, 50, 50, COLOR_PLAYER);
}
