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
    int l;
    int b;

    l = -1;
    while (++l < 10)
    {
        b = -1;
        while (++b < 10)
            put_pixel(win, x + b, y + l, color); 
    }
}


int color_detect(int x, int y, t_map *map)
{
    int color;

    if (y >= 0 && y < map->h && map->map[y] && x >= 0 && x < map->w)
    {
        if (map->map[y][x] == '1')
            color = COLOR_WALL;
        if (map->map[y][x] == '.') 
            color = COLOR_WALL; 
    }
    else
        color = COLOR_WALL;
    return (color);
}

void draw_minimap(void *param)
{
    t_window    *win;
    t_map       *map;

    map =  map_g();
    win = (t_window *)param;

    int xs = (int)(win->player.x / TILE) - 5;
    int ys = (int)(win->player.y / TILE) - 5;

    for (int j = 0; j < 11; j++)
    {
        for (int i = 0; i < 11; i++)
        {
            
            int map_x = xs + i;
            int map_y = ys + j;
            
            int color = COLOR_FLOOR;

            int px_x = (i * 10);
            int px_y = (j * 10);


            draw_square(win, px_x, px_y, color);
        }
    }
    draw_square(win, 50, 50, COLOR_PLAYER);
}