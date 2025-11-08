/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:40:42 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 16:45:46 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_parsing
{
	char		*config[6];
	char		*raw_config;
	char		*raw_map;
}	t_parsing;

typedef struct s_map
{
	int		c_color;
	int		f_color;
	char	**map;
	int		h;
	int		w;
}	t_map;

typedef struct s_animation
{
	void *images[10];
} t_animation;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	distance;
	int		hit_vertical;
	double	wall_hit_x;
	double	wall_hit_y;
	int		facing_down;
	int		facing_up;
	int		facing_left;
	int		facing_right;
	int		draw_start;
	int		draw_end;
	double	wall_height;
}	t_ray;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_tex
{
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		texture_id;
	int		color;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	double	wall_hit_x;
}	t_tex;

typedef struct s_window
{
	t_tex		textures[4];
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;	
	t_player	player;
	t_ray		rays[NUM_RAYS];	
	double		hit_hor_x;
	double		hor_distace;
	double		hit_ver_y;
	double		ver_distace;
	double		distance;
	int			iswall;
	double		step_x;
	double		step_y;
	double		ray_x;
	double		ray_y;
	int			is_hor_wall;
	int			is_ver_wall;
	t_keys		keys;
}	t_window;
