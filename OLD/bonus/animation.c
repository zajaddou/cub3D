/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:34:49 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/04 13:32:06 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int timer(int nb)
{
    static int timer;
    
    if (timer++ == nb)
    {
        timer = 0;
        return (1);
    }
    return (0);
}

void    init_images(void)
{
    t_window *win = window_g();

    int w;
    int h;
    int i;

    i = -1;
    while (++i < 10)
        fps_g()->walk[i] = mlx_xpm_file_to_image(win->mlx, ft_strjoin("textures/walk/", ft_strjoin(ft_itoa(i),".xpm")), &w, &h);

    printf("\nIMAGE : H:%d W:%d\n", h, w);
}

void animation(t_window *win)
{
    static int i;
    static int timer;

    timer++;

    if (timer >= 10)
    {
        timer = 0;
        i++;
    }

    if (i >= 10)
        i = 0;
    mlx_put_image_to_window(win->mlx,  win->win,  fps_g()->walk[i], 200, 384);
}


// # define WIN_W 1080
// # define WIN_H 720

// mlx_put_image_to_window(win->mlx,  win->win,  fps_g()->walk[i], 200, 384);

