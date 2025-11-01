
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

    if (map->map[y][x] == '1' || map->map[y][x] == '.')
        return (COLOR_WALL);

    if (map->map[y][x] == 'D')
        return (COLOR_DOOR_C);
    if (map->map[y][x] == 'd')
        return (COLOR_DOOR_O);

    return (COLOR_FLOOR);
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

    int start_x = (int)(win->player.x / TILE) - 5;
    int start_y = (int)(win->player.y / TILE) - 5;

    h = -1;
    while (++h <= 10)
    {
        w = -1;
        while (++w <= 10)
        {
            color = color_detect(start_x + h, start_y + w, map);
            draw_square(win, h * 10, w * 10, color);
        }
    }
    draw_square(win, 50, 50, COLOR_PLAYER);
}
