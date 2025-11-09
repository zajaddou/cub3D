/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:29:20 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/09 15:58:17 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_textures(void)
{
	t_window	*win;
	t_animation	*anim;
	int			i;

	win = window_g();
	anim = anim_g();
	i = -1;
	while (++i <= 3)
	{
		if (win->textures[i].img)
		{
			mlx_destroy_image(win->mlx, win->textures[i].img);
			win->textures[i].img = NULL;
		}
	}
	i = -1;
	while (++i < 10)
	{
		if (anim->images[i])
		{
			mlx_destroy_image(win->mlx, anim->images[i]);
			anim->images[i] = NULL;
		}
	}
}

void	load_textures(void)
{
	t_window	*win;
	t_parsing	*par;
	int			i;

	win = window_g();
	par = pars_g();
	i = -1;
	while (++i <= 3)
	{
		win->textures[i].img = mlx_xpm_file_to_image(win->mlx, par->config[i],
				&win->textures[i].width, &win->textures[i].height);
		if (!win->textures[i].img)
		{
			while (--i >= 0)
			{
				mlx_destroy_image(win->mlx, win->textures[i].img);
				win->textures[i].img = NULL;
			}
			error("Invalid textures");
		}
	}
}
