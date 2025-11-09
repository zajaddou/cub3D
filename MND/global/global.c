/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:03:10 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/09 13:43:58 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(void)
{
	t_window	*win;

	win = window_g();
	printf(BOLD"X Close window \n\n"RESET);
	destroy_textures();
	mlx_destroy_window(win->mlx, win->win);
	ft_free(NULL, FREE);
	exit(0);
	return (0);
}

void	error(char *str)
{
	ft_putstr_fd(BOLD RED "Error" RESET BOLD, 2);
	if (str)
	{
		ft_putstr_fd(" : " RED, 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n\n" RESET, 2);
	destroy_textures();
	ft_free(NULL, FREE);
	exit(2);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error("Failed to Allocate");
	ft_free(ptr, 0);
	return (ptr);
}
