/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:48:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/11 10:24:05 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void print_config()
{
	t_parsing *ptr;
	
	ptr = parsing_g();
	printf("\n       -- config --\n\n");
	printf("NO : %s\n", ptr->config[0]);
	printf("SO : %s\n", ptr->config[1]);
	printf("WE : %s\n", ptr->config[2]);
	printf("EA : %s\n", ptr->config[3]);
	printf("F  : %s\n", ptr->config[4]);
	printf("C  : %s\n\n", ptr->config[5]);
}

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
	t_parsing *ptr;

	ptr = parsing_g();
	if (!word_search(raw, "NO ") || !word_search(raw, "SO ")
		|| !word_search(raw, "WE ") || !word_search(raw, "EA ")
		|| !word_search(raw, "F ") || !word_search(raw, "C "))
		return (error("incorrect config ( .cub )"), ERR);
	ptr->config[0] = cut_config(raw, "NO");
	if (is_xpm_file(ptr->config[0]))
		return (ERR);
	ptr->config[1] = cut_config(raw, "SO");
	if (is_xpm_file(ptr->config[1]))
		return (ERR);
	ptr->config[2] = cut_config(raw, "WE");
	if (is_xpm_file(ptr->config[2]))
		return (ERR);
	ptr->config[3] = cut_config(raw, "EA");
	if (is_xpm_file(ptr->config[3]))
		return (ERR);
	ptr->config[4] = cut_config(raw, "F ");
	ptr->config[5] = cut_config(raw, "C ");
	print_config();
	return (OK);
}


