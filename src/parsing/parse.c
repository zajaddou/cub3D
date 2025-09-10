/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:22:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/10 14:00:11 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_input(char *path)
{
	t_map	*map;

	map = map_g();
	if (is_cub_file(path) == ERR)
		return (ERR);
	if (read_map(path))
		return (ERR);

    printf("%s", map->raw);
	return (OK);
}
