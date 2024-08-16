/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:49:24 by kfouad            #+#    #+#             */
/*   Updated: 2022/10/06 22:40:37 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (!str2[i])
		return (&str1[i]);
	while (str1[j + i] && str2[i] && (j + i) < len)
	{
		if (str1[i + j] != str2[i])
		{
			i = 0;
			j++;
		}
		else
			if (!str2[++i])
				return (&str1[j]);
	}
	return (NULL);
}
