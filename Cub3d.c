/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:03 by khalid            #+#    #+#             */
/*   Updated: 2024/08/21 19:01:57 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_element(t_map	*map)
{
	int i = 5;
    int j = 0;
    int p = 0;
	while (map->map_line[++i])
	{
		j = -1;
		while (map->map_line[i][++j])
		{
			if (map->map_line[i][j] == 'E' || map->map_line[i][j] == 'W' ||
             map->map_line[i][j] == 'N' || map->map_line[i][j] == 'S')
				p++;
			else if (map->map_line[i][j] != '1' &&
             map->map_line[i][j] != '0' && map->map_line[i][j] != ' ')
				return (0);
		}
	}
	if (p != 1)
		return (0);
	return (1);
}

int	get_map_index(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		while (map[i] && (map[i] == '\n' | map[i] == '\t' || map[i] == ' '))
			i++;
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W'
			|| map[i] == 'E' || map[i] == 'F' || map[i] == 'C')
		{
			while (map[i] && map[i] != '\n')
				i++;
		}
		else
		{
			while (map[i] && map[i] != '1')
				i++;
			if (map[i] == '1')
				return (i);
		}
		if (map[i])
			i++;
	}
	return (0);
}

void	check_map_newlines(char *map)
{
	int	i;

	i = get_map_index(map);
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i += 1;
			while (map[i] && map[i] == ' ')
				i++;
			if (map[i] == '\n')
				print_error(5);
		}
		i++;
	}
}

int file_exists(t_map *map) {
    int fd = open(map->ea, O_RDONLY);
    if (fd != -1) {
        close(fd);
        return 1; // File exists
    } else {
        return 0; // File does not exist
    }
}

void parc_map(t_map *map)
{
    int i = 0;
    if (!check_type_id(map, i))
        print_error(0);
    else
    {
        file_exists(map);
        if (!check_element(map))
            print_error(4);
        check_map_newlines(map->buff_map);
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