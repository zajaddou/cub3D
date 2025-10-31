/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:13:13 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/31 16:13:15 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h" 

void draw_square(t_window *win, int x, int y, int color)
{
    int h;
    int w;

    h = -1;
    while (++h < 10)
    {
        w = -1;
        while (++w < 10)
            put_pixel(win, x + w, y + h, color); 
    }
}

int color_detect(int x, int y, t_map *map)
{
    if (y < 0 || y >= map->h)
        return (COLOR_WALL);

    if (x < 0 || x >= map->w)
        return (COLOR_WALL);

    if (map->map[y][x] == '0')
        return (COLOR_FLOOR);

    return (COLOR_WALL);
}

void draw_minimap(void *param)
{
    t_window    *win;
    t_map       *map;
    int         color;
    int         h;
    int         w;

    map =  map_g();
    win = (t_window *)param;

    int xs = (int)(win->player.x / TILE) - 5;
    int ys = (int)(win->player.y / TILE) - 5;

    h = -1;
    while (++h <= 10)
    {
        w = -1;
        while (++w <= 10)
        {
            color = color_detect(xs + h, ys + w, map);
            draw_square(win, h * 10, w * 10, color);
        }
    }
    draw_square(win, 50, 50, COLOR_PLAYER);
}
