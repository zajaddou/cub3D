/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:18:10 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/10 16:25:51 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_valid_file(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error("Cannot open file"), ERR);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), error("Empty file"), ERR);
	close(fd);
	free(line);
	return (OK);
}

static	int	is_dir(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (ERR);
	}
	return (OK);
}

int	is_cub_file(char *path)
{
	int	len;
	int	fd;

	if (is_dir(path))
		return (error("Is a directory"), ERR);
	len = ft_strlen(path);
	if (len < 4)
		return (error("Not a .cub file"), ERR);
	if (!(path[len - 4] == '.' && path[len - 3] == 'c' && path[len - 2] == 'u' && path[len - 1] == 'b'))
		return (error("Not a .cub file"), ERR);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error("Cannot open file ( .cub )"), ERR);
	close(fd);
	return (OK);
}

void cut_line(char *line)
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
		ptr->raw_config = buff_ch(GET);
}

int		read_map(char *path)
{
	int			fd;
	char		*line;
	t_parsing	*ptr;

	ptr = parsing_g();
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (!is_empty(line))
			cut_line(line);
		line = get_next_line(fd);
	}
	ptr->raw_map = buff_ch(GET);
	close(fd);
	return (OK);
}
