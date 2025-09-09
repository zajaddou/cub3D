/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/09 12:34:21 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

bool	is_dir(char *path)
{
	int		fd;
	bool	res;

	res = false;
	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		res = true;
		close (fd);
	}
	return (res);
}

int	check_file(char *path)
{
	if (is_dir(path))
		return (error("Is a directory"), ERR);
	return (OK);
}

int	parse_input(char *path)
{
	if (check_file(path) == ERR)
		return (ERR);
	return (OK);
}

int	main(int ac, char **av)
{
	logo();
	
	if (ac != 2)
		return (error(ERR_INPUT), 1);

	if (parse_input(av[1]))
		return (ERR);

	return (OK);
}