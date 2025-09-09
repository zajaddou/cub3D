/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:48:11 by zajaddou          #+#    #+#             */
/*   Updated: 2025/09/09 16:24:58 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define ERR 1
# define OK 0

# define WIN_W 1080
# define WIN_H 490

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
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

// FUNCTIONS
int	    is_cub_file(char *path);
int     is_xpm_file(char *path);
t_data	*data_g(void);

#endif