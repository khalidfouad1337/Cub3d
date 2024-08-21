/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:26:16 by kfouad            #+#    #+#             */
/*   Updated: 2024/08/21 18:26:55 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map *read_map(char *fille)
{
    int fd;
    char buff[BUFFERSIZE];
    int readline;
    t_map *result;

    readline = '\0';
    fd = open(fille, O_RDONLY);
    if (fd < 3)
        return NULL;
    readline = read(fd, buff, BUFFERSIZE);
    if (!readline)
        return (NULL);
    readline[buff] = '\0';
    result = (t_map *)malloc(sizeof(t_map));
    result->fd_map = fd;
    ft_strlcpy(result->buff_map, buff, ft_strlen(buff));
    result->map_line = ft_split(buff, '\n');
    return (result);
}
