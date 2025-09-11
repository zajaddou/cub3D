/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:22:24 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/11 10:07:52 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

	printf("      -- cub3D map --\n\n%s", ptr->raw_map);
	
	return (OK);
}
