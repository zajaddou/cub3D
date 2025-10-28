/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:38:37 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/10 18:44:27 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	word_search(char *str, char *need)
{
	size_t i;
	size_t b;

	if (!*need)
		return (1);
	i = 0;
	while (str[i])
	{
		b = 0;
		while (str[i + b] && need[b] && str[i + b] == need[b])
			b++;
		if (!need[b])
			return (1);
		i++;
	}
	return (0);
}
