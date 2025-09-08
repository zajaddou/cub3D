/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/08 11:17:28 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	print_controls(void)
{
	printf(CYAN "\n");
	printf("░█▀▀░█░█░█▀▄░▀▀█░█▀▄░\n");
	printf("░█░░░█░█░█▀▄░░▀▄░█░█░\n");
	printf("░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░░\n");
	printf(RESET "\n");
	printf("\n");
}

int	main(int ac, char **av)
{
	(void)av;
    print_controls();
	if (ac != 2)
		return (err_msg("parsing", 1));
	return (0);
}