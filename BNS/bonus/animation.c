/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:34:49 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/09 12:24:49 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_animation	*anim_g(void)
{
	static t_animation	anim;

	return (&anim);
}

void	init_animation(void)
{
	t_window	*win;
	t_animation	*anim;
	char		*path;
	int			x;
	int			i;

	win = window_g();
	anim = anim_g();
	i = -1;
	while (++i < 10)
	{
		path = ft_strjoin("textures/anim/", ft_strjoin(ft_itoa(i), ".xpm"));
		is_xpm(path);
		anim->images[i] = mlx_xpm_file_to_image(win->mlx, path, &x, &x);
		if (!anim->images[i])
		{
			while (--i >= 0)
			{
				mlx_destroy_image(win->mlx, anim->images[i]);
				anim->images[i] = NULL;
			}
			error("Invalid Animation");
		}
	}
}

void	animation(t_window *win)
{
	static float	i;

	i += 0.1;
	if (i >= 10)
		i = 0;
	mlx_put_image_to_window(win->mlx, win->win,
		anim_g()->images[(int)i], 200, 384);
}
