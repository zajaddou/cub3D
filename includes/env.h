/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:37:06 by zajaddou          #+#    #+#             */
/*   Updated: 2025/11/01 14:54:16 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
#define ENV_H

# define WIN_W 800
# define WIN_H 600

# define TILE_SIZE 32

#define PI 3.14159265359
#define FOV (60 * (PI / 180))
#define TILE 32
#define NUM_RAYS WIN_W 
#define INCREMENT FOV / NUM_RAYS

#define COLOR_PLAYER  0xFF0000
#define COLOR_WALL    0x333333
#define COLOR_FLOOR   0xDDDDDD
#define COLOR_DOOR_C  0x664400
#define COLOR_DOOR_O  0xAAAAAA

# define GET -1
# define ERR 1
# define OK 0


# endif