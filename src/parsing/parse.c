/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:22:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/25 21:03:21 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_space(t_map *map)
{
	int			h;
	int			w;
	t_player	*ptr;
	
	ptr = player_g();
	
	h = -1;
	while (map->map[++h])
	{
		w = -1;
		while (map->map[h][++w])
		{
			if (map->map[h][w] == ' ')
				return (ERR);
			if (map->map[h][w] == 'N')
			{
				ptr->y = (h - 0.5) * TILE_SIZE;
				ptr->x = (w - 0.5) * TILE_SIZE;
				printf("\nplayer : [%f][%f]\n", ptr->y, ptr->x);
			}
		}
	}
	return (OK);
}

int	parse_input(char *path)
{
	t_parsing	*ptr;
	t_map		*map;

	ptr = parsing_g();
	map = map_g();

	if (is_cub_file(path) == ERR)
		return (ERR);

	if (read_cub(path))
		return (ERR);

	if (config_raw(ptr->raw_config))
		return (ERR);

	if (map_raw(ptr->raw_map))
		return (ERR);

	map_algo(0, 0, map);

	if (is_open(GET))
		return (error("Invalid map ( open )"), ERR);

	if (check_space(map))
		return (ERR);

	print_config();
	print_map();

	return (OK);
}
