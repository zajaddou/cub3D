/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:39:46 by mgarouj           #+#    #+#             */
/*   Updated: 2025/10/31 08:45:31 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	angle_update(double *ray_angle)
{
	*ray_angle = fmod(*ray_angle, 2 * M_PI);
	if (*ray_angle < 0)
		*ray_angle += 2 * M_PI;
}

void	init_window(void)
{
	t_window	*win;

	win = window_g();
	win->mlx = mlx_init();
	if (!win->mlx)
		return (error("mlx_init failed"));
	win->win = mlx_new_window(win->mlx, WIN_W, WIN_H, "Cub3D");
	if (!win->win)
		return (error("mlx_new_window failed"));
	win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
	if (!win->img)
		return (error("mlx_new_image failed"));
	win->addr = mlx_get_data_addr(win->img,
			&win->bpp, &win->line_len, &win->endian);
	if (!win->addr)
		return (error("mlx_get_data_addr failed"));
}
