/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/09 16:30:15 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	init_window(void)
{
	t_data *data;
	
	data = data_g();
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "Cub3D");
	return ;
}

int	parse_input(char *path)
{
	if (is_cub_file(path) == ERR)
		return (ERR);
	return (OK);
}

int	main(int ac, char **av)
{
	t_data *data;
	
	data = data_g();
	logo();
	if (ac != 2)
		return (error("Invalid input !"), 1);
	if (parse_input(av[1]))
		return (ERR);
	//init_window();
	//mlx_loop(data->mlx);
	return (OK);
}