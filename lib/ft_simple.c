/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:23:50 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/11 14:15:23 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	or(int main, int b, int c)
{
	if (main == c || b == c)
		return (1);
	return (0);
}

char *rm_spaces(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (NULL);
	while (str[++i])
		if (str[i] != ' ')
			buff_ch(str[i]);
	return (buff_ch(GET));
}

int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	is_empty(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (1);
	while (str[++i])
		if (!is_space(str[i]))
			return (0);
	return (1);
}

int	is_overflow(char *str, int i)
{
	int	len;

	if (!str)
		return (1);
	len = (int)ft_strlen(str);
	if (i >= len)
		return (1);
	if (i < 0)
		return (1);
	return (0);
}
