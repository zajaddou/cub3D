/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:12:04 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 13:19:42 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	is_cub(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		error("Not a .cub file");
	if (!(path[len - 4] == '.' && path[len - 3] == 'c'
			&& path[len - 2] == 'u' && path[len - 1] == 'b'))
		error("Not a .cub file");
	check_path(path);
}

void	is_xpm(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		error("Not a .xpm file");
	if (!(path[len - 4] == '.' && path[len - 3] == 'x'
			&& path[len - 2] == 'p' && path[len - 1] == 'm'))
		error("Not a .xpm file");
	check_path(path);
}

void	get_rgb(char *rgb)
{
	int			nbr;
	int			i;
	char		**split;

	split = ft_split(rgb, ',');
	if (!split)
		error("Split ( rgb )");
	i = -1;
	while (++i <= 2)
	{
		nbr = ft_atoi(split[i]);
		if (!(nbr >= 0 && nbr <= 255))
			error("Incorrect config ( RGB Limit )");
	}
}

void	is_rgb(char *rgb)
{
	int	i;
	int	cut;

	i = -1;
	cut = 0;
	while (rgb[++i])
	{
		if (rgb[i] == ' ')
			continue ;
		if (!ft_isdigit(rgb[i]) && rgb[i] != ',')
			error("Incorrect config ( RGB )");
		if (rgb[i] == ',' && ++cut)
			if ((i >= 1 && !ft_isdigit(rgb[i - 1])) || !ft_isdigit(rgb[i + 1]))
				error("Incorrect config ( RGB )");
	}
	if (cut != 2)
		error("Incorrect config ( RGB )");
	get_rgb(rgb);
}
