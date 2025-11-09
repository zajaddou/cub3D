/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 08:17:34 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 13:36:21 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*ft_read_to_str(int fd, char *str)
{
	ssize_t	bytes_read;
	char	*buff;
	char	*tmp;

	buff = ft_malloc((size_t)1024 + 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buff, 1024);
		if (bytes_read < 0)
			return (ft_free(buff, FREE), ft_free(str, FREE), NULL);
		buff[bytes_read] = '\0';
		tmp = ft_strjoin(str, buff);
		if (!tmp)
			return (ft_free(buff, FREE), ft_free(str, FREE), NULL);
		str = tmp;
	}
	ft_free(buff, FREE);
	return (str);
}

static char	*ft_extract_line(char *str)
{
	int		i;
	char	*line;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_remove_line(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free(str, FREE), NULL);
	new_str = ft_malloc(ft_strlen(str) - i);
	if (!new_str)
		return (ft_free(str, FREE), NULL);
	i++;
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	ft_free(str, FREE);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*line;

	if (fd < 0 || 1024 <= 0)
		return (NULL);
	static_str = ft_read_to_str(fd, static_str);
	if (!static_str)
		return (NULL);
	line = ft_extract_line(static_str);
	static_str = ft_remove_line(static_str);
	return (line);
}
