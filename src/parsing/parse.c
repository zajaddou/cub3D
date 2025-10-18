/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:22:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/18 15:04:27 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void handle_spaces(void)
{
	t_map   *map;
	int		i;
	int		b;
	
    map = map_g();
	i = -1;
	while (map->map[++i])
	{
		b = -1;
		while (map->map[i][++b])
		{
			if (map->map[i][b] == ' ')
				map->map[i][b] = '0';
			if (map->map[i][b] == '.')
				map->map[i][b] = ' ';
		}
	}
}


int	parse_input(char *path)
{
	t_parsing	*ptr;

	ptr = parsing_g();
	
	if (is_cub_file(path) == ERR)
		return (ERR);

	if (read_map(path))
		return (ERR);

	if (config_raw(ptr->raw_config))
		return (ERR);
	
	if (map_raw(ptr->raw_map))
		return (ERR);

	map_algo(1, 1);

	if (is_open(GET))
		return (error("Invalid map ( open )"), ERR);

	handle_spaces();

	print_config();
	print_map();

	return (OK);
}
