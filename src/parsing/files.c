/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:18:10 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/09 13:38:22 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	int	is_dir(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (ERR);
	}
	return (OK);
}

int	is_cub_file(char *path)
{
	int	len;
	int	fd;

	if (is_dir(path))
		return (error("Is a directory"), ERR);
	len = ft_strlen(path);
	if (len < 4)
		return (error("Not a .cub file"), ERR);
	if (!(path[len - 4] == '.' && path[len - 3] == 'c' && path[len - 2] == 'u' && path[len - 1] == 'b'))
		return (error("Not a .cub file"), ERR);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error("Cannot open file"), ERR);
	close(fd);
	return (OK);
}