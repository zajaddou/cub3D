/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:26:54 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/06 15:54:03 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map	*map_g(void)
{
	static t_map	map;

	return (&map);
}

t_player	*player_g(void)
{
	static t_player	player;

	return (&player);
}

t_parsing	*pars_g(void)
{
	static t_parsing	parsing;

	return (&parsing);
}

t_window	*window_g(void)
{
	static t_window	window_d;

	return (&window_d);
}
