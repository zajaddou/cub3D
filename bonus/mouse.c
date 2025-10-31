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

int mouse_handle(int x, int y, t_window *win)
{
    static int  last_x;

    if (last_x == 0)
        last_x = x;

    y = (x - last_x);

    win->player.angle += (0.003 * y);

    angle_update(&win->player.angle);

    last_x = x;

    return (0);
}
