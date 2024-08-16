/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:57:17 by kfouad            #+#    #+#             */
/*   Updated: 2022/10/06 19:56:05 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char	*s2, size_t	n)
{
	unsigned char	*str0;
	unsigned char	*str1;
	size_t			i;

	str0 = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str0[i] != '\0' && str0[i] == str1[i] && i < n - 1)
		i++;
	return (str0[i] - str1[i]);
}
