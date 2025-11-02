#include "../includes/cub3d.h"


int	get_texture_id(t_ray *ray)
{
	if (ray->hit_vertical)
	{
		if (ray->facing_right)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray->facing_down)
			return (SOUTH);
		else
			return (NORTH);
	}
}

// void	draw_wall_strip(t_window *win, int x, int draw_start, int draw_end, t_ray *ray)
// {
// 	int			y;
// 	int			texture_id;
// 	t_tex		*tex;
// 	int			color;
// 	double		step;
// 	double		tex_pos;
// 	int			tex_x;
// 	int			tex_y;
// 	double		wall_hit_x;

// 	texture_id = get_texture_id(ray);
// 	// tex = &win->tex_data[texture_id];

// 	if (ray->hit_vertical)
// 		wall_hit_x = ray->wall_hit_y;
// 	else
// 		wall_hit_x = ray->wall_hit_x;
// 	// wall_hit_x /= TILE;
// 	// wall_hit_x -= floor(wall_hit_x);
// 	tex_x = (int)(wall_hit_x * tex->width);
// 	// if ((ray->hit_vertical && ray->facing_left)
// 	// 	|| (!ray->hit_vertical && ray->facing_up))
// 	// 	tex_x = tex->width - tex_x - 1;

// 	step = 1.0 * tex->height / (draw_end - draw_start);
// 	tex_pos = 0;
// 	y = draw_start;
// 	while (y < draw_end)
// 	{
// 		tex_y = (int)tex_pos & (tex->height - 1);
// 		tex_pos += step;
// 		// color = *(int *)(tex->addr + (tex_y * tex->line_lenght + tex_x * (tex->bits_per_pixel / 8)));
// 		put_pixel(win, x, y, color);
// 		y++;
// 	}
// }

// void	draw_textures(t_window *win)
// {
// 	int		x;
// 	double	perp_dist;
// 	double	distance_proj_plane;
// 	double	wall_height;
// 	int		draw_start;
// 	int		draw_end;
// 	t_ray	*ray;

// 	x = 0;
// 	distance_proj_plane = (((WIN_W) / (2 * tan(FOV / 2))));
// 	while (x < NUM_RAYS)
// 	{
// 		ray = &win->rays[x];
// 		perp_dist = ray->distance * cos(ray->ray_angle - win->player.angle);
// 		if (perp_dist == 0)
// 			perp_dist = 1e-30;
// 		wall_height = (TILE / perp_dist) * distance_proj_plane;
// 		draw_start = (WIN_H / 2) - (wall_height / 2);
// 		if (draw_start < 0)
// 			draw_start = 0;
// 		draw_end = (WIN_H / 2) + (wall_height / 2);
// 		if (draw_end > WIN_H)
// 			draw_end = WIN_H - 1;
// 		draw_wall_strip(win, x, draw_start, draw_end, ray);
// 		x++;
// 	}
// }








// Add 'double wall_height' as a new parameter
void    draw_wall_strip(t_window *win, int x, int draw_start, int draw_end, double wall_height, t_ray *ray)
{
    int         y;
    int         texture_id;
    t_tex       *tex;
    int         color;
    double      step;
    double      tex_pos;
    int         tex_x;
    int         tex_y;
    double      wall_hit_x;

    texture_id = get_texture_id(ray);
    // Use the struct from your header
    tex = &win->tex_data[texture_id];

    // --- Start of uncommented tex_x logic ---
    if (ray->hit_vertical)
        wall_hit_x = ray->wall_hit_y;
    else
        wall_hit_x = ray->wall_hit_x;

    // Get the 0.0 to 1.0 fractional part of where the ray hit
    wall_hit_x /= TILE;
    wall_hit_x -= floor(wall_hit_x);

    // Convert the fractional part to an x-coordinate on the texture
    tex_x = (int)(wall_hit_x * tex->width);

    // --- Start of uncommented flip logic ---
    // Flip the texture if it's facing WEST or NORTH
    if ((ray->hit_vertical && ray->facing_left)
        || (!ray->hit_vertical && ray->facing_up))
        tex_x = tex->width - tex_x - 1;

    // --- Start of FIXED tex_y logic ---
    // 1. Calculate 'step' using the full, un-clamped wall_height
    step = 1.0 * tex->height / wall_height;
    
    // 2. Calculate the correct starting 'tex_pos' (texture y-position)
    tex_pos = (draw_start - WIN_H / 2 + wall_height / 2) * step;

    y = draw_start;
    while (y < draw_end)
    {
        // Convert the texture position to an integer pixel
        tex_y = (int)tex_pos & (tex->height - 1); // Fast modulo
        tex_pos += step;

        // --- Start of uncommented color logic ---
        // Get the pixel color from the texture's data address
        // Note: Using your header's "line_lenght" and "bits_per_pixel"
        color = *(int *)(tex->addr + (tex_y * tex->line_lenght + tex_x * (tex->bits_per_pixel / 8)));
        
        put_pixel(win, x, y, color);
        y++;
    }
}



void    draw_textures(t_window *win)
{
    int     x;
    double  perp_dist;
    double  distance_proj_plane;
    double  wall_height; // This is the key variable
    int     draw_start;
    int     draw_end;
    t_ray   *ray;

    x = 0;
    distance_proj_plane = (((double)WIN_W) / (2.0 * tan(FOV / 2.0)));
    while (x < NUM_RAYS)
    {
        ray = &win->rays[x];
        perp_dist = ray->distance * cos(ray->ray_angle - win->player.angle);
        if (perp_dist < 1e-30) // Use < 1e-30 for safety
            perp_dist = 1e-30;
            
        wall_height = (TILE / perp_dist) * distance_proj_plane;
        
        draw_start = (WIN_H / 2) - (wall_height / 2);
        if (draw_start < 0)
            draw_start = 0;
            
        draw_end = (WIN_H / 2) + (wall_height / 2);
        if (draw_end >= WIN_H) // Use >= WIN_H
            draw_end = WIN_H - 1;

        // --- THIS IS THE FIX ---
        // Pass 'wall_height' as the new parameter
        draw_wall_strip(win, x, draw_start, draw_end, wall_height, ray);
        x++;
    }
}