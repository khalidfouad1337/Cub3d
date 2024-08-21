/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:29:39 by kfouad            #+#    #+#             */
/*   Updated: 2024/08/21 17:30:25 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*s1;
	size_t	i;
	size_t	n;

	s1 = (char *)s;
	i = 0;
	n = len;
	if (start > ft_strlen(s1) || !s1)
		return (ft_calloc(1, 1));
	else if (len > ft_strlen(s1) - start)
		n = ft_strlen(s1) - start;
	p = malloc(n + 1);
	while (s1[i] && i < n)
	{
		p[i] = s1[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}