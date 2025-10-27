/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvment_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:51:10 by mgarouj           #+#    #+#             */
/*   Updated: 2025/10/27 18:37:59 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void rotate_player(t_window *win, double rot_speed)
{
    win->player.angle += rot_speed;
    angle_update(&win->player.angle);
}


void move_player(t_window *win, double move_x, double move_y)
{
    double new_x;
    double new_y;
    t_map *map;

    map = map_g();

    new_x = win->player.x + move_x;

    if (!has_wall(new_x * TILE, win->player.y * TILE))
        win->player.x = new_x;
        
    new_y = win->player.y + move_y;

    if (!has_wall(win->player.x * TILE, win->player.y * TILE))
        win->player.y = new_y;
}





int key_press_handle(int key, t_window *win)
{
    double move_angle;

    printf("____________________\n  x = %d\ny = %d\n", player_g()->x/32, player_g()->y/32);

    if (key == KEY_ESC)
        exit(0);
    if (key == KEY_LEFT)
        rotate_player(win, ROT_SPEED * -1);
    if (key == KEY_RIGHT)
    {
        rotate_player(win, ROT_SPEED);

    }
    if (key == KEY_W)
    {
        printf("RIGHT DEEEE\n");
        move_player(win, cos(win->player.angle) * MOVE_SPEED, sin(win->player.angle) * MOVE_SPEED);
        
    }
    if (key == KEY_S)
        move_player(win, -cos(win->player.angle) * MOVE_SPEED, -sin(win->player.angle) * MOVE_SPEED);
    if (key == KEY_A)
    {
        move_angle = win->player.angle - (M_PI / 2);
        move_player(win, cos(move_angle) * MOVE_SPEED, sin(move_angle) * MOVE_SPEED);
        
    }
    if (key == KEY_A)
    {
        move_angle = win->player.angle - (M_PI / 2);
        move_player(win, cos(move_angle) * MOVE_SPEED, sin(move_angle) * MOVE_SPEED);
        
    }
    return 0;
}