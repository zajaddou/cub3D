/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/09 13:22:33 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"



int	parse_input(char *path)
{
	if (is_cub_file(path) == ERR)
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