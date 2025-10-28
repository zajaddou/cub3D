/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:34:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/28 11:06:08 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void map_algo(int x, int y, t_map *map)
{
    if (x >= map->h || x < 0 || y >= map->w || y < 0)
        return ;
    if (is_open(GET))
        return ;
    if (map->map[x][y] == '1' || map->map[x][y] == '.')
        return ;
    if (map->map[x][y] == '0')
    {
        is_open(1);
        return ;
    }
    map->map[x][y] = '.';
    map_algo(x, y+1, map);
    map_algo(x, y-1, map);
    map_algo(x+1, y, map);
    map_algo(x-1, y, map);
}