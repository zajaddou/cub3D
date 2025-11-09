/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:48:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 13:57:59 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*cut_to_end(char *str, int rm_space)
{
	str += 2;
	if (*str == ' ' || *str == '\t')
		str++;
	while (*str)
	{
		if (*str == '\n' || *str == '\0')
			return (buff_ch(GET));
		if (rm_space)
		{
			if (*str != ' ')
				buff_ch(*str);
		}
		else
			buff_ch(*str);
		str++;
	}
	return (NULL);
}

char	*cut_config(char *str, char *tag, int rm_space)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == tag[0])
			if (!is_overflow(str, i + 1) && str[i + 1] == tag[1])
				return (cut_to_end(&str[i], rm_space));
	return (NULL);
}

void	extract_config(char *raw)
{
	t_parsing	*ptr;

	ptr = pars_g();
	ptr->config[0] = cut_config(raw, "NO", 0);
	ptr->config[1] = cut_config(raw, "SO", 0);
	ptr->config[2] = cut_config(raw, "WE", 0);
	ptr->config[3] = cut_config(raw, "EA", 0);
	ptr->config[4] = cut_config(raw, "F ", 1);
	ptr->config[5] = cut_config(raw, "C ", 1);
	is_xpm(ptr->config[0]);
	is_xpm(ptr->config[1]);
	is_xpm(ptr->config[2]);
	is_xpm(ptr->config[3]);
	is_rgb(ptr->config[4]);
	is_rgb(ptr->config[5]);
	map_g()->f_color = rgb_to_int(ptr->config[4]);
	map_g()->c_color = rgb_to_int(ptr->config[5]);
}

void	config_raw(void)
{
	char	**conf;
	char	*raw;

	raw = pars_g()->raw_config;
	conf = ft_split(raw, '\n');
	if (!conf)
		error("Split Error");
	if (word_search(conf, "NO ") || word_search(conf, "SO "))
		error("Incorrect config ( .cub )");
	if (word_search(conf, "WE ") || word_search(conf, "EA "))
		error("Incorrect config ( .cub )");
	if (word_search(conf, "F ") || word_search(conf, "C "))
		error("Incorrect config ( .cub )");
	extract_config(raw);
}
