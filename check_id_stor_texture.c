/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id_stor_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:20:34 by kfouad            #+#    #+#             */
/*   Updated: 2024/08/21 18:24:53 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_split(char **split)
{
    int j;
    
    j = 0;
    while (split[j] != NULL)
    {
        free(split[j]);
        j++;
    }
    free(split);
}

int parse_and_store_texture(char **test, t_map *map)
{
    if (ft_strlen(test[0]) <= 2 && ft_isalpha(test[0][0]))
    {
        if (test[0][0] == 'N' && test[0][1] == 'O')
            map->no = ft_strdup(test[1]);
        else if (test[0][0] == 'S' && test[0][1] == 'O')
            map->so = ft_strdup(test[1]);
        else if (test[0][0] == 'W' && test[0][1] == 'E')
            map->we = ft_strdup(test[1]);
        else if (test[0][0] == 'E' && test[0][1] == 'A')
            map->ea = ft_strdup(test[1]);
        else if (test[0][0] == 'F')
            map->f = ft_strdup(test[1]);
        else if (test[0][0] == 'C')
            map->c = ft_strdup(test[1]);
        else
            return 0;
    }
    else
        return 0;
    return 1;
}

int check_type_id(t_map *map, int i)
{
    char **test;

    while (map->map_line[i] && ft_isalpha(map->map_line[i][0]))
    {
        test = ft_split(map->map_line[i], ' ');
        if (!parse_and_store_texture(test, map))
        {
            free_split(test);
            return 0;
        }
        free_split(test);
        i++;
    }
    if (i != 6)
        return 0;
    return 1;
}