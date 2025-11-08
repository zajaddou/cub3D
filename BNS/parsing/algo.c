/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:34:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 20:43:17 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_algo(int x, int y, t_map *map)
{
	char	c;

	if (x >= map->h || x < 0 || y >= map->w || y < 0)
		return ;
	c = map->map[x][y];
	if (c == '1' || c == '.')
		return ;
	if (c == '0' || c == 'D')
		error("Invalid map ( open )");
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		error("Invalid map ( open )");
	map->map[x][y] = '.';
	map_algo(x, y + 1, map);
	map_algo(x, y - 1, map);
	map_algo(x + 1, y, map);
	map_algo(x - 1, y, map);
}
