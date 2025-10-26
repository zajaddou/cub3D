/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:18:10 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/26 09:59:21 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_file(char *path)
{
	int		fd;
	int		res;
	char	buff[20];

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
		return (close(fd), error("Path is a directory"), ERR);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error("Cannot open file"), ERR);
	res = read(fd, buff, sizeof(buff));
	if (res <= 0)
		return (close(fd), error("Empty file"), ERR);
	close(fd);
	return (OK);
}

int	is_cub_file(char *path)
{
	int	len;

	if (is_valid_file(path) == ERR)
		return (ERR);
	len = ft_strlen(path);
	if (len < 4)
		return (error("Not a .cub file"), ERR);
	if (!(path[len - 4] == '.' && path[len - 3] == 'c' 
			&& path[len - 2] == 'u' && path[len - 1] == 'b'))
		return (error("Not a .cub file"), ERR);
	return (OK);
}

int	is_xpm_file(char *path)
{
	int	len;

	if (is_valid_file(path) == ERR)
		return (ERR);
	len = ft_strlen(path);
	if (len < 4)
		return (error("Not a .xpm file"), ERR);
	if (!(path[len - 4] == '.' && path[len - 3] == 'x' 
			&& path[len - 2] == 'p' && path[len - 1] == 'm'))
		return (error("Not a .xpm file"), ERR);
	if (is_valid_file(path) == ERR)
		return (ERR);
	return (OK);
}

static void cut_line(char *line, int *map_part)
{
	t_parsing	*ptr;
	static int	call;
	int			i;
	
	ptr = parsing_g();
	call++;
	if (call <= 6)
	{
		i = -1;
		while (line[++i])
		{
			if (is_space(line[i]) && is_space(line[i+1]))
				continue;
			buff_ch(line[i]);
		}
	}
	else
		buff_str(line);
	if (call == 6)
	{
		ptr->raw_config = buff_ch(GET);
		*map_part = 1;
	}
}

void format_map(t_parsing	*ptr)
{
	char		*str;
	int 		e;
	int			s;
	
	str = ptr->raw_map;
	e = ft_strlen(str);
	s = -1;
	while (str[++s] && str[s] == '\n');
	while (str[--e] && str[e] == '\n');
	buff_ch('\n');
	while (str[s] && s <= e)
	{
		if (s >= 1 && (str[s] == '\n' && str[s-1] == '\n'))
		{
			error("newline inside map");
			exit(1);
		}
		buff_ch(str[s]);
		s++;
	}
	buff_ch('\n');
	ft_free(ptr->raw_map, 1);
	ptr->raw_map = buff_ch(GET);
}

int		read_cub(char *path)
{
	int			fd;
	int			map_part;
	char		*line;
	t_parsing	*ptr;

	map_part = 0;
	ptr = parsing_g();
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (map_part || !is_empty(line))
			cut_line(line, &map_part);
		line = get_next_line(fd);
	}
	close(fd);
	ptr->raw_map = buff_ch(GET);
	if (!ptr->raw_map)
		return (error("map not included !"), 1);
	format_map(ptr);
	return (OK);
}
