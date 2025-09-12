/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:26:54 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/12 12:13:32 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_open(int io)
{
	static int	on_off;

	if (io != GET)
		on_off = io;
	return (on_off);
}

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