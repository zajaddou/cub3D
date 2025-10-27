/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:46 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/27 17:50:36 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	logo();
	
	if (ac != 2)
		return (error("Invalid input !"), 1);

	if (parse_input(av[1]))
		return (ERR);

	init_window();
	
	mlx_loop_hook(window_g()->mlx, render_frame, window_g());
	mlx_key_hook(window_g()->win, key_press_handle, window_g());
	
	mlx_loop(window_g()->mlx);

	return (OK);
}