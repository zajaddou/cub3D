/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:48:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/07 21:18:24 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rgb_to_int(char *str)
{
	char	**rgb;

	rgb = ft_split(str, ',');
	return (ft_atoi(rgb[0]) * 256 * 256
		+ ft_atoi(rgb[1]) * 256 + ft_atoi(rgb[2]));
}

void	check_ascii(char *str)
{
	int		i;

	if (!str)
		error("Map not included !");
	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == ',' || str[i] == '\n')
			continue ;
		if (ft_isalpha(str[i]) || ft_isdigit(str[i]))
			continue ;
		error("Invalid Ascii ( .cub )");
	}
}
