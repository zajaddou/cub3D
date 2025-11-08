/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:03:10 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/23 12:18:58 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error(char *str)
{
	ft_putstr_fd(RED "Error" RESET, 2);
	if (str)
	{
		ft_putstr_fd(" : " RED, 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n\n" RESET, 2);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		printf("Failed to Allocate");
	ft_free(ptr, 0);
	return (ptr);
}
