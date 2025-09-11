/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:34:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/11 14:19:21 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// { '0', '1', 'N', 'S', 'E', 'W', ' ' }

int scan_map(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!or(str[i], 'N', 'S') && !or(str[i], 'E', 'W'))
            if (!or(str[i], '0', '1') && str[i] != ' ')
			    return (ERR);	
    return (OK);
}
    
int map_raw(char *raw)
{
    printf("      -- cub3D map --\n\n%s\n", raw);
    
    if (scan_map(raw))
        return (ERR);

    return (OK);
}