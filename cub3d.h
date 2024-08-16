/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:08:08 by khalid            #+#    #+#             */
/*   Updated: 2024/08/14 16:12:28 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef CUB3D_H
#define CUB3D_H


#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
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
    
} t_map;

t_map *read_map(char *fille);
int check_type_id(t_map *map);
void parc_map(t_map *map);

#endif