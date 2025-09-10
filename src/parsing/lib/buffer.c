/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:47:25 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/10 13:55:49 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*buff_ch(int c)
{
	static char	*buff;
	char		*new;
	char		*out;

	if (c >= 0)
	{
		new = malloc(sizeof(char) * 2);
		new[0] = c;
		new[1] = '\0';
		buff = ft_strjoin(buff, new);
	}
	else if (buff == NULL)
		return (NULL);
	else if (c == -1)
	{
		out = ft_strdup(buff);
		buff = NULL;
		return (out);
	}
	else
	{
		out = ft_strdup(buff);
		return (out);
	}
	return (NULL);
}

char	*buff_str(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (NULL);
	while (str[++i] != '\0')
		buff_ch(str[i]);
	return (NULL);
}

