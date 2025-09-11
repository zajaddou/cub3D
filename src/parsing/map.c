/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:34:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/11 15:25:29 by zajaddou         ###   ########.fr       */
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
    int h;
    int w;

    if (scan_map(raw))
        return (ERR);

	print_config();


    h = get_hight(raw);
    w = get_width(raw);
    printf("hight = %d\n", h);
    printf("width = %d\n\n", w);

    char *temp = add_padding(raw, w+1, '^');

    printf("      -- cub3D map --\n\n%s\n", temp);

    return (OK);
}

