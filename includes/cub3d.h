/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:48:11 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/09 17:38:01 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include "env.h"
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_data 
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
}	t_data;

typedef struct s_map
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
}	t_map;

// GLOBAL
void	error(char *str);
void	logo(void);

// LIB
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

// FUNCTIONS
int	    is_cub_file(char *path);
int     is_xpm_file(char *path);
t_data	*data_g(void);

#endif