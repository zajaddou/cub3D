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

void draw_square(t_window *win, int x, int y, int size, int color)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            put_pixel(win, x + j, y + i, color); 
            j++;
        }
        i++;
    }
}

void draw_minimap(void *param)
{
    t_window *win = (t_window *)param;
    t_map   *map = map_g();
    
    int PAD = 10;
    int map_x_start = (int)(win->player.x / TILE) - 5;
    int map_y_start = (int)(win->player.y / TILE) - 5;

    for (int j = 0; j < 11; j++)
    {
        for (int i = 0; i < 11; i++)
        {
            
            int real_map_x = map_x_start + i;
            int real_map_y = map_y_start + j;
            
            int color = COLOR_FLOOR;

            int px_x = (i * MINIMAP_TILE) + PAD;
            int px_y = (j * MINIMAP_TILE) + PAD;

            if (real_map_y >= 0 && real_map_y < map->h && map->map[real_map_y] && 
                real_map_x >= 0 && real_map_x < (int)ft_strlen(map->map[real_map_y]))
            {
                if (map->map[real_map_y][real_map_x] == '1')
                    color = COLOR_WALL;
                if (map->map[real_map_y][real_map_x] == '.') 
                    color = COLOR_WALL; 
            }
            else
                color = COLOR_WALL;
            
            draw_square(win, px_x, px_y, MINIMAP_TILE, color);
        }
    }

    int player_start_x = (5 * MINIMAP_TILE) + PAD;
    int player_start_y = (5 * MINIMAP_TILE) + PAD;

    draw_square(win, 
        player_start_x, 
        player_start_y, 
        MINIMAP_TILE,
        COLOR_PLAYER); 
}