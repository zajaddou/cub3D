/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:26:54 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/26 10:03:11 by zajaddou         ###   ########.fr       */
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

t_map	*map_g(void)
{
	static t_map	map;

	return (&map);
}

t_player *player_g(void)
{
	static t_player	player;

	return (&player);
}

t_parsing	*parsing_g(void)
{
	static t_parsing	parsing;

	return (&parsing);
}