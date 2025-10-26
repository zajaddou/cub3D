/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:37:06 by zajaddou          #+#    #+#             */
/*   Updated: 2025/10/26 13:55:03 by mgarouj          ###   ########.fr       */
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
#define TILE 64
#define NUM_RAYS WIN_W
#define INCREMENT FOV / NUM_RAYS


# endif