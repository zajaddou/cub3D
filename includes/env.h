/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:37:06 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/30 15:52:58 by zajaddou         ###   ########.fr       */
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


// Mini Map

#define MINIMAP_SIZE  200
#define MINIMAP_TILE  10

#define COLOR_PLAYER  0xFF0000
#define COLOR_WALL    0x333333
#define COLOR_FLOOR   0xDDDDDD

# endif