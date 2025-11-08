/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:37:06 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/08 18:55:58 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define WIN_W 1080
# define WIN_H 720
# define GET -1
# define ERR 1
# define OK 0
# define FREE 1

# define PI 3.14159265359
# define FOV 1.047197551196666687
# define TILE 32
# define NUM_RAYS WIN_W 
# define COLLISION_PADDING 5.0

# define MOVE_SPEED 5
# define ROT_SPEED 0.05

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

# define RESET	"\e[0m"
# define BOLD	"\e[1m"
# define RED	"\e[31m"
# define CYAN	"\e[36m"

# define COLOR_PLAYER  0xFF0000
# define COLOR_WALL    0x333333
# define COLOR_FLOOR   0xDDDDDD
# define COLOR_DOOR_C  0x664400
# define COLOR_DOOR_O  0xAAAAAA

#endif
