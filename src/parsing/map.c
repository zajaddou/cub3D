/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:34:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/11 15:51:28 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int scan_map(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\n' && str[i] != 'N' && str[i] != 'S')
            if (str[i] != 'E' && str[i] != 'W' && str[i] != '0' && str[i] !=  '1')
			    return (error("invalid map character"), ERR);	
    return (OK);
}

int get_hight(char *str)
{
    int	i;
    int line;

	i = -1;
    line = 0;
	while (str[++i])
		if (str[i] == '\n')
            line++;
    return (line);
}

int get_width(char *str)
{
    int	i;
    int s;
    int max;

	i = -1;
    s = 0;
    max = -1;
    
	while (str[++i])
    {
        if (str[i] == '\n')
        {
            if (max < (i - s))
                max = (i - s - 1);
            s = i;
        }
    }
    return (max);
}


char    *add_padding(char *raw, int size, char pad)
{
    int	i;
    int s;

	i = -1;
    s = -1;

    buff_dup(pad, size + 1);
    buff_ch('\n');
    buff_dup(pad, 1);
	while (raw[++i])
    {
        if (raw[i] != '\n')
            buff_ch(raw[i]);
        else if (raw[i] == '\n')
        {
            if ((i - s) < size + 1)
                buff_dup(pad, (size + 1 - (i - s)));
            s = i;
            buff_ch('\n');
            buff_dup(pad, 1);
        }
    }
    buff_dup(pad, size);
    buff_ch('\n');
    return (buff_ch(GET));
}
    
int map_raw(char *raw)
{
    char *new_raw;
    t_map *map;

    map = map_g();
    if (scan_map(raw))
        return (ERR);

    map->h = get_hight(raw);
    map->w = get_width(raw);
    new_raw = add_padding(raw, map->w+1, '`');
    map->map = ft_split(new_raw, '\n');
    return (OK);
}

void print_map(void)
{
    t_map   *map;
    int     i;

    map = map_g();
    printf("      -- cub3D map --\n\n");
    i = -1;
    while (map->map[++i] != NULL)
        printf("%s\n", map->map[i]);
    printf("hight = %d\n", map->h);
    printf("width = %d\n\n", map->w);
}
