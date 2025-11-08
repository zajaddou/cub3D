/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:22:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 13:57:44 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_space(void)
{
	int			h;
	int			w;
	t_map		*map;

	map = map_g();
	h = -1;
	while (map->map[++h])
	{
		w = -1;
		while (map->map[h][++w])
			if (map->map[h][w] == ' ')
				error("Space inside map !");
	}
}

void	view_angle(char pos, double *angle)
{
	if (pos == 'N')
		*angle = 3 * M_PI / 2;
	else if (pos == 'E')
		*angle = 0;
	else if (pos == 'S')
		*angle = M_PI / 2;
	else if (pos == 'W')
		*angle = M_PI;
	else
		return ;
}

void	player_info(void)
{
	int			h;
	int			w;
	t_player	*player;
	t_map		*map;

	player = player_g();
	map = map_g();
	h = -1;
	while (map->map[++h])
	{
		w = -1;
		while (map->map[h][++w])
		{
			if (map->map[h][w] == 'N' || map->map[h][w] == 'E'
				|| map->map[h][w] == 'S' || map->map[h][w] == 'W')
			{
				view_angle(map->map[h][w], &player->angle);
				player->y = (h + 0.5) * TILE;
				player->x = (w + 0.5) * TILE;
			}
		}
	}
}

void	free_parsing(void)
{
	t_parsing	*ptr;

	ptr = pars_g();
	ft_free(ptr->config[0], FREE);
	ft_free(ptr->config[1], FREE);
	ft_free(ptr->config[2], FREE);
	ft_free(ptr->config[3], FREE);
	ft_free(ptr->config[4], FREE);
	ft_free(ptr->config[5], FREE);
	ft_free(ptr->raw_map, FREE);
	ft_free(ptr->raw_config, FREE);
}

void	parsing(char *path)
{
	is_cub(path);
	read_cub(path);
	format_map();
	config_raw();
	map_raw();
	map_algo(0, 0, map_g());
	check_space();
	player_info();
}
