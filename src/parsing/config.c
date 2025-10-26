/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:48:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/26 13:41:14 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char *cut_to_end(char *str, int rm_space)
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

char *cut_config(char *str, char *tag, int rm_space)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == tag[0])
			if (!is_overflow(str, i+1) && str[i+1] == tag[1])
				return (cut_to_end(&str[i], rm_space));	
	return (NULL);
}

int	is_valid_rgb(char *rgb)
{
	int	i;
	int	cut;

	i = -1;
	cut = 0;
	while (rgb[++i])
	{
		if (rgb[i] == ' ')
			continue;
		if (!ft_isdigit(rgb[i]) && rgb[i] != ',')
			return (ERR);
		if (rgb[i] == ',' && ++cut)
			if (!ft_isdigit(rgb[i-1]) || !ft_isdigit(rgb[i+1]))
				return (ERR);
	}
	if (cut != 2)
		return (ERR);
	return (OK);
}

int	rgb_check(char *rgb)
{
	int			nbr;
	int			i;
	t_parsing	*ptr;
	char		**sp;

	ptr = parsing_g();
	sp = ft_split(rgb, ',');
	i = -1;
	while (++i <= 2)
	{
		nbr = ft_atoi(sp[i]);
		if (!(nbr >= 0 && nbr <= 255))
			return (error("Incorrect config ( RGB )"), ERR);
	}
	return (OK);
}

int color_math(char *str)
{
	char **rgb = ft_split(str, ',');
	int r;
	int g;
	int b;
	
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	return (r * 256 * 256 + g * 256 + b);
}

int	extract_config(char *raw)
{
	t_parsing *ptr;
	
	ptr = parsing_g();

	ptr->config[0] = cut_config(raw, "NO", 0);
	ptr->config[1] = cut_config(raw, "SO", 0);
	ptr->config[2] = cut_config(raw, "WE", 0);
	ptr->config[3] = cut_config(raw, "EA", 0);
	ptr->config[4] = cut_config(raw, "F ", 1);
	ptr->config[5] = cut_config(raw, "C ", 1);
	if (is_xpm_file(ptr->config[0]) || is_xpm_file(ptr->config[1]))
		return (ERR);
	if (is_xpm_file(ptr->config[2]) || is_xpm_file(ptr->config[3]))
		return (ERR);
	if (is_valid_rgb(ptr->config[4]))
		return (error("Incorrect config ( RGB )"), ERR);
	if (is_valid_rgb(ptr->config[5]))
		return (error("Incorrect config ( RGB )"), ERR);
	if (rgb_check(ptr->config[4]) || rgb_check(ptr->config[5]))
		return (ERR);
		
	map_g()->f_color = color_math(ptr->config[4]);
	map_g()->c_color = color_math(ptr->config[5]);

	return (OK);
}

int config_raw(char *raw)
{
	if (!word_search(raw, "NO ") || !word_search(raw, "SO ")
		|| !word_search(raw, "WE ") || !word_search(raw, "EA ")
		|| !word_search(raw, "F ") || !word_search(raw, "C "))
		return (error("Incorrect config ( .cub )"), ERR);
	if (extract_config(raw))
		return (ERR);

	return (OK);
}
