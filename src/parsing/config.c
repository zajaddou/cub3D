/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:48:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/10 15:57:30 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char *cut_to_end(char *str)
{
	str+= 2;
	if (*str == ' ' || *str == '\t')
		str++;
	if (*str == '\n' || *str == '\0')
		return (error("void config"), NULL);
	while (*str)
	{
		if (*str == '\n' || *str == '\0')
			return (buff_ch(GET));
		buff_ch(*str);
		str++;
	}
	return (NULL);
}

char *cut_config(char *str, char a, char b)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == a && b == 0)
			return (cut_to_end(&str[i]));
		else if (str[i] == a)
			if (!is_overflow(str, i+1) && str[i+1] == b)
				return (cut_to_end(&str[i]));	
	}
	return (NULL);
}

int config_raw(char *raw)
{
	char *temp;
	
	temp = cut_config(raw, 'N', 'O');
	if (!temp)
		return (ERR);
	printf("\nNO: %s\n", temp);
	return (OK);
}
