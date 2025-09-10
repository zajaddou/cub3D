/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:48:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/10 19:36:39 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char *cut_to_end(char *str)
{
	str+= 2;
	if (*str == ' ' || *str == '\t')
		str++;
	while (*str)
	{
		if (*str == '\n' || *str == '\0')
			return (buff_ch(GET));
		buff_ch(*str);
		str++;
	}
	return (NULL);
}

char *cut_config(char *str, char *tag)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == tag[0])
			if (!is_overflow(str, i+1) && str[i+1] == tag[1])
				return (cut_to_end(&str[i]));	
	}
	return (NULL);
}

int config_raw(char *raw)
{
	char *res;

	if (!word_search(raw, "NO ") || !word_search(raw, "SO ")
		|| !word_search(raw, "WE ") || !word_search(raw, "EA ")
		|| !word_search(raw, "F ") || !word_search(raw, "C "))
		return (error("incorrect config ( .cub )"), ERR);

	res = cut_config(raw, "NO");
	if (!res)
		return (ERR);
	printf("\nNO: %s\n", res);
	res = cut_config(raw, "F ");
	if (!res)
		return (ERR);
	printf("\nF : %s\n", res);
	return (OK);
}
