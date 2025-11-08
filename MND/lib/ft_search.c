/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:38:37 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 13:36:39 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	str_cmp(char *str, char *need)
{
	int	i;

	i = -1;
	while (*str == ' ')
		str++;
	while (need[++i])
		if (str[i] != need[i])
			return (0);
	return (1);
}

int	word_search(char **conf, char *need)
{
	size_t	i;
	size_t	f;

	i = -1;
	f = 0;
	while (conf[++i])
		if (str_cmp(conf[i], need))
			f++;
	if (f < 1)
		error("Incorrect config ( .cub )");
	if (f > 1)
		error("Duplicate config ( .cub )");
	return (OK);
}
