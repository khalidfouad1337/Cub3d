/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:32:44 by kfouad            #+#    #+#             */
/*   Updated: 2022/10/14 19:08:07 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	lendst;

	i = 0;
	n = dstsize;
	lendst = ft_strlen(dst);
	if (lendst >= n)
		return (ft_strlen(src) + n);
	while (n != 0 && src[i] != '\0' && (lendst + i < n - 1))
	{
		dst[i + lendst] = src[i];
		i++;
	}
	if (n != 0)
		dst[i + lendst] = '\0';
	return (ft_strlen(src) + lendst);
}
