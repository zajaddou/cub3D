/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:22:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/26 10:36:25 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_space_inside(t_map *map)
{
	int			h;
	int			w;
	
	h = -1;
	while (map->map[++h])
	{
		w = -1;
		while (map->map[h][++w])
			if (map->map[h][w] == ' ')
				return (ERR);
	}
	return (OK);
}

void view_angle(char pos, float *angle)
{
	if (pos == 'N')
		printf("\nPlayer view [ N ]\n");
	if (pos == 'E')
		printf("\nPlayer view [ E ]\n");
	if (pos == 'S')
		printf("\nPlayer view [ S ]\n");
	if (pos == 'W')
		printf("\nPlayer view [ W ]\n");
	*angle = 0.6;
}

int	player_info(t_map *map)
{
	int			h;
	int			w;
	t_player	*player;
	
	player = player_g();
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
				player->y = (h + 0.5) * TILE_SIZE;
				player->x = (w + 0.5) * TILE_SIZE;
			}
		}
	}
	return (OK);
}

int	parse_input(char *path)
{
	if (is_cub_file(path) == ERR)
		return (ERR);

	if (read_cub(path))
		return (ERR);

	if (config_raw(parsing_g()->raw_config))
		return (ERR);

	if (map_raw(parsing_g()->raw_map))
		return (ERR);

	map_algo(0, 0, map_g());

	if (is_open(GET))
		return (error("Invalid map ( open )"), ERR);

	if (check_space_inside(map_g()))
		return (ERR);

	if (player_info(map_g()))
		return (ERR);

	print_config();
	print_map();

	return (OK);
}
