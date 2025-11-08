/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:23:12 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 13:35:24 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	new_line_inside(char *str, int i)
{
	while (str[++i])
	{
		if (str[i] != '\n' && str[i] != ' ')
			break ;
		if (str[i] == '\n')
			error("Invalid map ( .cub )");
	}
}

void	scan_from_end(char *str, int s, int e)
{
	int	new;

	new = 0;
	while (s < e)
	{
		if (str[e] == '0' || str[e] == '1')
			break ;
		if (str[e] == '\n')
			new++;
		if (new > 2)
			error("Newline at the end ( .cub )");
		e--;
	}
}

void	format_map(void)
{
	int		e;
	int		s;
	char	*raw;

	raw = pars_g()->raw_map;
	e = ft_strlen(raw);
	s = -1;
	while (raw[++s] && raw[s] == '\n')
		;
	scan_from_end(raw, s, e);
	buff_ch('\n');
	while (raw[s] && s <= e)
	{
		if (raw[s] == '\n')
			new_line_inside(raw, s);
		buff_ch(raw[s]);
		s++;
	}
	buff_ch('\n');
	ft_free(pars_g()->raw_map, FREE);
	pars_g()->raw_map = buff_ch(GET);
}
