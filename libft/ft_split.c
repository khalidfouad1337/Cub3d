/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:36:13 by kfouad            #+#    #+#             */
/*   Updated: 2022/10/12 20:29:59 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	chhal_mn_klma(char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			j++;
		i++;
	}
	return (j + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	result = malloc((chhal_mn_klma((char *)s, c) + 1) * sizeof(char *));
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		if (j != i)
			result[k++] = ft_substr(s, i, j - i);
		i = j;
	}
	result[k] = (char *) '\0';
	return (result);
}
