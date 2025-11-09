/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:00:31 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/09 12:22:00 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_door(int x, int y, t_map *map)
{
	if (y < 0 || y >= map->h || x < 0 || x >= map->w)
		return ;
	if (map->map[y][x] == 'D')
		map->map[y][x] = 'd';
	else if (map->map[y][x] == 'd')
		map->map[y][x] = 'D';
}

void	door_handle(void)
{
	t_window	*win;
	t_map		*map;
	int			x;
	int			y;

	win = window_g();
	map = map_g();
	x = (int)(win->player.x / TILE);
	y = (int)(win->player.y / TILE);
	check_door(x, y - 1, map);
	check_door(x, y + 1, map);
	check_door(x - 1, y, map);
	check_door(x + 1, y, map);
}
