/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 08:17:34 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/10 14:07:25 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*utils_ft_strchr(const char *s, int c)
{
	char	char_c;

	char_c = (char)c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == char_c)
			return ((char *)s);
		s++;
	}
	if (char_c == '\0')
		return ((char *)s);
	return (NULL);
}

static size_t	utils_ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

static char	*read_line(int fd, char *str)
{
	char	*buff;
	char	*temp;
	int		bread;

	buff = (char *)malloc((size_t)1024 + 1);
	if (!buff)
		return (free(str), str = NULL, NULL);
	while (!utils_ft_strchr(str, '\n'))
	{
		bread = read(fd, buff, BUFFER_SIZE);
		if (bread < 0)
			return (free(buff), buff = NULL, free(str), str = NULL, NULL);
		if (bread == 0)
			break ;
		buff[bread] = '\0';
		temp = str;
		str = ft_strjoin(str, buff);
		free(temp);
		temp = NULL;
		if (!str)
			return (free(buff), buff = NULL, NULL);
	}
	free(buff);
	buff = NULL;
	return (str);
}

static char	*one_line(char **src)
{
	char	*result;
	char	*temp;
	int		index;
	char	*new;

	if (!*src || !**src)
		return (NULL);
	new = ft_strchr(*src, '\n');
	if (new)
		index = new - *src;
	else
		index = utils_ft_strlen(*src) - 1;
	result = (char *)malloc(index + 2);
	if (!result)
		return (NULL);
	ft_strncpy(result, *src, index + 1);
	result[index + 1] = '\0';
	if (new)
		temp = ft_strdup(*src + index + 1);
	else
		temp = NULL;
	free(*src);
	*src = NULL;
	*src = temp;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	res = one_line(&str);
	if (!str || !*str)
	{
		free(str);
		str = NULL;
	}
	return (res);
}
