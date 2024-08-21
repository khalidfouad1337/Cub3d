/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:25:25 by kfouad            #+#    #+#             */
/*   Updated: 2024/08/21 18:25:51 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_error(int i)
{
    if (i == 0)
        printf("Error in type ID");
    else if (i == 1)
        printf("Error: NO texture is not a valid .png file.\n");
    else if (i == 2)
        printf("Error: Floor color is not valid. It should be in the format 'r,g,b' with values between 0 and 255.\n");
    else if (i == 3)
        printf("Error: Map is not properly enclosed by walls.\n");
    else if (i == 4)
        printf("error elment");
    else if (i == 5)
        printf("Multiple new lines in a map");
}