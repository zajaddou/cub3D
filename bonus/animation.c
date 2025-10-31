/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:47:22 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/30 20:16:27 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

long    get_current_time_in_ms(void)
{
    struct timeval  time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void    init_animation(void)
{
    t_window *win = window_g();
    
    win->animated_logo.img_ptr[0] = mlx_xpm_file_to_image(win->mlx, "textures/logo.xpm", &win->animated_logo.width, &win->animated_logo.height);
    win->animated_logo.img_ptr[1] = mlx_xpm_file_to_image(win->mlx, "textures/logo.xpm", &win->animated_logo.width, &win->animated_logo.height);
    win->animated_logo.img_ptr[2] = mlx_xpm_file_to_image(win->mlx, "textures/logo.xpm", &win->animated_logo.width, &win->animated_logo.height);

    win->animated_logo.frame = 0;
    win->animated_logo.last_frame_time = get_current_time_in_ms();
}

void    update_animation(t_window *win)
{
    long    current_time;
    long    time_difference;

    current_time = get_current_time_in_ms();
    time_difference = current_time - win->animated_logo.last_frame_time;

    if (time_difference > 333) // ~333ms per frame for 3 FPS
    {
        win->animated_logo.frame++;
        if (win->animated_logo.frame >= 3)
            win->animated_logo.frame = 0;
        win->animated_logo.last_frame_time = current_time;
    }
}
