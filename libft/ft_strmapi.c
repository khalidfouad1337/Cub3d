/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:52:48 by kfouad            #+#    #+#             */
/*   Updated: 2022/10/09 21:23:58 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	char	*str;
	int		i;

	s1 = (char *)s;
	i = 0;
	if (!s1)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = f(i, s1[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
