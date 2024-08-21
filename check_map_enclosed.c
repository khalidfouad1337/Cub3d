/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_enclosed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:22:49 by kfouad            #+#    #+#             */
/*   Updated: 2024/08/21 18:24:46 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_row_enclosure(char *row)
{
    int j;
    int len;
    
    j = 0;
    len = ft_strlen(row);
    while (j < len - 1)
    {
        if (row[j] != '1')
        {
            if (row[j] == ' ')
            {
                j++;
                continue;
            } 
            else
            {
                print_error(3);
                return 0;
            }
        }
        j++;
    }
    return 1;
}


int check_column_enclosure(t_map *map, int start_row, int end_row)
{
    int i;
    
    i = start_row;
    while (i < end_row) 
    {
        int len = ft_strlen(map->map_line[i]);
        if (map->map_line[i][0] != '1' || map->map_line[i][len - 1] != '1')
        {
            if (map->map_line[i][0] == ' ' || map->map_line[i][len - 1] == ' ')
            {
                i++;
                continue;
            } else 
            {
                print_error(3);
                return 0;
            }
        }
        i++;
    }
    return 1;
}

int is_enclosed(t_map *map, int i, int j, int len) 
{
    if ((i > 6 && ((int)ft_strlen(map->map_line[i - 1]) <= j || 
        map->map_line[i - 1][j] == ' ')) || 
        (i < (len - 1) && ((int)ft_strlen(map->map_line[i + 1]) <= j || 
        map->map_line[i + 1][j] == ' ')) || 
        map->map_line[i][j - 1] == ' ' || 
        map->map_line[i][j + 1] == ' ')
        return 0;
    return 1;
}

int check_line_enclosure(t_map *map, int i, int len) 
{
    int j;
    char c;

    j = 0;
    while (++j < len - 1) 
    {
        c = map->map_line[i][j];
        if (c == '0' || c == 'S' || c == 'N' || c == 'E' || c == 'W') 
        {
            if (!is_enclosed(map, i, j, len))
                return (print_error(3), 0);
        }
    }
    return 1;
}


int check_inner_map_enclosure(t_map *map, int start_row, int end_row) 
{
    int i;
    int len;

    i = start_row - 1;
    while (++i < end_row) 
    {
        len = ft_strlen(map->map_line[i]);
        if (!check_line_enclosure(map, i, len))
            return 0;
    }
    return 1;
}

int is_map_enclosed_by_walls(t_map *map) 
{
    // Check the first and last rows
    if (!check_row_enclosure(map->map_line[6]) ||
        !check_row_enclosure(map->map_line[map->map_height - 1])) 
            return 0;
    // Check the first and last columns of each row
    if (!check_column_enclosure(map, 6, map->map_height)) 
            return 0;
    // Check inner map for open spaces
    if (!check_inner_map_enclosure(map, 7, map->map_height - 1)) 
        return 0;
    return 1;
}