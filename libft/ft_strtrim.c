/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:07:27 by kfouad            #+#    #+#             */
/*   Updated: 2022/10/08 19:41:01 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	index_start(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((check(str2, str1[i])) == 1)
		i++;
	return (i);
}

int	index_end(char *str1, char *str2)
{
	int	i;

	i = ft_strlen(str1);
	while (i > index_start(str1, str2) && (check(str2, str1[i - 1])) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	*set1;
	int		start;
	int		end;

	s = (char *)s1;
	set1 = (char *)set;
	start = index_start(s, set1);
	end = index_end(s, set1);
	if (!s || !set1)
		return (NULL);
	return (ft_substr(s, start, (end - start)));
}
