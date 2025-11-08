/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:34:59 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 13:27:35 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	scan_map(char *str)
{
	int		i;
	int		p;
	char	c;

	p = 0;
	i = -1;
	while (str[++i])
	{
		c = str[i];
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			p++;
		else if (c != '0' && c != '1' && c != ' ' && c != '\n')
			error("Invalid map character !");
	}
	if (p > 1)
		error("Multiple player !");
	if (p == 0)
		error("No player !");
}

int	get_hight(char *str)
{
	int	i;
	int	line;

	i = -1;
	line = 0;
	while (str[++i])
		if (str[i] == '\n')
			line++;
	return (line);
}

int	get_width(char *str)
{
	int	i;
	int	s;
	int	max;

	i = -1;
	s = 0;
	max = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			if (max < (i - s))
				max = (i - s - 1);
			s = i;
		}
	}
	return (max);
}

char	*add_padding(char *raw, int size, char pad)
{
	int	i;
	int	s;

	i = -1;
	s = -1;
	buff_str(" ");
	while (raw[++i])
	{
		if (raw[i] != '\n')
			buff_ch(raw[i]);
		else if (raw[i] == '\n')
		{
			if ((i - s) < size + 1)
				buff_dup(pad, (size + 1 - (i - s)));
			s = i;
			buff_str("\n ");
		}
	}
	buff_dup(pad, size);
	buff_str("\n");
	return (buff_ch(GET));
}

void	map_raw(void)
{
	char		*new_raw;
	t_map		*map;
	char		*raw;

	raw = pars_g()->raw_map;
	map = map_g();
	scan_map(raw);
	map->h = get_hight(raw);
	map->w = get_width(raw);
	new_raw = add_padding(raw, map->w + 1, ' ');
	map->w += 2;
	map->h += 1;
	map->map = ft_split(new_raw, '\n');
	if (!map->map)
		error("Split Error");
}
