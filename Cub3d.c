/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:03 by khalid            #+#    #+#             */
/*   Updated: 2024/08/18 21:14:57 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void print_error(int i)
{
    if (i == 0)
        printf("Error in type ID");
    else if(i == 1)
        printf("Error: NO texture is not a valid .png file.\n");
    else if(i == 2)
        printf("Error: Floor color is not valid. It should be in the format 'r,g,b' with values between 0 and 255.\n");
    else if (i == 3)
        printf("Error: Map is not properly enclosed by walls.\n");
}

t_map *read_map(char *fille)
{
    int fd;
    char buff[BUFFERSIZE];
    int     readline;
    t_map   *result;

    readline = '\0';
    fd = open(fille, O_RDONLY);
    if(fd < 3)
        return NULL;
    readline = read(fd, buff, BUFFERSIZE);
    if(!readline)
        return (NULL);
    readline[buff] = '\0';
    result = (t_map *)malloc(sizeof (t_map));
    result->fd_map = fd;
    ft_strlcpy(result->buff_map, buff, ft_strlen(buff));
    result->map_line = ft_split(buff, '\n');
    return (result);
}

// Function to check if a string ends with ".png"
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
    if (r < 0 || r > 255 )
        return 0;
    color_str++;
    g = ft_atoi(str[1]);
    if (g < 0 || g > 255)
        return 0;
    color_str++;
    b = ft_atoi(str[2]);
    if (b < 0 || b > 255 )
        return 0;
    return 1;
}

// Function to check if the textures and colors are valid
int check_textures_and_colors(t_map *map)
{
    if (!ends_with_png(map->no) || !ends_with_png(map->so) || !ends_with_png(map->we) || !ends_with_png(map->ea))
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

// Function to check if the map is enclosed by walls
int is_map_enclosed_by_walls(t_map *map)
{
    int i = 6;
    int j = 0;
    int len;

    // Check the first and last rows
    len = ft_strlen(map->map_line[6]);
    while (j < len)
    {
        if (map->map_line[6][j] != '1' || map->map_line[map->map_height - 1][j] != '1')
        {
            if(map->map_line[6][j] == ' ' || map->map_line[len - 1][j] == ' ')
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

    // Check the first and last columns of each row
    i = 6;
    while (i < map->map_height)
    {
        len = ft_strlen(map->map_line[6]);
        if (map->map_line[i][0] != '1' || map->map_line[i][len - 1] != '1')
        {
            if(map->map_line[i][0] == ' ' || map->map_line[i][len - 1] == ' ')
            {
                i++;
                continue;
            }
            else
            {
                print_error(3);
                return 0;
            }
        }
        i++;
    }

    // Check inner map for open spaces
    i = 7;
    while (i < map->map_height - 1)
    {
        j = 1;
        len = ft_strlen(map->map_line[7]);
        while (j < len - 1)
        {
            if (map->map_line[i][j] == '0' || map->map_line[i][j] == 'S' || map->map_line[i][j] == 'N' || map->map_line[i][j] == 'E' || map->map_line[i][j] == 'W')
            {
                if (map->map_line[i - 1][j] == ' ' || map->map_line[i + 1][j] == ' ' || map->map_line[i][j - 1] == ' ' || map->map_line[i][j + 1] == ' ')
                {
                    print_error(3);
                    return 0;
                }
            }
            j++;
        }
        i++;
    }

    return 1;
}

int check_type_id(t_map *map, int i)
{
    char **test;
    int j;
  
    j = 0;
    while(map->map_line[i] && ft_isalpha(map->map_line[i][0]))
    {
        test = ft_split(map->map_line[i], ' ');
        if (ft_strlen(test[0]) <= 2 && ft_isalpha(test[0][0]))
        {
            if(test[0][0] == 'N' && test[0][1] == 'O') 
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
        for (j = 0; test[j] != NULL; j++)
            free(test[j]);
        free(test);
        i++;
    }
    if(i != 6)
        return 0;
    
    return (1);
}


void parc_map(t_map *map)
{
    int i = 0;
    if(!check_type_id(map, i))
        print_error(0);
    else 
    {
        check_textures_and_colors(map);
        map->map_height = 0;
        while (map->map_line[map->map_height])
            map->map_height++;
        is_map_enclosed_by_walls(map);
    }
    
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (printf("argument not valid\n"), 1);
    t_map *map;
    map = read_map(av[1]);
    if (map == NULL)
        return (printf("Failed to load map.\n"), 1);
    parc_map(map);   
    return (0);
}