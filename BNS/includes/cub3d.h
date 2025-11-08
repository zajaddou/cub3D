/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:48:11 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 20:10:56 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "env.h"
# include "structs.h"

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <math.h>

// STATIC 

t_parsing	*pars_g(void);
t_player	*player_g(void);
t_window	*window_g(void);
t_map		*map_g(void);

// GLOBAL

void		*ft_malloc(size_t size);
void		ft_free(void *ptr, int flag);
void		error(char *str);

// LIB

int			ft_isdigit(int c);
char	    *ft_itoa(int n);
int			ft_isalpha(int c);
char		*buff_dup(int c, int dup);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strncpy(char *dest, const char *src, size_t n);
size_t	    ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
char		*buff_ch(int c);
char		*buff_str(char *str);
int			is_empty(char *str);
int			is_space(int c);
int			is_overflow(char *str, int i);

// PARSING

void		parsing(char *path);
void		free_parsing(void);
void		format_map(void);
void		destroy_textures(void);
void		load_textures(void);
void		check_ascii(char *str);
void		is_rgb(char *rgb);
int			rgb_to_int(char *str);
void		map_algo(int x, int y, t_map *map);
void		is_cub(char *path);
void		is_xpm(char *path);
int			word_search(char **conf, char *need);
void		read_cub(char *path);
void		config_raw(void);
void		map_raw(void);
char		*rm_spaces(char *str);
void		check_path(char *path);

// RAYCASTING

void		init_window(void);
void		init_data(void);
void		init_textures(void);
int			close_window(t_window *game);
int			render_frame(void *param);
double		calc_distance(double x1, double y1, double x2, double y2);
int			has_wall(double x, double y);
void		angle_update(double *ray_angle);
int			key_release_handle(int key, t_window *win);
void		move_player(t_window *win, double move_speed, double angle_offset);
void		rotate_player(t_window *win, double rot_speed);
void		update_player(t_window *win);
void		render_background(t_window *win);
void		put_pixel(t_window *win, int x, int y, int color);
int			key_press_handle(int key, t_window *win);
void		is_hor_ray(t_window *win, double ray_angle, int id);
void		is_ver_ray(t_window *win, double ray_angle, int id);
void		draw_textures(t_window *win, int i, double distance_proj_plane);
void		rotate_player(t_window *win, double rot_speed);

// BONUS

void	    door_handle(void);
void        init_animation(void);
void        animation(t_window *win);
void		draw_minimap(void *param);
int         mouse_handle(int x, int y, t_window *win);

#endif