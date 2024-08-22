/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:08:08 by khalid            #+#    #+#             */
/*   Updated: 2024/08/22 18:13:18 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef CUB3D_H
#define CUB3D_H


#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
# include <mlx.h>
#include "libft/libft.h"

#ifndef BUFFERSIZE
#define BUFFERSIZE  1024
#endif

typedef struct s_map
{
    char		*no;
	char		*so;
	char		*we;
	char		*ea;
    char		*f;
	char		*c;
    char        buff_map[BUFFERSIZE];
    char        **map_line;
    int         fd_map;
     int        map_height; 
    
} t_map;

int check_textures_and_colors(t_map *map);
t_map *read_map(char *fille);
int check_type_id(t_map *map, int i);
void parc_map(t_map *map);
int is_map_enclosed_by_walls(t_map *map);
void print_error(int i);

#endif