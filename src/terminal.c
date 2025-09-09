/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:54:29 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/09 12:33:54 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	logo(void)
{
	printf(CYAN);
	printf("   ______      __   _____ ____   \n");
	printf("  / ____/_  __/ /_ |__  // __ \\ \n");
	printf(" / /   / / / / __ \\ /_ </ / / / \n");
	printf("/ /___/ /_/ / /_/ /__/ / /_/ /   \n");
	printf("\\____/\\__,_/_.___/____/_____/  \n\n");
	printf(RESET);
}

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
