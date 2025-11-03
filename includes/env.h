/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:37:06 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/03 12:35:09 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
#define ENV_H

# define WIN_W 1080
# define WIN_H 720
# define GET -1
# define ERR 1
# define OK 0
# define BUFFER_SIZE 1024

# define TILE_SIZE 32
# define ADD  1
# define FREE  -1

#define PI 3.14159265359
#define FOV (60 * (PI / 180))
#define TILE 32
#define NUM_RAYS WIN_W 
#define INCREMENT FOV / NUM_RAYS
#define COLLISION_PADDING 5.0

# define MOVE_SPEED 3
# define ROT_SPEED 0.05

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53


# endif