/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:18:48 by mgarouj           #+#    #+#             */
/*   Updated: 2025/10/27 16:46:34 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void put_pixel(t_window *win, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
        return ;
    dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
    *(unsigned int *) dst = color;
}

void render_background(t_window *win)
{
    int x;
    int y;

    y = 0;
    while (y < WIN_H)
    {
        x = 0;
        while (x < WIN_W)
        {
            if (y < WIN_H / 2)
                put_pixel(win, x, y, map_g()->c_color);
            else
                put_pixel(win, x, y, map_g()->f_color);
            x++;
        }
        y++;
    }
}