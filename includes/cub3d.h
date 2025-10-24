/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:48:11 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/23 12:20:25 by zajaddou         ###   ########.fr       */
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

typedef struct parsing
{
	char		*config[6];
	char		*raw_config;
	char		*raw_map;
}	t_parsing;


typedef struct s_data 
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
}	t_data;

typedef struct s_map
{
	char		**map;
	int			h;
	int			w;
}	t_map;

typedef struct s_player
{
	float		x;
	float		y;
	float		view;
} t_player;

// GLOBAL

void	*ft_malloc(size_t size);
void	ft_free(void *ptr, int flag);
void	error(char *str);
void	logo(void);

// LIB

char	*buff_dup(int c, int dup);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		or(int main, int b, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*buff_ch(int c);
char	*buff_str(char *str);

// FUNCTIONS

void 		print_config(void);
void 		print_map(void);
void 		map_algo(int x, int y);
int			is_open(int io);
int	    	is_cub_file(char *path);
int			is_xpm_file(char *path);
int			parse_input(char *path);
int			word_search(char *str, char *need);
int			read_map(char *path);
int 		config_raw(char *raw);
int 		map_raw(char *raw);
char 		*rm_spaces(char *str);
int			is_overflow(char *str, int i);
int 		is_valid_file(char *path);
int			is_empty(char *str);
int			is_space(int c);
t_data		*data_g(void);
t_map		*map_g(void);
t_parsing	*parsing_g(void);

#endif