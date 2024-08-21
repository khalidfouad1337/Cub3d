/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:28:03 by kfouad            #+#    #+#             */
/*   Updated: 2024/08/21 18:28:33 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ends_with_png(const char *str)
{
    int len = ft_strlen(str);
    if (len < 4)
        return 0;
    if (ft_strncmp(str + len - 4, ".png", 4) == 0)
        return 1;
    return 0;
}

// Function to check if a string is a valid color in the format "r,g,b"
int is_valid_color(const char *color_str)
{
    int r, g, b;
    char **str = ft_split(color_str, ',');
    int i;

    i = 0;
    while (str[i])
        i++;
    if (i != 3)
        return 0;
    r = ft_atoi(str[0]);
    if (r < 0 || r > 255)
        return 0;
    color_str++;
    g = ft_atoi(str[1]);
    if (g < 0 || g > 255)
        return 0;
    color_str++;
    b = ft_atoi(str[2]);
    if (b < 0 || b > 255)
        return 0;
    return 1;
}

// Function to check if the textures and colors are valid
int check_textures_and_colors(t_map *map)
{
    if (!ends_with_png(map->no) || !ends_with_png(map->so) ||
     !ends_with_png(map->we) || !ends_with_png(map->ea))
    {
        print_error(1);
        return 0;
    }
    if (!is_valid_color(map->f) || !is_valid_color(map->c))
    {
        print_error(2);
        return 0;
    }
    return 1;
}