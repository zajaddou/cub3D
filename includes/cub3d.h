/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:48:11 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/03 12:38:16 by mgarouj          ###   ########.fr       */
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
# include <math.h>
# include <limits.h>
# include <math.h>




enum e_dir
{
	NORTH = 0,
	SOUTH,
	EAST,
	WEST
};

typedef struct parsing
{
	char		*config[6];
	char		*raw_config;
	char		*raw_map;
}	t_parsing;

typedef struct s_map
{
	int 		c_color;
	int 		f_color;
	char		**map;
	int			h;
	int			w;
}	t_map;

typedef struct s_player
{
    double  x; // Changed from int
    double  y; // Changed from int
    double  angle;
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
void 		map_algo(int x, int y, t_map *map);
int			is_open(int io);
int	    	is_cub_file(char *path);
int			is_xpm_file(char *path);
int			parse_input(char *path);
int			word_search(char *str, char *need);
int			read_cub(char *path);
int 		config_raw(char *raw);
int 		map_raw(char *raw);
char 		*rm_spaces(char *str);
int			is_overflow(char *str, int i);
int 		is_valid_file(char *path);
int			is_empty(char *str);
int			is_space(int c);

// GLOBAL 
t_map		*map_g(void);
t_parsing	*parsing_g(void);
t_player 	*player_g(void);

// RAYCASTING_____________________________________________________________________________________________---

void init_window();
int render_frame(void *param);



typedef struct s_ray
{
	double	ray_angle;
	double	distance;
	int		hit_vertical;
	double	wall_hit_x;
	double	wall_hit_y;


	int facing_down;
	int facing_up;
	int facing_left;
	int facing_right;
	

	int     draw_start;
    int     draw_end;
	double  wall_height;
}	t_ray;

typedef struct s_keys
    {
        int w;
        int a;
        int s;
        int d;
        int left;
        int right;
    } t_keys;



typedef struct s_tex
{
	void *img;


	int width;
	int height;


	char *addr;
	int bits_per_pixel;
	int line_lenght;
	int endian;







	// for function draw_wall_strip()
	int         texture_id;
	int         color;
    double      step;
    double      tex_pos;
    int         tex_x;
    int         tex_y;
    double      wall_hit_x;
}t_tex;

typedef struct s_window
{

	// tex
	t_tex tex_data[4];
	
	void *mlx;
	void *win;
	void *img;

	char *addr;
	int bpp;
	int line_len;
	int endian;



	
	t_player player;
	t_ray rays[NUM_RAYS];


	
	double hit_hor_x;
	double hor_distace;
	double hit_ver_y;
	double ver_distace;
	double distance;

	int iswall;

	
	double step_x;
	double step_y;

	
	double ray_x;
	double ray_y;


	int is_hor_wall;
	int is_ver_wall;

	t_keys keys;

	

}t_window;


double	calc_distance(double x1, double y1, double x2, double y2);
int has_wall(double x, double y);
void angle_update(double* ray_angle);

int	key_release_handle(int key, t_window *win);
void	move_player(t_window *win, double move_speed, double angle_offset);
void	rotate_player(t_window *win, double rot_speed);
void	update_player(t_window *win);
t_window *window_g(void);
void render_background(t_window *win);
void put_pixel(t_window *win, int x, int y, int color);

int key_press_handle(int key, t_window *win);
void is_hor_ray(t_window *win, double ray_angle, int id);
void is_ver_ray(t_window *win, double ray_angle, int id);



void    draw_textures(t_window *win, int i, double distance_proj_plane);
void	rotate_player(t_window *win, double rot_speed);

#endif