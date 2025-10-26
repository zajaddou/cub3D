/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:34:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/26 13:31:31 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int scan_map(char *str)
{
    int     i;
    int     p;
    char    c;

    p = 0;
    i = -1;
    while (str[++i])
    {
        c = str[i];
        if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            p++;
        else if (c != '0' && c != '1' && c != ' ' && c != '\n')
            return (error("invalid map character"), ERR);
    }
    if (p > 1)
        return (error("multiple player positions"), ERR);
    if (p == 0)
        return (error("no player"), ERR);
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

char    *map_padding(char *raw, int size)
{
    int	i;
    int s;

	i = -1;
    s = -1;
    buff_ch(' ');
	while (raw[++i])
    {
        if (raw[i] != '\n')
            buff_ch(raw[i]);
        else if (raw[i] == '\n')
        {
            if ((i - s) < size + 1)
                buff_dup(' ', (size + 1 - (i - s)));
            s = i;
            buff_str("\n ");
        }
    }
    buff_dup(' ', size);
    buff_ch('\n');
    return (buff_ch(GET));
}

int map_raw(char *raw)
{
    char    *new_raw;
    t_map   *map;

    map = map_g();
    if (scan_map(raw))
        return (ERR);
    map->h = get_hight(raw);
    map->w = get_width(raw);
    new_raw = map_padding(raw, ++map->w);
    map->w+=1;
    map->h+=1;
    map->map = ft_split(new_raw, '\n');
    return (OK);
}
