/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:03 by khalid            #+#    #+#             */
/*   Updated: 2024/08/16 14:57:21 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void print_error(int i)
{
    if (i == 0)
        printf("Error in type ID");
    else if(i == 1)
        printf("Error in texteur");
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

// int check_texteur(t_map *map)
// {
    
// }

int check_type_id(t_map *map)
{
    char **test;
    int i;
    int count;
  
    i = 0;
    count = 0;
    while(map->map_line[i] && count >= 4)
    {
        test = ft_split(map->map_line[i], ' ');
        if (ft_strlen(test[0]) <= 2)
        {
            if(test[0][0] == 'N' && test[0][1] == 'O' && count++) 
                map->no = ft_strdup(test[1]);
            else if (test[0][0] == 'S' && test[0][1] == 'O' && count++)
                map->so = ft_strdup(test[1]);
            else if (test[0][0] == 'W' && test[0][1] == 'E' && count++)
                map->we = ft_strdup(test[1]);
            else if (test[0][0] == 'E' && test[0][1] == 'A' && count++)
                map->ea = ft_strdup(test[1]);
            // else if (test[0][0] == 'F')
            //     map->f = ft_strdup(test[1]);
            // else if (test[0][0] == 'C')
            //     map->c = ft_strdup(test[1]);
            // else
            //     return 0;
        }
        else
            return 0;
        free(test);
        i++;
    }
    if(count != 4)
        return 0;
    return (1);
}

void parc_map(t_map *map)
{
    int i;
    i = 0;
    
    if(!check_type_id(map))
        print_error(0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (printf("argument not valid\n"), 1);
    t_map *map;
    map = read_map(av[2]);
    //parc_map(map);
    return (0);
}