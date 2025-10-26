/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:16:41 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/26 13:39:46 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void print_map(void)
{
    t_map   *map;
    t_player   *player;
    int     i;

    map = map_g();
    player = player_g();

    printf("F  : %d\n", map->c_color);
	printf("C  : %d\n", map->f_color);
    
    printf("\n      -- cub3D map --\n\n");
    i = -1;
    while (map->map[++i] != NULL)
        printf("%s\n", map->map[i]);

    printf("\nMAP [%d][%d]\n", map->h, map->w);
    
    printf("\nPlayer   | W:%.1f H:%.1f", ((float)player->x / TILE_SIZE), ((float)player->y / TILE_SIZE));
    printf("\nPixel    | X:%d Y:%d\n\n", player->x, player->y);
}

void print_config(void)
{
	t_parsing *ptr;
	
	ptr = parsing_g();
	printf("\n       -- config --\n\n");
	printf("NO | %s\n", ptr->config[0]);
	printf("SO | %s\n", ptr->config[1]);
	printf("WE | %s\n", ptr->config[2]);
	printf("EA | %s\n\n", ptr->config[3]);
	printf("F  | %s\n", ptr->config[4]);
	printf("C  | %s\n\n", ptr->config[5]);
}

