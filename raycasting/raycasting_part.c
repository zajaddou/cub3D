#include "../includes/cub3d.h"

void ray_cast(void)
{
    t_data *d = data_g();
    t_map *m = map_g();
    t_player *p = 
}

void cast_all_rays(void)
{
    double ray_angle;
    int i = 0;
    t_mlx *mlx = mlx_g();
    double start_angle = mlx->player.view - (FOV / 2);

    while (i < NUM_RAYS)
    {
        
    }
}


void raycasting()
{
    cast_all_rays()

    
}