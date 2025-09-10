/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:26:54 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/10 14:55:05 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_data	*data_g(void)
{
	static t_data	data;

	return (&data);
}

t_map	*map_g(void)
{
	static t_map	map;

	return (&map);
}

t_parsing	*parsing_g(void)
{
	static t_parsing	parsing;

	return (&parsing);
}