#include "../includes/cub3d.h" // Or your header

// This function is called when a key is PRESSED
int	key_press_handle(int key, t_window *win)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_W)
		win->keys.w = 1;
	if (key == KEY_S)
		win->keys.s = 1;
	if (key == KEY_A)
		win->keys.a = 1;
	if (key == KEY_D)
		win->keys.d = 1;
	if (key == KEY_LEFT)
		win->keys.left = 1;
	if (key == KEY_RIGHT)
		win->keys.right = 1;
	return (0);
}

// This function is called when a key is RELEASED
int	key_release_handle(int key, t_window *win)
{
	if (key == KEY_W)
		win->keys.w = 0;
	if (key == KEY_S)
		win->keys.s = 0;
	if (key == KEY_A)
		win->keys.a = 0;
	if (key == KEY_D)
		win->keys.d = 0;
	if (key == KEY_LEFT)
		win->keys.left = 0;
	if (key == KEY_RIGHT)
		win->keys.right = 0;
	return (0);
}

// --- (Your move_player and rotate_player logic) ---
// (Make sure you have these functions)

 void	rotate_player(t_window *win, double rot_speed)
{
	win->player.angle += rot_speed;
	angle_update(&win->player.angle);
}

 void	move_player(t_window *win, double move_speed, double angle_offset)
{
	double	move_angle;
	double	new_x;
	double	new_y;
	double	move_x;
	double	move_y;

	move_angle = win->player.angle + angle_offset;
	angle_update(&move_angle);
    // Note: Your MOVE_SPEED is 15, which is high.
    // Make sure your player coordinates are in PIXELS, not grid units.
	move_x = cos(move_angle) * move_speed;
	move_y = sin(move_angle) * move_speed;
	
	new_x = win->player.x + move_x;
	if (!has_wall(new_x, win->player.y))
		win->player.x = new_x;
	
	new_y = win->player.y + move_y;
	if (!has_wall(win->player.x, new_y))
		win->player.y = new_y;
}

// --- This new function runs every frame ---
void	update_player(t_window *win)
{
	if (win->keys.w)
		move_player(win, MOVE_SPEED, 0); // Forward
	if (win->keys.s)
		move_player(win, -MOVE_SPEED, 0); // Backward
	if (win->keys.a)
		move_player(win, MOVE_SPEED, -M_PI / 2); // Strafe Left
	if (win->keys.d)
		move_player(win, MOVE_SPEED, M_PI / 2); // Strafe Right
	if (win->keys.left)
		rotate_player(win, -ROT_SPEED);
	if (win->keys.right)
		rotate_player(win, ROT_SPEED);
}