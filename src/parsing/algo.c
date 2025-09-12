/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:34:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/12 14:40:18 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void map_algo(int x, int y)
{
    t_map *map;

    map = map_g();
    if (is_open(GET))
        return ;
    if (map->map[x][y] == '1' || map->map[x][y] == '.' || map->map[x][y] == '\a')
        return ;
    if (map->map[x][y] == '0')
    {
        is_open(1);
        return ;
    }
    map->map[x][y] = '.';
    map_algo(x, y+1);
    map_algo(x, y-1);
    map_algo(x+1, y);
    map_algo(x-1, y);
}