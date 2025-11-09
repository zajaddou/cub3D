/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:42:22 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/23 12:59:17 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;
	char	*start;

	len = ft_strlen(s);
	copy = ft_malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	start = copy;
	while (*s)
		*copy++ = *s++;
	*copy = '\0';
	return (start);
}
