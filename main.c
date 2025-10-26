/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/26 09:53:45 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_player    *player;
	t_map   	*map;

	map = map_g();
	player = player_g();
	
	logo();
	
	if (ac != 2)
		return (error("Invalid input !"), 1);
	
	if (parse_input(av[1]))
		return (ERR);
	return (OK);
}