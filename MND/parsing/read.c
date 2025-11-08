/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:18:10 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 13:25:18 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_path(char *path)
{
	int		fd;
	int		res;
	char	buff[20];

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		error("Path is a directory");
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("Cannot open file");
	res = read(fd, buff, sizeof(buff));
	if (res <= 0)
	{
		close(fd);
		error("Empty file");
	}
	close(fd);
}

int	config_line(char *str)
{
	int	i;

	if (is_empty(str))
		return (0);
	i = -1;
	while (str[++i])
	{
		if (is_space(str[i]) && is_space(str[i + 1]))
			continue ;
		buff_ch(str[i]);
	}
	return (1);
}

void	handel_line(char *str, char *loop)
{
	if (*loop < 6)
	{
		if (config_line(str))
			(*loop)++;
	}
	else
		buff_str(str);
}

void	read_cub(char *path)
{
	int			fd;
	char		loop;
	char		*line;
	t_parsing	*ptr;

	ptr = pars_g();
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	loop = 0;
	while (line)
	{
		handel_line(line, &loop);
		if (loop == 6)
		{
			ptr->raw_config = buff_ch(GET);
			loop++;
		}
		line = get_next_line(fd);
	}
	close(fd);
	ptr->raw_map = buff_ch(GET);
	check_ascii(ptr->raw_map);
}
